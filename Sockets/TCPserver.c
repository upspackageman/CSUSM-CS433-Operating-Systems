#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
  
	char server_message[256]="You have reached the server!"; 
	
	int server_socket;
	server_socket=socket(AF_INET,SOCK_STREAM,0); 

	//define the sever address
	struct sockaddr_in server_address; 
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(9002);
	server_address.sin_addr.s_addr=INADDR_ANY;

	//bind the socket to our specified IP and port
	bind(server_socket,(struct sockaddr*) &server_address, sizeof(server_address));

	//listen for connection
	listen(server_socket,6); 

	int client_socket; 
	// find  and whre the connection is coming from
	client_socket=accept(server_socket,NULL,NULL); 
	//send message
	send(client_socket,server_message, sizeof(server_message),0);

	//close the socket 
	close(server_socket);   
        return 0;




}

