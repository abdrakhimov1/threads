#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

std::mutex my_mutex;

void increment(int* numb){
    for(short int i = 0; i < 10000; i++){
        my_mutex.lock();

        (*numb)++;

        my_mutex.unlock();


    }
}



int main() {

    int numb = 0;





    std::thread t1 (increment, &numb) ;
    std::thread t2 (increment, &numb);

    t1.join();
    t2.join();

    std::cout << numb << std::endl;

    return 0;
}