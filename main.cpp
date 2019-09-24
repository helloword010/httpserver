#include<iostream>
#include"server.h"
#include<string>
#include"log.h"
int main()
{
        Log log_obj("/home/yunzhitec/PROJECT/LOG/",HOUR);
//	std::cout<<log_obj.get_time_str()<<std::endl;
	
std::cout<<log_obj.get_time_str(HOUR);
 std::cout<<log_obj. get_time_str(HOUR);
 std::cout<<log_obj. get_time_str(MINUTE);
log_obj.log_message();
	
	log_obj.write_line("你好");
Server server_obj("127.0.0.1",8080);
	server_obj.show_message();
	
	return 0;
}
