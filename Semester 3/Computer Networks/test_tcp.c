#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>

void client(int fd){
	char strg[] = "Salut Sicoe!\n";
	write(fd, strg, strlen(strg));
	
	
	int x;
	read(fd, &x, sizeof(int));

	char newStrg[] = "Bravo Sicoe!\n";
	if(x == 3){
		write(fd, newStrg, strlen(newStrg));
	}
}

int main(){
        uint16_t port = 1234;
        int backlog = 10;
        char address[256] = "172.24.12.251";
        int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if(sock_fd == -1){
                perror("Socket error!\n");
                return -1;
        }
        printf("Socket created.\n");

        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_aton(address, &server_addr.sin_addr);
        socklen_t server_addr_len = sizeof(server_addr);
        int res = bind(sock_fd, (const struct sockaddr *) &server_addr, server_addr_len);
        if(res == -1){
		printf("Bind Error!\n");
		return -1;
	}
	printf("Bind created!\n");
	res = listen(sock_fd, backlog);
        if(res == -1){
		printf("Listen Error");
		return -1;
	}
	printf("Listen created!\n");
        struct sockaddr_in client_addr;
        socklen_t client_addr_len;
        while(1){
                int client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len);
                if(client_fd == -1){
                        perror("Accept error!\n");
                        continue;
                }
      		client(client_fd);
        }
        return 0;
}
