#include <iostream>
#include <thread>

void threadFunction()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
  std::cout << "Finished work 1 in thread\n";
  std::cout << "Hello concurrent world from fun! Thread id = "
            << std::this_thread::get_id() << std::endl;

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Finished work 2 in thread\n";
  std::cout << "Hello concurrent world from fun! Thread id = "
            << std::this_thread::get_id() << std::endl;
}

int main()
{
  // create thread
  std::thread t(threadFunction);

  // wait for thread to finish
  t.join();

  // do something in main()
  std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
  std::cout << "Finished work 1 in main\n";
  std::cout << "Hello concurrent world from main! Thread id = "
            << std::this_thread::get_id() << std::endl;

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Finished work 2 in main\n";
  std::cout << "Hello concurrent world from main! Thread id = "
            << std::this_thread::get_id() << std::endl;

  return 0;
}