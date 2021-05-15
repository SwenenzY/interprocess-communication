#include "stdafx.h"

#define CommPort 3152
struct sockaddr_in Server, Listen;
SOCKET Socket;
char Buffer[512];
int FromLen;
int RecvLen;

void Listener() {
    while (true) {
        memset(&Buffer, '\0', sizeof(Buffer));

        if ((RecvLen == recvfrom(Socket, Buffer, 512, 0, (struct sockaddr*)&Listen, &FromLen)) == SOCKET_ERROR) {
            std::cout << "[-] Failed to create recvfrom " << WSAGetLastError() << std::endl;
        }

        if (FromLen > 0) {
            std::cout << "[!] Recevied packet from " << inet_ntoa(Listen.sin_addr) << ":" << ntohs(Listen.sin_port) << std::endl;
        }
    }
}

int main(int argc, char* argv[])
{
    #pragma region Clean

    WSACleanup();
    WSADATA wsa_data;
    WSAStartup(MAKEWORD(2, 2), &wsa_data);

    #pragma endregion

    if ((Socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        std::cout << "[-] Failed to create socket" << std::endl;
        system("pause");
        return 1;
    }

    Server.sin_family = AF_INET;
    Server.sin_addr.s_addr = inet_addr("127.0.0.1"); // 127.0.0.1 ::1
    Server.sin_port = CommPort;

    if (bind(Socket, (struct sockaddr*)&Server, sizeof(Server)) == SOCKET_ERROR) {
        std::cout << "[-] Failed to bind socket : " << WSAGetLastError() << std::endl;
    }

    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Listener, 0, 0, 0);

    std::cout << "[+] Waiting packet from client. " << std::endl;
    getchar();
    return 0;
}