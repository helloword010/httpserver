#include"phrase.h"



void Http_phrase::phrase(){
	if(message_data.find("")==std::string::npos)
	{
		std::cout<<message_data.find("")<<std::endl;

	}else{
		std::cout<<"未查找到"<<std::endl;}
}


LINE_STATUS Http_phrase::parse_line(char *buffer,int &checked_index,int &read_index){
	char temp;
	/*checked_index指向buffer（应用程序中的读缓冲区）中当前正在分析的字节，read_index 指向客户程序数据尾部的下一字节。buffer中第0～checked_index
	字节都已分析完毕，第checked_index ～（read——index-1）字节由下面的循环进行分析*/
	for(;checked_index<read_index;checked_index){
		/*****获取当前要分析的字节********/
		temp=buffer[checked_index];
		/****如果当前字节为‘\r’,则说明可能读取到一个完整行*****/
		if(temp=='\r'){
		/*******如果“\r”刚好是目前buffer中的最后一个已经被读入的客户数据，那么这次分析没有读取到一个完整的行，返回LINE——OPEN以表示还需要即系读取客户数据才能			进一步进行分析*************/
			if((checked_index+1)==read_index){
				return LINE_OPEN;
				}else if(buffer[checked_index+1]=='\n'){
						buffer[checked_index++]='\0';
						buffer[checked_index++]='\0';
						return LINE_OK;
						}
		/******否则。http请求存在语法问题*****************/
		return LINE_BAD;
		}else if(temp=='\n'){
			if((checked_index>1)&&buffer[checked_index-1]=='\r'){
				buffer[checked_index-1]='\0';
				buffer[checked_index++]='\0';
				return LINE_OK;
			}
		return LINE_BAD;
 		}
	}
	return LINE_OPEN;	
}

LINE_STATUS Http_phrase::parse_line(std::string buffer,int &checked_index,int &read_index){
	return parse_line(buffer.c_str(),checked_index,read_index);
}

HTTP_CODE Http_phrase::parse_requestline(char *temp,CHECK_STATE &checkstate){
}
