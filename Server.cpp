//
// Created by osnat on 12/29/18.
//


#include <sys/socket.h>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <iostream>
#include "Server.h"
#define BUFFER_SIZE 1024

bool Server::sould_stop;
pthread_t Server::pthreadID;

void* thread_func(void* args){
    struct arg_struct *params = (struct arg_struct*)args;
    char buffer[BUFFER_SIZE+1];
    string buff2 = "";
    while(!Server::sould_stop){
        ssize_t n = read(params->socket_args, buffer,BUFFER_SIZE);
        if(n<=0) {
            perror("ERROR read from socket");
            exit(1);
        }
        buffer[n] = 0;
        buff2 += buffer;

        //cout << buffer<< endl;
        bool result = params->fsParamMap_args->parsBuffer(buff2);
        while (result){
            result = params->fsParamMap_args->parsBuffer(buff2);
        }
    }
    close(params->socket_args);
    delete(params);

}

void Server::run(int port, int herz, FSParamMap* fsParamMap) {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    close(sockfd);

    auto args = new arg_struct();
    args->socket_args = newsockfd;
    args->fsParamMap_args = fsParamMap;
    pthread_create(&Server::pthreadID, nullptr, thread_func, args);

}

void Server::stop() {
    Server::sould_stop = true;
    pthread_join(Server::pthreadID, nullptr);
}

