#ifndef __MYCONDITION_H__
#define __MYCONDITION_H__
#include "MyLock.h"
class MyCondition
{
	public:
		MyCondition( MyLock & obj):m_lock(obj)
		{
			pthread_cond_init(&m_cond, NULL) ;
		}
		void wait()
		{
			pthread_cond_wait(&m_cond, &m_lock.m_mutex);
		}
		void broadcast()
		{
			pthread_cond_broadcast(&m_cond);
		}
		~MyCondition()
		{
			pthread_cond_destroy(&m_cond);
		}
	private:
		MyCondition( MyCondition& obj);
		MyCondition& operator = ( MyCondition& obj) ;
		pthread_cond_t m_cond ;
		MyLock& m_lock ;
};
#endif
