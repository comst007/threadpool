#ifndef __MYTHREAD_H__
#define __MYTHREAD_H__
#include "Thread.h"
class ThreadPool ;
class MyThread : public Thread
{
	public:
		void get_relate(ThreadPool* p)
		{
			m_pthreadpool = p ;
		}
	private:
		void run();
		ThreadPool * m_pthreadpool ;
};
#endif
