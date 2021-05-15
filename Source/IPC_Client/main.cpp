#include "stdafx.h"

#define CommPort 3152

int main(int argc, char* argv[])
{
    #pragma region Clean

    WSACleanup();
    WSADATA wsa_data;
    WSAStartup(MAKEWORD(2, 2), &wsa_data);

    #pragma endregion

    SOCKET Socket;
    struct sockaddr_in Server;
    Server.sin_addr.s_addr = INADDR_ANY;
    Server.sin_family = AF_INET;
    Server.sin_port = CommPort;

    if ((Socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        std::cout << "[-] Failed to create socket" << std::endl;
        system("pause");
        return 1;
    }   
    if (connect(Socket, (struct sockaddr*)&Server, sizeof(Server)) < 0) {
        std::cout << "[-] Connection error" << std::endl;
        system("pause");
        return 1;
    }
    std::string Message = "Selam!";
    int ST = send(Socket, Message.c_str(), strlen(Message.c_str()), 0);

    std::cout << "[+]" << std::endl;
    getchar();
    return 0;
}