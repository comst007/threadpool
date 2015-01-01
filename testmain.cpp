/*************************************************************************
	> File Name: testmain.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 28 Apr 2014 01:00:54 AM CST
 ************************************************************************/
#include "ThreadPool.h"
#include <iostream>
#include <unistd.h>
int main(int argc, char* argv[])
{
	ThreadPool my_threadpool ;
	my_threadpool.on();
	std::string str ;
	while(std::cin >> str)
	{
		MyTask task(str);
		my_threadpool.allocate_task(task);
	}
	return 0 ;
}
