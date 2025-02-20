#include "include/scan_tcp.h"

void scan_tcp_port(const std::string& ip, int port) {
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);
    if (connect(sock, reinterpret_cast<sockaddr *>(&addr), sizeof(addr)) == 0) {
        std::cout << "[+] Puerto " << port << " abierto.\n";
    }
    closesocket(sock);
}

int scan_ipv4(const target_ipv4 &target_ipv4) {
    // Start win-sock API
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cerr << "WSAStartup fallo!\n";
        return 1;
    }
    std::cout << "[-] Escaneando " << target_ipv4.get_target_ip() << " del puerto "<< target_ipv4.get_first_port() <<
        " hasta el puerto " << target_ipv4.get_last_port() << "...\n";

    // Create the threads that scans the ports sequentially
    std::vector<std::thread> threads;
    for (int port = target_ipv4.get_first_port() ; port <= target_ipv4.get_last_port(); port++) {
        threads.emplace_back(scan_tcp_port, target_ipv4.get_target_ip(), port);
    }

    for (auto& t : threads) t.join();

    WSACleanup();
    std::cout << "[-] Escaneo a " << target_ipv4.get_target_ip() << " completado.\n";
    return 0;
}