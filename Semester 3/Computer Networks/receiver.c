#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netinet/ip.h>
int main(){
	uint16_t port = 1234;
	int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_fd == -1){
		perror("Error when creating socket file description.\n");
		return -1;
	}
	printf("Socket created successfully.\n");
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = INADDR_ANY;
	socklen_t server_size = sizeof(server);
	int res = bind(sock_fd, (const struct sockaddr *) &server, server_size);
	if(res == -1){
		perror("Error when creating bind.\n");
		return -1;
	}
	printf("Bind created successfully.\n");
	char buff[1024];
	struct sockaddr_in sender_addr;
	socklen_t sender_addr_size;
	while(1){
		recvfrom(sock_fd, buff, 1024, 0, (struct sockaddr *) &sender_addr, &sender_addr_size);
		printf("%s : %s", inet_ntoa(sender_addr.sin_addr), buff);
	}
	return 0;
}
