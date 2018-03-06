#include <ext/rope>
using namespace __gnu_cxx;

主要函数
pop_front() push_pront()
pop_back() push_back()
front() back()
void copy(charT* buf) 				复制rope中所有内容到字符串buf
void erase(size_t i, size_t n)		从i开始删除n个

把从i开始的n个元素换成字符串s
void replace(size_t i, size_t n, const charT* s) 
void replace(size_t i, charT c)		把第i个元素换成c
void insert(size_t i, charT c)		在第i位插入c
void insert(size_t i, const charT* s)在第i位插入字符串s
rope substr(iterator f, iterator l)  得到[f,l)的子串

【实现可持久化(O(1)记录历史版本】
rope<char> *rp[MAXN];
rp[i]=new rope<char>(*rp[i-1]);
就可以实现可持久化了，每次new都是O(1)的，只复制了树根