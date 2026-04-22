#include <iostream>
#include <thread>

using namespace std;

void task1() {
    cout << "Hello 1"<< endl;
}

void task2() {
    cout << "Hello 2" << endl;;
}

int main() {
    thread t1(task1);
    thread t2(task2);
    t1.join();
    t2.join();
    cout << "Two threads finish execution" << endl;
}