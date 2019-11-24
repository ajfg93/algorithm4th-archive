/*
    有bug，在SO上悬而未决的问题，令人头疼
    更新：解决了。。我为什么会让consumer sleep for 5s 啊。。我的天。这样的话producer都可能已经写满整个circular_array了。
    
    rachet 教我的，但看不太懂：
    put a mutex around advancing head and tail
    at that point you can make the decision of whether to wait for the other when the buffer is empty/full

    更新：还是有点问题，初始填充的数据量，consumer是否wait，还有ring buffer的大小好像都会影响结果，不知道怎样才能写一个很好的例子
        感觉还是得在有cv.wait的前提下再实现异步，现在的这个程序，感觉太不可靠了

*/

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <fstream>
#include <sstream>
#include "circular_array.h"
using namespace ythlearn;
using namespace std;

int p_count = 0;
int c_count = 0;
int fileSize = 0;
ostringstream p_os, c_os;

void producer(CircularArray<int>* Ca, vector<int> &data){
    for(int i = 0; i < 5; i++){
        p_os << data.back() << " ";
        Ca->push_right(data.back());
        data.pop_back();
        p_count++;
    }
    while(!data.empty()){
        this_thread::sleep_for(chrono::seconds(1));    
        p_os << data.back() << " ";
        Ca->push_right(data.back());
        data.pop_back();
        p_count++;
    }
    
}

void consumer(CircularArray<int>* Ca){
    // this_thread::sleep_for(chrono::seconds(5));
    cout << "********************" << endl;
    cout << "Consumer start working" << endl;
    while(c_count < fileSize){
        this_thread::sleep_for(chrono::seconds(1));    
        int re = Ca->pop_left();
        cout << re << endl;
        c_os << re << " ";
        c_count++;
    
    }
    cout << "Consumer done" << endl;
    cout << "********************" << endl;
    
}


void getInput(vector<int>& data){
    ifstream ifs("test.txt");
    int j;
    while(ifs >> j){
        data.push_back(j);
    }
}

int main(){
    cout << unitbuf;
    vector<int> data;
    getInput(data);

    CircularArray<int> Ca;

    ::fileSize = data.size();
    cout << "data size: " << ::fileSize << endl;
    for(const auto& s: data){
        cout << s << " ";
    }
    cout << endl;


    thread th_producer(producer, &Ca, std::ref(data));
    thread th_consumer(consumer, &Ca);

    th_consumer.join();
    th_producer.join();
    cout << "p_count: " << p_count << endl
         << "c_count: " << c_count << endl;
    cout << "P ostream: " << p_os.str() << endl;
    cout << "C ostream: " << c_os.str() << endl;
    return 0;
}