#ifndef SERVER_H_
#define SERVER_H_
#include<string>
#include<iostream>
#include"log.h"
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
static Log log("/home/yunzhitec/PROJECT/LOG/",HOUR);
class Server{
	public:
        Server();
	Server(std::string ip_address,int port_name):ip(ip_address),port(port_name){};
	void show_message();
	void server_init();
	public:
	std::string ip="";
	int port=0;
	private:
	struct sockaddr_in address;
	int listenfd,sendfd,recvfd;
	
        
};



#endif
