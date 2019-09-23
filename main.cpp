#include<iostream>
#include"server.h"
#include<string>
int main()
{
        
	Server server_obj("127.0.0.1",8080);
	server_obj.show_message();
	return 0;
}
