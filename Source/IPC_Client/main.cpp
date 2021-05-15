#include "stdafx.h"

int main(int argc, char* argv[])
{
    #pragma region Clean

    WSACleanup();
    WSADATA wsa_data;
    WSAStartup(MAKEWORD(2, 2), &wsa_data);

    #pragma endregion


    std::cout << "[+]" << std::endl;
    getchar();
    return 0;
}