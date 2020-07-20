#include <iostream>
#include <thread>
#include <future>

void modifyMessage(std::promise<std::string> &&prms, std::string message)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // simulate work
    std::string modifiedMessage = message + " has been modified";
    prms.set_value(modifiedMessage);
}

int main()
{
    // define message
    std::string messageToThread = "My Message";

    // create promise and future
    std::promise<std::string> prms;
    std::future<std::string> ftr = prms.get_future();

    // start thread and pass promise as argument
    std::thread t(modifyMessage, std::move(prms), messageToThread);

    // print original message to console
    std::cout << "Original message from main(): " << messageToThread << std::endl;

    // retrieve modified message via future and print to console
    std::string messageFromThread = ftr.get();
    std::cout << "Modified message from thread(): " << messageFromThread << std::endl;

    // thread barrier
    t.join();

    std::string messageToThread2 = "test";

    // create promise and future
    std::promise<std::string> prms2;
    std::future<std::string> ftr2 = prms2.get_future();

    std::thread t2(modifyMessage, std::move(prms2), messageToThread2);
    std::cout << "Original message from main(): " << messageToThread2 << std::endl;

    // retrieve modified message via future and print to console
    std::string messageFromThread2 = ftr2.get();
    std::cout << "Modified message from thread(): " << messageFromThread2 << std::endl;
    t2.join();

    return 0;
}
