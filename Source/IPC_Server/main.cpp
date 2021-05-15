#include "stdafx.h"

#define CommPort 3152

void Listener() {

}

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

    Server.sin_family = AF_INET;
    Server.sin_addr.s_addr = INADDR_ANY; // 127.0.0.1 ::1
    Server.sin_port = CommPort;

    if (bind(Socket, (struct sockaddr*)&Server, sizeof(Server)) == SOCKET_ERROR) {
        std::cout << "[-] Failed to bind socket : " << WSAGetLastError() << std::endl;
    }



    std::cout << "[+] Ready " << std::endl;
    return 0;
}