#include "include/program_options.h"
#include "include/scan_tcp.h"
#include <chrono>
#include <iostream>
#include <unistd.h>

// Scans the selected ports sequentially
int main(const int argc, char *argv[]){
    // Parse program options
    std::vector<target_ipv4> targets(0);
    try {
        targets = parse(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << "OpenPort: "  << e.what() << '\n';
        std::cerr << "Uso: " << argv[0] << "<ip> <primer puerto> <ultimo puerto>\n";
        return 1;
    }
    if (targets.empty()) {
        std::cerr << "No hay objetivos válidos.\n";
        return 1;
    }

    if (targets.size() == 1) {
        scan_ipv4(targets[0]);
        return 0;
    }

    std::vector<PROCESS_INFORMATION> procesos;
    for (const auto& target : targets) {
        std::string command = std::string(argv[0]) + " " + target.get_target_ip() + " " +
                              std::to_string(target.get_first_port()) + " " +
                              std::to_string(target.get_last_port());

        STARTUPINFO si = { sizeof(si) };
        PROCESS_INFORMATION pi;
        if (CreateProcess(NULL, (LPSTR)command.c_str(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            procesos.push_back(pi);
            std::cout << "Proceso creado para IP: " << target.get_target_ip() << " de " << target.get_first_port() <<
                " hasta " << target.get_last_port() << " (PID: " << pi.dwProcessId << ")\n";
        } else {
            std::cerr << "Error al crear proceso para " << target.get_target_ip() << "\n";
        }
    }

    for (const auto& pi : procesos) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}