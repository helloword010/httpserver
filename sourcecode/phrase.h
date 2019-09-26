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
	
class Http_phrase{
public:
	Http_phrase(char * http_message):message_data(http_message){};
public:
	void request_type_phrase();
	void phrase();

private:
	std::string message_data;
	std::string data;
	
};

#endif
