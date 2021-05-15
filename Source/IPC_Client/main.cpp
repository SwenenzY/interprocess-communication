#include "stdafx.h"

#define CommPort 3131
#define CommServer "127.0.0.1"

int main(int argc, char* argv[])
{
    #pragma region Clean

    WSACleanup();
    WSADATA wsa_data;
    WSAStartup(MAKEWORD(2, 2), &wsa_data);

    #pragma endregion

    SOCKET Socket;
    struct sockaddr_in Server;
    Server.sin_addr.s_addr = inet_addr(CommServer);
    Server.sin_family = AF_INET;
    Server.sin_port = htons(CommPort);

    if ((Socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        std::cout << "[-] Failed to create socket" << std::endl;
        system("pause");
        return 1;
    }   
    if (connect(Socket, (struct sockaddr*)&Server, sizeof(Server)) < 0) {
        std::cout << "[-] Connection error" << std::endl;
        system("pause");
        return 1;
    }
    std::string Message = "Bu bir uzun test...........";

    int Call = send(Socket, Message.c_str(), strlen(Message.c_str()), 0);
    std::cout << "[+] Send : " << Call  << "("<< strlen(Message.c_str()) <<")"<< std::endl;
    if (Call < 0) {
        std::cout << "[-] Send failed" << std::endl;
        system("pause");
        return 1;
    }

    std::cout << "[+]" << std::endl;
    getchar();
    return 0;
}