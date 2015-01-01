#ifndef __THREAD_H__
#define __THREAD_H__
#include <pthread.h>
#include <stdexcept>
class Thread 
{
	public:
		Thread():m_on(false)
		{
			pthread_attr_init(&m_attr);
			if(pthread_attr_setdetachstate(&m_attr, PTHREAD_CREATE_DETACHED))
			{
				throw std::runtime_error("pthread_attr");
			}
		}
		void start(void* arg=NULL);
		~Thread()
		{
			pthread_attr_destroy(&m_attr);
		}
		const pthread_t get_tid() const
		{
			return m_tid ;
		}
	protected:
		void*  m_arg ;
	private:
		bool m_on ;
		virtual void run() = 0 ;
		static void* thread_handle(void* arg);
		pthread_attr_t m_attr ;
		pthread_t m_tid ;		
};
#endif
