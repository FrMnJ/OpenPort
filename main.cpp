#include <chrono>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")


void scanPortTCP(const std::string& ip, int port) {
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

// Scans the selected ports sequentially
int main(const int argc, char *argv[]){
    // Check whether we have enough params
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <ip> <primer-puerto> <ultimo-puerto>" << '\n';
        return 1;
    }
    // If so the second parameter is the target IP
    std::string target_ip = argv[1];
    const long first_port = strtol(argv[2], nullptr, 10);
    const long last_port = strtol(argv[3], nullptr, 10);
    // Start win-sock API
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cerr << "WSAStartup failed!\n";
        return 1;
    }
    std::cout << "[-] Escaneando " << target_ip << " del puerto "<< first_port << " hasta el puerto " << last_port << "...\n";
    // Create the threads that scans the ports sequentially
    std::vector<std::thread> threads;
    for (int port = first_port ; port <= last_port; port++) {
        threads.emplace_back(scanPortTCP, target_ip, port);
    }

    for (auto& t : threads) t.join();

    WSACleanup();
    std::cout << "[-] Escaneo a " << target_ip << " completado.\n";
    return 0;
}