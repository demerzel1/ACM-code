#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <iomanip>
#define PI acos(-1.0)
#define Max 100005
#define inf 1<<28
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define FOR(i,s,t) for(int i=(s);i<=(t);++i)
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define mp(a,b) make_pair(a,b)
using namespace std;

struct SBT
{
    int left, right ,num , size , priority;
}tree[Max];

void left_rot(int &x)
{
    int y = tree[x].right;
    tree[x].right = tree[y].left;
    tree[y].left = x;
    tree[y].size = tree[x].size;
    tree[x].size = tree[tree[x].left].size + tree[tree[x].right].size + 1;
    x = y;
}

void right_rot(int &x)
{
    int y = tree[x].left;
    tree[x].left = tree[y].right;
    tree[y].right = x;
    tree[y].size = tree[x].size;
    tree[x].size = tree[tree[x].left].size + tree[tree[x].right].size + 1;
    x = y;
}

void maintain(int &x,bool flag)
{
    if(!flag)
    {
        if(tree[tree[tree[x].left].left].size > tree[tree[x].right].size)
        right_rot(x);
        else if(tree[tree[tree[x].left].right].size > tree[tree[x].right].size)
        {
            left_rot(tree[x].left);
            right_rot(x);
        }
        else return ;
    }
    else
    {
        if(tree[tree[tree[x].right].right].size > tree[tree[x].left].size)
        left_rot(x);
        else if(tree[tree[tree[x].right].left].size > tree[tree[x].left].size)
        {
            right_rot(tree[x].right);
            left_rot(x);
        }
        else return ;
    }
    maintain(tree[x].left,0);
    maintain(tree[x].right,1);
    maintain(x,1);
    maintain(x,0);
}
int root , top;
void insert(int &x ,int num ,int priority)
{
    if (x == 0)
    {
        x = ++top;
        tree[x].size = 1;
        tree[x].left = tree[x].right = 0;
        tree[x].num = num ;
        tree[x].priority = priority;
    }
    else
    {
        tree[x].size ++;
        if(priority < tree[x].priority)insert(tree[x].left , num , priority);
        else insert(tree[x].right , num ,priority);
        maintain(root , priority >= tree[x].priority);
    }
}
int del(int &x ,int priority)
{
    int d_priority ;
    if(!x)return 0;
    tree[x].size --;
    if(priority == tree[x].priority || (tree[x].priority >priority && tree[x].left == 0)||(tree[x].priority < priority && tree[x].right == 0))
    {
        d_priority = tree[x].priority;
        if(tree[x].left && tree[x].right )
        {
            tree[x].priority = del(tree[x].left , tree[x].priority + 1);
        }
        else
        x = tree[x].left + tree[x].right ;
    }
    else if(priority > tree[x].priority)
    d_priority = del(tree[x].right, priority );
    else if (priority < tree[x].priority)
    d_priority = del(tree[x].left , priority);
    return d_priority;
}
int get_min()
{
    int x;
    for (x = root ; tree[x].left; x = tree[x].left  );
    printf("%d\n",tree[x].num);
    return tree[x].priority;
}
int get_max()
{
    int x ;
    for (x = root ; tree[x].right ; x = tree[x].right );
    printf("%d\n",tree[x].num);
    return tree[x].priority;
}
int main()
{
    int n ;
    root = top = 0;
    while(scanf("%d",&n)&& n  )
    {
        if( n == 1)
        {
            int a , b ;
            scanf("%d%d",&a,&b);
            insert(root , a, b);
        }
        else if (n == 2)
        {
            if(!root)
            puts("0");
            else{
            int k = get_max();
            del(root ,k);
            }
        }
        else
        {
            if(!root)
            puts("0");
            else{
            int k = get_min();
            del(root ,k);
            }
        }
    }
    return 0;
}
