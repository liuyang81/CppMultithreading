#include <iostream>                // std::cout
#include <future>                // std::async, std::future, std::launch
#include <chrono>                // std::chrono::milliseconds
#include <thread>                // std::this_thread::sleep_for

void
do_print_ten(char c, int ms)
{
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        std::cout << c;
    }
}

int
main()
{
    /*
    * https://www.cnblogs.com/haippy/p/3280643.html
    * launch::async	Asynchronous: 异步任务会在另外一个线程中调用，并通过共享状态返回异步任务的结果（一般是调用 std::future::get() 获取异步任务的结果）。
    * launch::deferred	Deferred: 异步任务将会在共享状态被访问时调用，相当与按需调用（即延迟(deferred)调用）。
    */
    std::cout << "with launch::async:\n";
    std::future < void >foo =
        std::async(std::launch::async, do_print_ten, '*', 100);
    std::future < void >bar =
        std::async(std::launch::async, do_print_ten, '@', 200);
    // async "get" (wait for foo and bar to be ready):
    foo.get();
    bar.get();
    std::cout << "\n\n";

    std::cout << "with launch::deferred:\n";
    foo = std::async(std::launch::deferred, do_print_ten, '*', 100);
    bar = std::async(std::launch::deferred, do_print_ten, '@', 200);
    // deferred "get" (perform the actual calls):
    foo.get();
    bar.get();
    std::cout << '\n';

    return 0;
}