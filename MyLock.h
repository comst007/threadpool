#ifndef __MYLOCK_H__
#define __MYLOCK_H__
#include <pthread.h>
class MyLock
{
	public:
		friend class MyCondition ;
		MyLock()
		{
			pthread_mutex_init(&m_mutex, NULL);
		}
		void lock()
		{
			pthread_mutex_lock(&m_mutex);
		}
		void unlock()
		{
			pthread_mutex_unlock(&m_mutex);
		}
		~MyLock()
		{
			pthread_mutex_destroy(&m_mutex);
		}
	private:
		MyLock(const MyLock &obj);
		MyLock& operator = (const MyLock& obj) ;
		pthread_mutex_t	 m_mutex ;
};
#endif
