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
    SOCKET Socket;

    if ((Socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        std::cout << "[-] Failed to create socket" << std::endl;
        system("pause");
        return 1;
    }


    std::cout << "[+] Ready " << std::endl;
    return 0;
}