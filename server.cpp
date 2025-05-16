#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
int main(){
    // creating socket
    int server_socket = socket(AF_INET,SOCK_STREAM,0);

    if (server_socket == -1){
        std::cout << "Creating Socket Error" <<  std::endl;
        return 1;
    }

    // defining address family , port and address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(2000);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // binding socket
    int bind_result = bind(server_socket,(struct sockaddr *)&serverAddress,sizeof(serverAddress));

    if(bind_result==-1){
        std::cout << "Binding Error" << std::endl;
        return 1;
    }

    //listening 

    int listen_result = listen(server_socket,20); // maximum queue of 20 

    if(listen_result==-1){
        std::cout << "Listening Error" << std::endl;
        return 1;
    }

    // creating buffer to store client address

    struct sockaddr_in clientAddr;

    //acepting

    int accept_result = accept(server_socket,nullptr,nullptr);
  

    if (accept_result==-1){
        std::cout << "Error Accepting" <<std::endl;
        return 1;
    }

    // reading out client buffer

    char buffer[1024] = {0}; // intializing char array to null termionator

    int bytes_sent = recv(accept_result,buffer,sizeof(buffer),0) ;

	while(bytes_sent >0){
		bytes_sent = recv(accept_result,buffer,sizeof(buffer),0);
}
    
    std::cout << "Msg from client : " << buffer << std::endl ;
    



    //closign the socket

    close(server_socket);




    return 0;
}






