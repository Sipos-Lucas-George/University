#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <string.h>

int main(){
	uint16_t port = 1345;
	char broadcast_ip[] = "172.30.255.255";
	int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_fd == -1){
		perror("Error when creating socket file description.\n");
		return -1;
	}
	printf("Socket created successfully.\n");
	char enable = '1';
	int res = setsockopt(sock_fd, SOL_SOCKET, SO_BROADCAST, &enable, sizeof(enable));
	if(res < 0){
		perror("Error setting socket options.\n");
		return -1;
	}
	printf("Socket options for broadcast enabled successfully.\n");
	struct sockaddr_in broadcaster;
	broadcaster.sin_family = AF_INET;
	broadcaster.sin_port = htons(port);
	inet_aton(broadcast_ip, &broadcaster.sin_addr);	
	socklen_t broadcaster_size = sizeof(broadcaster);
	char buff[] = "HENLO FREN!\n\n\n\n";
	char response[1024];

	struct sockaddr_in receiver_addr;
	socklen_t receiver_addr_len;
	while(1){
		sendto(sock_fd, buff, strlen(buff) + 1, 0, (const struct sockaddr *) &broadcaster, broadcaster_size);
		recvfrom(sock_fd, response, strlen(response) + 1, 0, (struct sockaddr *) &receiver_addr, &receiver_addr_len);
	}
	return 0;
}
