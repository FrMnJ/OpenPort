#ifndef TARGET_H
#define TARGET_H
#include <stdexcept>
#include <string>
#include <regex>

class target_ipv4 {
    std::string target_ip;
    long first_port;
    long last_port;

    public:
        target_ipv4();
        target_ipv4(std::string &target_ip, long first_port, long last_port);
        std::string get_target_ip() const;
        long get_first_port() const;
        long get_last_port() const;
        static bool match_IPV4(const std::string &target_ip);
};

#endif //TARGET_H
