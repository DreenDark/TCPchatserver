#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
    int sockfd;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        printf("socket cration failed!");
        return -1;
    }
    printf("Socket created successfully\n");
    
    char x[16];
    printf("Enter the destination IP= ");
    fgets(x,sizeof(x),stdin);
    x[(strcspn(x,"\n"))]='\0';
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(8080);
    server_addr.sin_addr.s_addr=inet_addr(x);

    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("Connect failed");
    return 1;
    }
    printf("Connected to server!\n");

    while(1){
    char buffer[1024],message[1024];
    printf("You: ");
    fgets(message,sizeof(message),stdin);
    message[(strcspn(message,"\n"))]='\0';

    send(sockfd,message,strlen(message),0);

    memset(buffer,0,sizeof(buffer));
    int bytes_recived=recv(sockfd,buffer,sizeof(buffer)-1,0);
    if(bytes_recived<=0){
        printf("Server disconnected!\n");
        break;
    }
    printf("server: %s\n",buffer);

    }

    close(sockfd);
    return 0;
}