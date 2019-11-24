/*

    首次填充链表，需要清除重复字符。解决方法是，用vector排序，在链表removeduplicated，因为在vector里remove一项成本感觉高很多。
    读取字符，（检查表，如果有重复，就删除重复），将其插在表头。
    无法使用二分查找： 1. 数据插入后不是有序的
                    2. 二分查找，对于链表，要得到mid的指针，还得遍历，感觉成本比二分算法本身都还高
    这里说的是“字符”，因此链表长度也极其有限，因此查重的话，直接遍历整个表。

*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "doublelinkedlist.h"
using namespace std;
using namespace ythlearn;

int main(){
    istringstream istr("abcddejejdikwjcqqddd333");
    char c;
    vector<char> cvec;
    DLinkList<char> dl;

    while(istr >> c){
        cvec.push_back(c);
    }
    sort(cvec.begin(), cvec.end());
    for(const auto& b: cvec){
        cout << b << " ";
        dl.push_right(b);        
    }
    cout << endl;

    dl.print();
    dl.remove_duplicated_with_ordered();
    dl.print();
    dl.push_left('Q');
    dl.print();
    dl.push_left_check_duplicated('Q').print();

    return 0;
}