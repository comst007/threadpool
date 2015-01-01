OBJS:=testmain.cpp Thread.cpp MyThread.cpp ThreadPool.cpp
testmain:$(OBJS) Thread.h MyThread.h ThreadPool.h MyLock.h MyCondition.h MyTask.h
	g++ -g -o $@ $(OBJS) -lpthread
