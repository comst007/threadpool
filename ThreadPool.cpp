/*************************************************************************
	> File Name: ThreadPool.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 28 Apr 2014 02:26:49 AM CST
 ************************************************************************/
#include "ThreadPool.h"
void ThreadPool::on()
{
	if(!m_on)
	{
		m_on = true ;
		std::vector<MyThread>::iterator iter ;
		for(iter = m_threads.begin(); iter != m_threads.end(); iter ++)
		{
			iter -> start();
		}
	}
}
void ThreadPool::off()
{
	if(m_on)
	{
		m_on = false ;
		m_cond.broadcast();
	}
}
void ThreadPool::allocate_task(MyTask& atask)
{
	m_lock.lock();
#ifndef NDEBUG
	std::cout <<"add task" << std::endl ;
#endif
	m_tasks.push(atask);
	m_lock.unlock();
	m_cond.broadcast();
}
bool ThreadPool::fetch_task(MyTask& atask)
{
	m_lock.lock();
	while(m_on && m_tasks.empty())
	{
		m_cond.wait();
	}
	if(!m_on)
	{
	
#ifndef NDEBUG
	std::cout <<" pool off" << std::endl ;
#endif
	m_lock.unlock();
	m_cond.broadcast();
	return false ;
	}
	atask = m_tasks.front();
	m_tasks.pop();
	m_lock.unlock();
	m_cond.broadcast();
#ifndef NDEBUG
	std::cout <<"fetch task" << std::endl ;
#endif
	return true ;
}





















