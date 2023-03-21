#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <string.h>

int main(){
	uint16_t port = 1234;
	char receiver_ip[] = "172.30.117.34";
	int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_fd == -1){
		perror("Error when creating socket file description.\n");
		return -1;
	}
	printf("Socket created successfully.\n");
	struct sockaddr_in receiver;
	receiver.sin_family = AF_INET;
	receiver.sin_port = htons(port);
	inet_aton(receiver_ip, &receiver.sin_addr);
	char message[] = "Salud!\n\n\nSEEN..\n";
	socklen_t receiver_size = sizeof(receiver);
	while(1){
		sendto(sock_fd, message, strlen(message) + 1, 0, (const struct sockaddr*) &receiver, receiver_size);
	}
	return 0;
}
