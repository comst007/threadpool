/*************************************************************************
	> File Name: MyThread.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 28 Apr 2014 12:44:42 AM CST
 ************************************************************************/
#include "ThreadPool.h"
#include <unistd.h>
#include <iostream>
void MyThread::run()
{
	while(true)	
	{
		MyTask task;
		if(m_pthreadpool -> fetch_task(task) == false )
		{
			break ;
		}
		task.excute();
		sleep(1);
	}
}

