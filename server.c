#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include<string.h>

int main(){

    int newsocket;
    newsocket=socket(AF_INET,SOCK_STREAM,0);
    if (newsocket<0) {
        printf("Connection failed!");
        return 1;}
    printf("Socket created successfully\n");

    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(8080);
    server_addr.sin_addr.s_addr=INADDR_ANY;

    if (bind(newsocket,(struct sockaddr*)&server_addr,sizeof(server_addr))<0){
        printf("Bind failed\n");
        close(newsocket);
        return 1;
    }
   

    if(listen(newsocket,4)<0){
    printf("Listen faild\n");
    close(newsocket);
    return 1;
    }
    printf("Server is listening\n");

    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len=sizeof(client_addr);

    client_socket=accept(newsocket,(struct sockaddr*)&client_addr,&client_addr_len);
    if (client_socket<0){
        printf("Accept failed\n");
        close(newsocket);
        return 1;
    }
    printf("Client connected!\n");

    char buffer[1024];
    char message[1024];
    while(1){
        memset(buffer,0,sizeof(buffer));
        int bytes_recived=recv(client_socket,buffer,sizeof(buffer)-1,0);
        if(bytes_recived<=0){
            printf("Client disconnected\n");
            break;
        }
        printf("client: %s\n",buffer);

        printf("You: ");
        fgets(message,sizeof(message),stdin);
        message[strcspn(message,"\n")]=0;
        send(client_socket,message,strlen(message),0);
    }
    close(client_socket);
    close(newsocket);

    return 0;

}