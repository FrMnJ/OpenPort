#ifndef SCAN_TCP_H
#define SCAN_TCP_H
#include "target_ipv4.h"
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#pragma comment(lib, "ws2_32.lib")



void scan_tcp_port(const std::string& ip, int port);
int scan_ipv4(const target_ipv4 &target_ipv4);

#endif //SCAN_TCP_H
