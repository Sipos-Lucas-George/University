#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>

int main(){
	uint16_t port = 1234;
	char server_address[256] = "192.168.50.160";
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd == -1){
		perror("Error socket!\n");
		return -1;
	}
	printf("Successfully created socket.\n");
	struct sockaddr_in client_addr;
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(port);
	inet_aton(server_address, &client_addr.sin_addr);
	socklen_t client_addr_len = sizeof(client_addr);
	int res = connect(socket_fd, (const struct sockaddr *) &client_addr, client_addr_len);
	if(res == -1){
		perror("Connect error!\n");
		return -1;
	}
	printf("Successfully connected to server at address %s on port %d.\n", server_address, port);
	char mess[256] = "Andrei\0";
	int len_mess = strlen(mess);
	len_mess = htonl(len_mess + 1);
	write(socket_fd, &len_mess, sizeof(int));
	write(socket_fd, mess, strlen(mess) + 1);
	return 0;
}
