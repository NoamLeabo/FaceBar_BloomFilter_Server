#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread> // Add this header for multithreading

#include "App.h"
#include "CheckUrl.h"
#include "AddUrl.h"
#include "HashNo1.h"
#include "HashNo2.h"
#include "ConsoleMenu.h"
using namespace std;

void handleClient(int client_sock, App* app_ptr)
{
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    App* app = app_ptr;
    while (true)
    {
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0)
        {
            cout << "client disconnected" << endl;
            break;
        }
        else if (read_bytes < 0)
        {
            perror("error reading from client");
            break;
        }
        else
        {
            if (app->bFInitialized())
            {
                int task = stoi(string(1, buffer[0]));
                string url = string(&buffer[2]);
                bool res = app->doCommand(task, url);
                // "2 " + url
                int sent_bytes;
                if (res == false)
                {
                    buffer[0] = 'F';
                    sent_bytes = send(client_sock, buffer, read_bytes, 0);
                }
                else
                {
                    buffer[0] = 'T';
                    sent_bytes = send(client_sock, buffer, read_bytes, 0);
                }
                if (sent_bytes < 0)
                {
                    perror("error sending to client");
                    break;
                }
            }
            else
            {
                ConsoleMenu menu;
                int initVals[3];
                menu.initFromBuff(initVals, buffer);
                BloomFilter bf = BloomFilter(0, 1, app->getFuncBank());
                if (initVals[2] == -1)
                {
                    bf = BloomFilter(initVals[0], initVals[1], app->getFuncBank());
                }
                else
                {
                    bf = BloomFilter(initVals[0], initVals[1], initVals[2], app->getFuncBank());
                }
                AddUrl add(&bf);
                app->addCommand(1, &add);
                CheckUrl check(&bf);
                app->addCommand(2, &check);
                cout << "BloomFilter not initialized" << endl;
                app->doCommand(1, "http://www.google.com");
                app->doCommand(2, "http://www.google1.com");
                app->doCommand(2, "http://www.google.com");
                app->setBF(&bf);
            }
        }
    }

    close(client_sock);
}

int main()
{
    vector<HashFunc *> funcBank;
    HashNo1 f1;
    HashNo2 f2;
    funcBank.push_back(&f1);
    funcBank.push_back(&f2);
    App app(funcBank);

    const int server_port = 7272;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
        return 1;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
        return 1;
    }
    if (listen(sock, 5) < 0)
    {
        perror("error listening to a socket");
        return 1;
    }

    cout << "server is listening..." << endl;

    while (true)
    {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
        cout << "client connected" << endl;
        if (client_sock < 0)
        {
            perror("error accepting client");
            return 1;
        }

        // Create a new thread to handle the client connection
        thread client_thread(handleClient, client_sock, &app);
        client_thread.detach(); // Detach the thread to run independently
    }

    close(sock);
    return 0;
}
