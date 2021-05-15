#include "stdafx.h"

#define CommPort 3152

int main(int argc, char* argv[])
{
    #pragma region Clean

    WSACleanup();
    WSADATA wsa_data;
    WSAStartup(MAKEWORD(2, 2), &wsa_data);

    #pragma endregion

    struct sockaddr_in Server;
    Server.sin_addr.s_addr = INADDR_ANY;
    Server.sin_family = AF_INET;
    Server.sin_port = CommPort;


    std::cout << "[+]" << std::endl;
    getchar();
    return 0;
}