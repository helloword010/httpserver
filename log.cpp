#include"log.h"
#include<time.h>

/*Log::Log(std::string log_file_folder_address,int log_mode_choose):log_fil    e_folder(log_file_folder_address),log_mode(log_mode_choose){
	int ret=access(log_file_folder,rw)
	if(ret==0){
	std::cout<<"this path is valid!"<<std::endl;
}else{
	std::cout<<"this path is invalid!"<<std::endl;
	this->~Log();
	std::cout<<"已析构"<<std::endl;
	std::cout<<"请重新构造"<<std::endl;
}*/
std::string Log::get_time_str(){
	timespec time;
	clock_gettime(CLOCK_REALTIME, &time);  //获取相对于1970到现在的秒数
	tm nowTime;
	localtime_r(&time.tv_sec, &nowTime);
	char current[1024];
	sprintf(current, "%d-%d-%d %d:%02d:%02d", nowTime.tm_year + 1900, nowTime.tm_mon+1, nowTime.tm_mday, 
      nowTime.tm_hour, nowTime.tm_min, nowTime.tm_sec);
	std::string current_time=current;
	current_time="["+current_time;
	current_time+="]  ";
	return current_time;
}


std::string Log::get_time_str(LOG_MODE log_Mode){
	timespec time;
	clock_gettime(CLOCK_REALTIME, &time);  //获取相对于1970到现在的秒数
        tm nowTime;
	localtime_r(&time.tv_sec, &nowTime);
	char current[1024];
	switch(log_Mode){
	case DAY:sprintf(current, "%d-%d-%d", nowTime.tm_year + 1900, nowTime.tm_mon+1, nowTime.tm_mday);
	break;
	case HOUR:sprintf(current, "%d-%d-%d %d", nowTime.tm_year + 1900, nowTime.tm_mon+1, nowTime.tm_mday,nowTime.tm_hour);
	break;
	case MINUTE:sprintf(current, "%d-%d-%d %d:%d", nowTime.tm_year + 1900, nowTime.tm_mon+1, nowTime.tm_mday,nowTime.tm_hour, nowTime.tm_min);
	break;
        }

	std::string current_time=current;
	return current_time;
 }

void Log::log_message(){
	std::cout<<"当前模式为"<<log_mode<<std::endl;
}

void Log::write_line(std::string log_message){
	log_message=get_time_str()+log_message;
	std::string log_file_name=get_time_str(log_mode);
	log_file_name+=".txt";
	
	log_file_name=log_file_folder+log_file_name;
        int fd=open(log_file_name.c_str(),O_RDWR|O_CREAT|O_APPEND);
	if(fd==-1){
		std::cout<<"打开失败！"<<std::endl;
	}else{
		log_message+="\r";
		write(fd,(void *)log_message.c_str(),log_message.size());	
	}
	close(fd);
}
