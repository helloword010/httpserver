#ifndef SERVER_H_
#define SERVER_H_
#include<string>
#include<iostream>
using namespace std;
class Server{
	public:
        Server();
	Server(std::string ip_address,int port_name):ip(ip_address),port(port_name){};
	void show_message();
	public:
	std::string ip="";
	int port=0;
        
};



#endif
