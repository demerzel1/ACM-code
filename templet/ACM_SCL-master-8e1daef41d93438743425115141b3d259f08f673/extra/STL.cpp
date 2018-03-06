/*priority_queue*/
struct cmp { 
	bool operator ()(int x, int y) { 
		return x > y; // x小的优先级高
	}
};
priority_queue<int, vector<int>, cmp>q;

struct Node {
    int x,y;
	bool operator<(const Node& t)const{
        return y > t.y; //结构体中,y小的优先级高
    }
};
priority_queue<Node>q;
/*priority_queue*/

/*set/map/multiset/multimap*/
struct classcomp{ 
	bool operator()(const int&lhs,const int&rhs)const{
		return lhs>rhs;//从大到小
	}
};
multiset<int,classcomp> fifth; 	// class as Compare 

struct Node{int x,y;};
struct classcomp{
	bool operator()(const Node &a,const Node &b)const{ 
		if(a.x!=b.x)	return a.x<b.x; 
		else return a.y>b.y;
 	} //先按照 x 从小到大排序,x相同则按照y从大到小排序
};
multiset<Node,classcomp>mt; 
multiset<Node,classcomp>::iterator it; 
/*

定义 set 或者 multiset 的时候定义了排序函数,定义迭代器时一样带上排序函数
注意对于 multiset,erase删除值会把等于这个值的都删掉,删除一个要用迭代器
lower_bound() 大于等于某值的第一个元素 
upper_bound() 大于某值的第一个元素 

set/map/multiset/multimap*/

/*unordered_map/unordered_set*/
typedef pair<int,int> ii;
struct myhash{
    template<typename T1,typename T2>
    size_t operator()(const pair<T1, T2>& _tmp)const{
        return hash<T1>()(_tmp.first) ^ hash<T2>()(_tmp.second);
    }
};
unordered_map<ii, int, myhash>mp;