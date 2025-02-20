#include "include/target_ipv4.h"

target_ipv4::target_ipv4() {
    this->target_ip = "";
    this->first_port = 0;
    this->last_port = 0;
}

target_ipv4::target_ipv4(
    std::string &target_ip,
    const long first_port,
    const long last_port
    ) {
    if (!this->match_IPV4(target_ip)) {
      throw std::invalid_argument("Invalid IP address");
    }
    this->target_ip = target_ip;
    if (first_port > last_port || (first_port < 1 || first_port > 65'535)) {
        throw std::invalid_argument("Invalid first port");
    }
    if (last_port < 1 || last_port > 65'535) {
        throw std::invalid_argument("Invalid last port");
    }
    this->first_port = first_port;
    this->last_port = last_port;
}

std::string target_ipv4::get_target_ip() const {
    return this->target_ip;
}

long target_ipv4::get_first_port() const {
    return this->first_port;
}

long target_ipv4::get_last_port() const {
    return this->last_port;
}

bool target_ipv4::match_IPV4(const std::string &target_ip) {
    const std::regex reg (R"(^((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$)");
    return std::regex_match(target_ip, reg);
}
