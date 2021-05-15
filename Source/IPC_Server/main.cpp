#include "stdafx.h"

#define CommPort 3131
struct sockaddr_in Server, Listen;
SOCKET Socket;
char Buffer[512];
int FromLen;
int RecvLen;

int main(int argc, char* argv[])
{
    #pragma region Clean

    WSACleanup();
    WSADATA wsa_data;
    WSAStartup(MAKEWORD(2, 2), &wsa_data);

    #pragma endregion

    if ((Socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        std::cout << "[-] Failed to create socket" << std::endl;
        system("pause");
        return 1;
    }
    // netstat -na | find "3131"
    Server.sin_family = AF_INET;
    Server.sin_addr.s_addr = INADDR_ANY;//inet_addr("127.0.0.1"); // 127.0.0.1 ::1
    Server.sin_port = htons(CommPort);

    if (bind(Socket, (struct sockaddr*)&Server, sizeof(Server)) == SOCKET_ERROR) {
        std::cout << "[-] Failed to bind socket : " << WSAGetLastError() << std::endl;
    }
    /*
    
    Operation not supported.
    The attempted operation is not supported for the type of object referenced. 
    Usually this occurs when a socket descriptor to a socket that cannot support this 
    operation is trying to accept a connection on a datagram socket.

    */
    // ERROR 10045
    if (listen(Socket, 5) < 0) {
        std::cout << "[-] Failed to listen socket : " << WSAGetLastError() << std::endl;
    }

    struct sockaddr_in In;
    socklen_t SockSize = sizeof(In);


    std::cout << "[+] Waiting packet from client. " << std::endl;

    //if (accept(Socket, (struct sockaddr*)&In, &SockSize) < 0) {
    //    std::cout << "[-] Failed to accept socket : " << WSAGetLastError() << std::endl;
    //}

    printf(".");

    while (true) {
        

        memset(Buffer, '\0', 512);

        if ((RecvLen == recvfrom(Socket, Buffer, 512, 0, (struct sockaddr*)&Listen, &FromLen)) == SOCKET_ERROR) {
            std::cout << "[-] Failed to create recvfrom " << WSAGetLastError() << std::endl;
        }

        std::cout << "[!] Recevied packet from " << inet_ntoa(Listen.sin_addr) << ":" << ntohs(Listen.sin_port) << std::endl;
        std::cout << "[!] Recevied buffer " << Buffer << std::endl;
        
    }

    getchar();
    return 0;
}