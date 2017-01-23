#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
        //create socket
        int network_socket;
        network_socket =socket(AF_INET, SOCK_STREAM,0);

        //specify an address for the socket

        struct sockaddr_in server_address;
        server_address.sin_family=AF_INET;
        //specify port
        server_address.sin_port=htons(9002);
        //specifiy address
        server_address.sin_addr.s_addr=INADDR_ANY;

        int connection_status=connect(network_socket,(struct sockaddr *) &server_address, sizeof(server_address));
        // check for error with the connection
        if(connection_status== -1){
                printf("Ther was an error making a connection to the remote socket \n\n");
        }
        // recieve data from server
        char server_response[256];
        recv(network_socket,&server_response, sizeof(server_response), 0);
        //print out server's response
        printf("Ther server sent the data: %s\n", server_response);

        //and then close the socket
        close(network_socket);
        return 0;




}
