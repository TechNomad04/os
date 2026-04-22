#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
mutex mtx;

void increment() {
    int i;
    for(i = 0; i < 5; i++) {
        mtx.lock();
        counter++;
        cout << "inc: " << counter << endl;
        mtx.unlock();
    }
}

void decrement() {
    int i;
    for(i = 0; i < 5; i++) {
        mtx.lock();
        counter--;
        cout << "dec: " << counter << endl;
        mtx.unlock();
    }
}

int main() {
    thread t1(increment);
    thread t2(decrement);

    t1.join();
    t2.join();
}