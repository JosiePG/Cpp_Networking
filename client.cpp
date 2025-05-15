#include <sys/socket.h>

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

    int connect = connect(clientAddr,(struck sockaddr *)&serverAddress,sizeof(serverAddress));

    if(connect == -1){
        std::cout << "Error connecting to server" << std::endl;
        return 1;
    }

    // sending message to server
    const char * message = "Hello Josie";

    send(clientSocket,message,size(message),0);

    close(clientSocket);

    return 0;
    }




