#include <scpthread.h>
#include <pthread.h>

//全局计时器,存在锁问题
static int _old;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//简单的线程打印函数
static void _ppt(const char* str)
{
    //pthread_mutex_lock(&mutex);
	for (int i = 0; i < 1; ++i)
	    printf("%d => %s, i=%d. tid=%ld\n", ++_old, str, i, pthread_self());
	//pthread_mutex_unlock(&mutex);
}

//另一个线程测试函数
static  void _doc(void* arg)
{
    //pthread_mutex_lock(&mutex);
	printf("p = %d, tid=%ld.The turorial begins with an introduction to concepts.\n", ++_old, pthread_self());
	//pthread_mutex_unlock(&mutex);
}

// 测试开启线程量集
#define _INT_THS (100000)
#define _S_L_E (_INT_THS / 30000 * 5)
int main(void)
{    
    int i;
    //创建线程池
    threadpool_t pool = sp_NEW();
    
    //添加任务到线程池中
    for(i=0; i<_INT_THS; ++i){
        sp_ADD(pool, _ppt, "POSIX THREADS PROGRAMMING");
        sp_ADD(pool, _doc, NULL);
    }
    
    //等待5s 再结束吧
    SLEEPMS(_S_L_E);
    //清除当前线程池资源, 实战上线程池是常驻内存,不要清除.
    sp_del(&pool);
    return 0;
}