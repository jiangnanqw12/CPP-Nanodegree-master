#include <iostream>
#include <thread>

int main()
{
  unsigned int nCores = std::thread::hardware_concurrency();
  // Returns the number of concurrent threads
  // supported by the implementation.
  // The value should be considered only a hint.
  std::cout << "This machine supports concurrency with " << nCores
            << " cores available" << std::endl;

  return 0;
}