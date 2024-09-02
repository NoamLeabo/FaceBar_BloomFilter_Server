#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <vector>
#include <sstream>
#include <thread>
#include "App.h"
#include "CheckUrl.h"
#include "AddUrl.h"
#include "HashNo1.h"
#include "HashNo2.h"
#include "ConsoleMenu.h"
using namespace std;

// handle a client connection
void handleClient(int client_sock, App *app_ptr)
{
    // create a buffer to read data from the client
    char buffer[4096];
    // set the expected data length
    int expected_data_len = sizeof(buffer);
    // get the app object from the pointer
    App *app = app_ptr;
    // create a bloom filter object with the app's hash-functions bank
    BloomFilter bf = BloomFilter(0, 1, app->getFuncBank());
    // read data from the client in a loop
    while (true)
    {
        // read data from the client
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        // check if the client disconnected
        if (read_bytes == 0)
        {
            // indicate that the client disconnected
            cout << "client disconnected" << endl;
            break;
        }
        // check if an error occurred while reading
        else if (read_bytes < 0)
        {
            // print an error message
            perror("error reading from client");
            break;
        }
        else
        {
            // if the app is already initialized
            if (app->bFInitialized())
            {
                // extract the task number
                int task = stoi(string(1, buffer[0]));
                // extract the url
                string url = string(&buffer[2]);
                // print the task and the url
                cout << "the url is: " + url << endl;
                // execute the task (will be in form of "2 " + url)
                bool res = app->doCommand(task, url);
                int sent_bytes;
                if (res == false)
                {
                    // if the bloom filter does not contain the url in the black-list send 'F' to the client
                    buffer[0] = 'F';
                    sent_bytes = send(client_sock, buffer, read_bytes, 0);
                    // clear the buffer
                    memset(buffer, 0, sizeof(buffer));
                }
                else
                {
                    // if the bloom filter contains the url in the black-list send 'T' to the client
                    buffer[0] = 'T';
                    sent_bytes = send(client_sock, buffer, read_bytes, 0);
                    // clear the buffer
                    memset(buffer, 0, sizeof(buffer));
                    break;
                }
                // check if an error occurred while sending
                if (sent_bytes < 0)
                {
                    // print an error message
                    perror("error sending to client");
                    break;
                }
            }
            // if the app is not initialized
            else
            {
                // extract the initialization values
                ConsoleMenu menu;
                int initVals[3];
                menu.initFromBuff(initVals, buffer);
                cout << buffer << endl;
                // create a new bloom filter object due to the initialization values
                if (initVals[2] == -1)
                {
                    bf = BloomFilter(initVals[0], initVals[1], app->getFuncBank());
                }
                else
                {
                    bf = BloomFilter(initVals[0], initVals[1], initVals[2], app->getFuncBank());
                }
                // send a msg back to the client that the bloom filter was initialized and ready to get the blacked urls
                int sent_bytes = send(client_sock, buffer, read_bytes, 0);
            
                // add cmds to the app
                AddUrl add(&bf);
                app->addCommand(1, &add);
                CheckUrl check(&bf);
                app->addCommand(2, &check);

                // receive the black-listed urls from the client
                int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
                std::vector<std::string> urls;
                // parse the urls
                char* url = strtok(buffer, ",");
                // iterate over the urls and add them to the bloom filter's black-list
                while (url != NULL) {
                    urls.push_back(std::string(url));
                    url = strtok(NULL, ",");
                }
                for (const auto& url : urls) {
                    std::cout << url << std::endl;
                    app->doCommand(1, url);
                }
                // set the initialized bloom filter to the app
                app->setBF(&bf);
            }
        }
    }
    // close the client socket
    close(client_sock);
    // indicate that the client was closed
    cout << "client was closed" << endl;
}

int main()
{
    // create hash-functions bank
    vector<HashFunc *> funcBank;
    // create hashFunc1
    HashNo1 f1;
    // create hashFunc2
    HashNo2 f2;
    // add hashFunc1 and hashFunc2 to the bank
    funcBank.push_back(&f1);
    funcBank.push_back(&f2);
    // create an app with the hash-functions bank
    App app(funcBank);

    // set a socket port
    const int server_port = 7979;
    // create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // check if the socket was created successfully
    if (sock < 0)
    {
        // print an error message
        perror("error creating socket");
        return 1;
    }

    // create a socket struct
    struct sockaddr_in sin;
    // reset the struct
    memset(&sin, 0, sizeof(sin));
    // set the struct fields
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    // bind the socket to the port
    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        // print an error message
        perror("error binding socket");
        return 1;
    }
    // listen to the socket with a queue of 5 clients at most
    if (listen(sock, 5) < 0)
    {
        // print an error message
        perror("error listening to a socket");
        return 1;
    }

    // indidate that the server is listening
    cout << "server is listening..." << endl;

    // accept clients in a loop
    while (true)
    {
        // create a client socket struct
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        // accept a client connection
        int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
        // indicate that a client connected
        cout << "client connected" << endl;
        // check if the client was accepted
        if (client_sock < 0)
        {
            // print an error message
            perror("error accepting client");
            return 1;
        }

        // create a new thread to handle the client connection
        thread client_thread(handleClient, client_sock, &app);
        // detach the thread to run independently
        client_thread.detach();
    }

    // close the main socket
    close(sock);
    // indicate that the main socket was closed
    cout << "main socket was closed" << endl;
    // return 0 when server is closed
    return 0;
}
