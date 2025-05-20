#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
int main(){
    // creating clicket socket
    int clientSocket = socket(AF_INET,SOCK_STREAM,0);

    if (clientSocket == -1 ){
        std::cout << "Creating socket error" <<std::endl;
        return 1;
    }

    // defining Server Address

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(2000);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // connecting to server

    int connect_result = connect(clientSocket,(struct sockaddr *)&serverAddress,sizeof(serverAddress));

    if(connect_result == -1){
        std::cout << "Error connecting to server" << std::endl;
        return 1;
    }

    // sending message to server
    const char * message  = "Hello Delia";

    int bytes_sent = send(clientSocket,message,sizeof(message),0) - 1 ;

    while( bytes_sent < sizeof(message)){


        bytes_sent += send(clientSocket,&message[bytes_sent+1],sizeof(message),0);;

}

    close(clientSocket);

    return 0;
    }




