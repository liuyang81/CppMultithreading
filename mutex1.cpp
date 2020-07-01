#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

volatile int counter(0); // non-atomic counter
std::mutex mtx;           // locks access to counter

void attempt_10k_increases() {
    for (int i=0; i<100; ++i) {
        if (mtx.try_lock()) {   // only increase if currently not locked:
            ++counter;
            std::cout << "thread id: " << std::this_thread::get_id() << " current counter: " << counter << '\n';
            mtx.unlock();
        }
    }
}

int main (int argc, const char* argv[]) {
    //https://www.cnblogs.com/haippy/p/3237213.html
    std::thread threads[10];
    for (int i=0; i<10; ++i)
        threads[i] = std::thread(attempt_10k_increases);

    for (auto& th : threads) th.join();
    std::cout << counter << " successful increases of the counter.\n";

    return 0;
}