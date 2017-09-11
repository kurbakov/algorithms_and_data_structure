#include <iostream>
#include <queue>                // std::queue
#include <mutex>                // std::mutex
#include <condition_variable>   // std::condition_variable


// class Queue
template <class T>
class ThreadSafeQueue{
private:
    std::queue<T> data;
    std::mutex data_mutex;
    std::condition_variable data_condition;

public:
    ThreadSafeQueue();
    ~ThreadSafeQueue();

    void qpush(T);
    T qpop();
    bool empty();
};

template <class T>
ThreadSafeQueue<T>::ThreadSafeQueue(){}

template <class T>
ThreadSafeQueue<T>::~ThreadSafeQueue(){}

template <class T>
void ThreadSafeQueue<T>::qpush(T v){
    std::unique_lock<std::mutex> lock(data_mutex);
    data.push(v);
    data_condition.notify_one();
}

template <class T>
T ThreadSafeQueue<T>::qpop(){
    std::unique_lock<std::mutex> lock(data_mutex);
    data_condition.wait(lock, [=](){return !data.empty();});
    
    T res = data.front();
    data.pop();
    return res;
}

template<class T>
bool ThreadSafeQueue<T>::empty(){
    std::unique_lock<std::mutex> lock(data_mutex);
    return data.empty();
}

void print(int x){
    std::cout << "hello " << x << "\n";
}

int main(){
    ThreadSafeQueue<std::function<void(int)> > q;
    q.qpush(print);
    q.qpush(print);
    q.qpush(print);
    q.qpush(print);

    int counter=0;
    while(!q.empty()){
        auto f = q.qpop();
        f(counter);
        counter++;
    }

    return 0;
}
