#ifndef __MYTASK_H__
#define __MYTASK_H__
#include <iostream>
class MyTask
{
	public:
		MyTask(const std::string &express =""):m_express(express)
		{
		}
		void excute()
		{
			std::cout << "express: " << m_express << std::endl ;
		}
	private:
		std::string m_express ;
};
#endif
