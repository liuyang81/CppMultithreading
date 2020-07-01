#include <iostream>       // std::cout
#include <future>         // std::async, std::future, std::shared_future

int do_get_value() { return 10; }

int main ()
{
    // https://www.cnblogs.com/haippy/p/3280643.html
    std::future<int> fut = std::async(do_get_value);
    /*
    * 返回一个 std::shared_future 对象，调用该函数之后，
    * 该 std::future 对象本身已经不和任何共享状态相关联，因此该 std::future 的状态不再是 valid 的了。
    */
    std::shared_future<int> shared_fut = fut.share();

    // 共享的 future 对象可以被多次访问.
    std::cout << "value: " << shared_fut.get() << '\n';
    std::cout << "its double: " << shared_fut.get()*2 << '\n';

    return 0;
}