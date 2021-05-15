#include "stdafx.h"


int main(int argc, char* argv[])
{
    #pragma region Clean

    WSACleanup();
    WSADATA wsa_data;
    WSAStartup(MAKEWORD(2, 2), &wsa_data);

    #pragma endregion

    SOCKET Socket;
    if ((Socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        std::cout << "[-] Failed to create socket" << std::endl;
        system("pause");
        return 1;
    }



    return 0;
}