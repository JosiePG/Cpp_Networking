#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <string>
#include <cstring>

int main(){

    std::string host_name;

    std::cout << "Enter Website Link : " ;
    std::cin >> host_name;

    const char * host_name_cstring = host_name.c_str();

    int getaddressinfo_status ;

    struct addrinfo hints ;

    struct addrinfo *server_info;

    memset(&hints, 0, sizeof hints);

    hints.ai_family = AF_UNSPEC; // can be ipv4 or ipv6
    hints.ai_socktype = SOCK_STREAM; // tcp stream socket
    hints.ai_flags = AI_CANONNAME;

    getaddressinfo_status = getaddrinfo(host_name_cstring,"http",&hints,&server_info);

    if(getaddressinfo_status!=0){
        std::cout << "Error getting address info" <<std::endl;
        std::cout << gai_strerror(getaddressinfo_status) <<std::endl;
        return 1;
    }

    std::cout << server_info->ai_canonname << std::endl ;

    // creating client socket

    int clientSocket = socket(AF_INET,SOCK_STREAM,0);

    if (clientSocket == -1) {
        std::cout << "Error initalizing client socket" <<std::endl;
        return 1;
    }

    // connecting to server

    int clientConnect = connect(clientSocket,server_info->ai_addr,server_info->ai_addrlen);
    if (clientConnect == -1) {
        std::cout << "Error connecting client socket" <<std::endl;
    }







    return 0;
}
