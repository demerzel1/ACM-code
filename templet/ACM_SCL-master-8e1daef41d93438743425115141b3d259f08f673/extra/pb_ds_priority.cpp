#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
typedef __gnu_pbds::priority_queue<Type,less<Type>,Tag> heap;
/*
第二个参数为比较函数，默认为 less<Type>,大的优先级高
第三个参数是堆的类型，默认为 pairing_heap_tag，配对堆
所占空间为std::priority_queue的3倍左右...

clear() 清空队列
join(priority queue &other) 
把other合并到this，然后other被清空

void modify(point iterator, const reference) 
更改迭代器指向的元素的值

void erase(point iterator)
删除迭代器指向的元素
*/