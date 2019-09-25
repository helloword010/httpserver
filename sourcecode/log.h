#ifndef LOG_H_
#define LOG_H_
#include<iostream>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
/**********该日志类为非线程安全的。如需在多线程程序中使用，建议区分文件使用*******************************/
/*log 的格式为[日期-小时（24小时制）-分钟-秒-毫秒]-----todo*/
    enum LOG_MODE{
          DAY,
          HOUR,
          MINUTE, };

class Log{
public:
	Log(std::string log_file_folder_address,LOG_MODE log_mode_choose):log_file_folder(log_file_folder_address),log_mode(log_mode_choose){
	int ret=access(log_file_folder.c_str(),06);
           if(ret==0){
           std::cout<<"this path is valid!"<<std::endl;
   }else{
           std::cout<<"this path is invalid!"<<std::endl;
          std::cout<<"请重新构造"<<std::endl;
}
};/*文件的路径必须是已存在的*/
	~Log(){std::cout<<"已析构"<<std::endl;}
	std::string get_time_str(LOG_MODE log_Mode);
	void log_message();
	void write_line(std::string log_message);
	std::string get_time_str();
	//std::string get_time_str(int log_mode);
	//void mode(int log_mode);
private:
	std::string log_file_folder;
	LOG_MODE log_mode;
	
 };
#endif

