#include"server.h"
Server::Server(){};
void Server::show_message(){
std::cout<<ip<<":"<<port<<std::endl;
}


void Server::server_init(){
	/*****该函数 包含监听socket的创建及socket的绑定 并写入log文件 ******/
	bzero(&address,sizeof(address));
	address.sin_family=AF_INET;
	inet_pton(AF_INET,ip.c_str(),&address.sin_addr);
	address.sin_port=htons(port);
	listenfd=socket(AF_INET,SOCK_STREAM,0);
	if(listenfd>=0){
	log.write_line("create socket success!");
	}else{
	log.write_line("create socket failed!");
	}

	int ret=bind(listenfd,(struct sockaddr *)&address,sizeof(address));
	if(ret!=-1){
	log.write_line("listenfd bind success!");
	}else{
	log.write_line("listen bind failed!");
	}	
	log.write_line("init complate");
}


void Server::server_receive(){
}
