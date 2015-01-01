#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__
#include <vector>
#include <queue>
#include "MyThread.h"
#include "MyCondition.h"
#include "MyTask.h"
class ThreadPool
{
	public:
		ThreadPool(const int thread_size = 12):m_lock(),m_cond(m_lock),m_threads(thread_size)
		{
			std::vector<MyThread>::iterator iter ;
			for(iter = m_threads.begin(); iter != m_threads.end(); iter ++)
			{
				iter -> get_relate(this);
			}
		}
		void on() ;
		void off() ;

		void allocate_task(MyTask& atask);
		bool fetch_task(MyTask& atask);

	private:
		ThreadPool(const ThreadPool& obj) ;
		ThreadPool& operator = (const ThreadPool& obj) ;
		bool m_on ;
		std::vector<MyThread> m_threads ;
		std::queue<MyTask> m_tasks ;
		MyLock m_lock ;
		MyCondition m_cond ;
};
#endif
