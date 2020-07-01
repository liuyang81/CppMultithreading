#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
#include <vector>

void disPlay(std::future<int>& value)
{
    std::cout << "wait some times......" << std::endl;
    auto result = value.get();    //没有获取到值会阻塞等待获取
    std::cout << "Value:" << result << std::endl;
}


int main()
{
    /*
    * https://www.cnblogs.com/haippy/p/3239248.html
    * https://www.cnblogs.com/DOMLX/p/10945309.html
    * 1. 线程1初始化一个promise对象和一个future对象，promise传递给线程2，相当于线程2对线程1的一个承诺；future相当于一个接受一个承诺，用来获取未来线程2传递的值。
    * 2. 线程2获取到promise后，需要对这个promise传递有关的数据，之后线程1的future就可以获取数据了。
    * 3. 如果线程1想要获取数据，而线程2未给出数据，则线程1阻塞，直到线程2的数据到达。
    */
    std::promise<int> promise;    
    std::future<int> value = promise.get_future(); //将promise与future绑定
    
    std::thread t1(disPlay, std::ref(value));  //创建线程并且函数传参，ref()是传一个引用
    std::this_thread::sleep_for(std::chrono::seconds(1)); //线程延时1秒

    //给线程传值进去
    promise.set_value(15);
    t1.join();
    
    
    system("pause");

    return 0;
}