#include <iostream>
#include <thread> // 多线程头文件

void Hello() {
  std::cout << "Hello, World!" << std::endl;
  //system("pause");
}

int main() {
  //https://www.cnblogs.com/haippy/p/3235560.html
  // 创建一个线程对象，注意函数 Hello 将立即运行。
  std::thread t(&Hello);

  // 等待线程结束。
  // 否则线程还没执行（完），主程序就已经结束了。
  t.join();
  
  std::cout << "This is over!" << std::endl;
  system("pause");
  return 0;
}