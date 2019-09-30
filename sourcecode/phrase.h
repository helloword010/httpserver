#ifndef PHRASE_H_
#define PHRASE_H_
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
static std::string Content_type_table[13][2]={
	{{ "txt"},{ "text/plain" }},
	{{ "c"}, {"text/plain" }},
	{{ "h"},{ "text/plain" }},
	{{ "html"},{ "text/html" }},
	{{ "htm"},{ "text/htm" }},
	{{ "css"},{ "text/css" }},
	{{ "gif"},{ "image/gif" }},
	{{ "jpg"},{ "image/jpeg" }},
	{{ "jpeg"},{ "image/jpeg" }},
	{{ "png"},{ "image/png" }},
	{{ "pdf"},{ "application/pdf" }},
	{{ "ps"},{ "application/postscript"} },
	{{ NULL},{ NULL }}
};

static std::string Request_type_table[]={"POST",
	"GET",
	"PUT",
	"DELETE",
	"PATCH",
	"CONNECT",
	"TRACE",
	"HEAD",
	"OPTIONS"};

enum CHECK_STATE{
		CHECK_STATE_REQUESTLINE=0,CHECK_STATE_HEADER
};//主状态机的两种状态：正在分析请求行，正在分析头部字段
enum LINE_STATUS{
	LINE_OK=0,
	LINE_BAD,	
	LINE_OPEN
};//从状态机的3种状态：即行的读取状态
enum HTTP_CODE{
	NO_REQUEST,
	GET_REQUEST,
	BAD_REQUEST,
	FORBIDDEN_REQUEST,
	INTERNAL_ERROR,
	CLOSE_CONNECTION
};/*服务器处理HTTP请求的结果：NO_REQUEST 表示请求不完整，需要继续读取客户数据；GET_REQUEST 表示获取了一个完整的客户请求
	BAD_REQUEST 表示客户请求有语法错误；FORBIDDEN_REQUEST 表示客户对资源没有足够的访问权限；INTERNAL_ERROR 表示服务器
	内部错误；CLOSE_CONNECTION 表示客户端已经关闭连接了*/



			
class Http_phrase{
public:
	Http_phrase(char * http_message):message_data(http_message){};
public:
	void request_type_phrase();
	void phrase();
protected:
	LINE_STATUS parse_line(char *buffer,int &checked_index,int &read_index);
	LINE_STATUS parse_line(std::string buffer,int &check_index,int &read_index);
	HTTP_CODE parse_requestline(char *temp,CHECK_STATE &checkstate);//分析请求行
private:
	std::string message_data;
	std::string data;
	
};

#endif
