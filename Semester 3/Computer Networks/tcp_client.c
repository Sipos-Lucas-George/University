#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <pthread.h>

void *func(void *a){
	uint16_t port = 9998;
        char receiver_ip[] = "172.30.118.193";
        int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
        if(sock_fd == -1){
                perror("Socket error.\n");
                return NULL;
        }
        printf("Socket created.\n");
        struct sockaddr_in receiver;
        receiver.sin_family = AF_INET;
        receiver.sin_port = htons(port);
        inet_aton(receiver_ip, &receiver.sin_addr);
        char message[] = "Lucas a trimis mesaj!\n";
        socklen_t receiver_size = sizeof(receiver);
        
	struct sockaddr_in sender;
	socklen_t sender_size = sizeof(sender);
	char buff[1024];
	while(1){
                sendto(sock_fd, message, strlen(message) + 1, 0, (const struct sockaddr *) &receiver, receiver_size);
		printf("Sent!\n");
		recvfrom(sock_fd, buff, 30, 0, (struct sockaddr *) &sender, &sender_size);
		printf("Received\n");
		printf("%s\n", buff);
	}
	return NULL;
}

void *func2(void *a){
	uint16_t port = 4443;
        char broadcast_ip[] = "172.30.255.255";
        int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
        if(sock_fd == -1){
                perror("Error when creating socket file description.\n");
                return NULL;
        }
        printf("Socket created successfully.\n");
        char enable = '1';
        int res = setsockopt(sock_fd, SOL_SOCKET, SO_BROADCAST, &enable, sizeof(enable));
        if(res < 0){
                perror("Error setting socket options.\n");
                return NULL;
        }
        printf("Socket options for broadcast enabled successfully.\n");
        struct sockaddr_in broadcaster;
        broadcaster.sin_family = AF_INET;
        broadcaster.sin_port = htons(port);
        inet_aton(broadcast_ip, &broadcaster.sin_addr);
        socklen_t broadcaster_size = sizeof(broadcaster);
        char buff[] = "HENLO FREN!\n";
        char response[1024];

        struct sockaddr_in receiver_addr;
        socklen_t receiver_addr_len;
        while(1){
                sendto(sock_fd, buff, strlen(buff) + 1, 0, (const struct sockaddr *) &broadcaster, broadcaster_size);
                int res = recvfrom(sock_fd, response, strlen(response) + 1, 0, (struct sockaddr *) &receiver_addr, &receiver_addr_len);
        	printf("%d\n", res);
	}
	return NULL;
}

int main(){
	/*
	uint16_t port = 9999;
	char server_address[] = "172.30.118.193";
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd == -1){
		perror("Socket error!\n");
		return -1;
	}
	printf("Socket created!\n");
	struct sockaddr_in client_addr;
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(port);
	inet_aton(server_address, &client_addr.sin_addr);
	socklen_t client_addr_len = sizeof(client_addr);
	int res = connect(socket_fd, (const struct sockaddr*)&client_addr, client_addr_len);
	if(res == -1){
		perror("Connect error!\n");
		return -1;
	}
	printf("Connected to address %s and port %d.\n",server_address, port);

	//client primeste si afiseaza string

	char buffer1[100];
	
	int rez1 = read(socket_fd, buffer1, 101);

	if(rez1 == -1){
		perror("Read error! \n");
		close(socket_fd);
		return -1;
	}

	printf("Received from server: %s\n", buffer1);

	//client trimite int
	int num;
	while(1){
		printf("\nNumber: ");
		scanf("%d", &num);
		num = htonl(num);
		write(socket_fd, &num, sizeof(int));

		//client primeste string if conditie
		char buffer[100];
		int rez = read(socket_fd, buffer, 101);
		if(strcmp(buffer, "gresit\n") == 0){
			perror("Raspuns gresit!\n");
		}
		else{
			printf("Server sent: %s\n", buffer);
			break;
		}
	}*/
	pthread_t thr;
	pthread_create(&thr, NULL, func, NULL);
	pthread_join(thr, NULL);
	
	//pthread_t thr1;
        //pthread_create(&thr1, NULL, func2, NULL);
        //pthread_join(thr1, NULL);
	return 0;
}
