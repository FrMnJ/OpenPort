#include "include/program_options.h"

std::vector<target_ipv4> parse(int argc, char *argv[]) {
    if (argc > 64) {
        throw std::invalid_argument("Demasiados argumentos");
    }
    const std::vector<std::string_view> args(argv + 1, argv + argc);
    if (args.size()%3 != 0) {
        throw std::invalid_argument("Numero de argumentos incorrectos debe darse <ip> <first port> <last port> por cada ip");
    }
    auto targets = std::vector<target_ipv4>(0);
    for (int i = 0; i < args.size(); i+=3) {
        std::string target_ip;
        target_ip = args[i];
        const auto first_port = strtol(args[i + 1].data(), nullptr, 10);
        const auto last_port = strtol(args[i + 2].data(), nullptr, 10);
        target_ipv4 target_ipv4(target_ip, first_port, last_port);
        targets.emplace_back(target_ipv4);
    }
    return targets;
}
