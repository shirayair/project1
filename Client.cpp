//
// Created by osnat on 12/27/18.
//

#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <sstream>
#include <cstring>
#include "Client.h"
int Client::socket_id = -1;

void Client::connectClient(string ip, int port) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    portno = port;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(ip.c_str());

    if (server == nullptr) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,(size_t) server->h_length);
    serv_addr.sin_port = htons((uint16_t)portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    socket_id = sockfd;

}



void Client:: send(string path, double value){
    if(path[0] == '/') {
        path.erase(0,1);
    }
    ostringstream strs;
    strs << value;
    string double_str = strs.str();
    string message = "set "+path+" "+double_str+"\r\n";

    /* Send message to the server */
    ssize_t n = write(socket_id, message.c_str(),strlen(message.c_str()) );

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

}

void Client::closeClient(){
    close(socket_id);
    socket_id = -1;
}