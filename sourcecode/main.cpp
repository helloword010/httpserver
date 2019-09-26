#include<iostream>
#include<string>
#include"log.h"
#include"server.h"
#include"phrase.h"
int main()
{
      
std::cout<<Content_type_table[1][1]<<std::endl;
Server server_obj("127.0.0.1",8080);
	server_obj.show_message();
server_obj.server_init();
Http_phrase ph("nihao\r\n\r\n你好");
ph.phrase();
	return 0;
}
