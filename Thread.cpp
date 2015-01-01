/*************************************************************************
	> File Name: MyThread.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 28 Apr 2014 12:13:45 AM CST
 ************************************************************************/
#include "Thread.h"
void* Thread::thread_handle(void* arg)
{
	Thread* p = (Thread*)arg ;
	p -> run();
}
void Thread::start(void* arg)
{
	if(!m_on)
	{
		if( pthread_create(&m_tid, &m_attr, Thread::thread_handle, this ) )
		{
			throw std::runtime_error("pthread_create");
		}
	}
}
