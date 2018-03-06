    #include <iostream>
    #include <queue>
    #include <map>

    using namespace std;


    class edge
    {
    public:

        int point1,point2;
        int value;
        int id;
        edge(int point1,int point2,int value,int id):point1(point1),point2(point2),value(value),id(id)
        {

        }
    };

    bool operator <(const edge &a,const edge &b)
    {
        return a.value>b.value;
    }

    int rela[1005];
    priority_queue<edge>edges;
    vector<edge> edges2;
    map<int,int >sptree;
    map<int,int >::iterator it;

    void initial(int n)
    {
        sptree.clear();
        while(!edges.empty())
        {
            edges.pop();
        }
        for(int i=0;i<=n;i++)
        {
            rela[i]=i;
        }
    }

    int find(int x)
    {
        if(x==rela[x])
        {
            return x;
        }
        else
        {
            rela[x]=find(rela[x]);
            return rela[x];
        }
    }


    int solve(int n,int m)
    {
        int sum=0;
        while(!edges.empty())
        {
            int r1=find(edges.top().point1);
            int r2=find(edges.top().point2);
            if(r1!=r2)
            {
                rela[r1]=r2;
                sum+=edges.top().value;
            }
            edges.pop();
        }
        return sum;
    }

    int main()
    {
        int n,m;
        while(cin>>n>>m)
        {
            initial(n);
            int u,v,c;
            for(int i=0;i<m;i++)
            {
                cin>>u>>v>>c;
                edges.push(edge(u,v,c,i+1));
                edges2.push_back(edge(u,v,c,i+1));
            }

            int sum1=solve(n,m);
            int sum2=0;


            for(int i=0;i<=n;i++)
            {
                rela[i]=i;
            }
            int check;

            int flag=1;
            for(int i=1;i<=n-1;i++)
            {
                cin>>check;
                sum2+=edges2[check-1].value;
                int r1=find(edges2[check-1].point1);
                int r2=find(edges2[check-1].point2);
                if(r1!=r2)
                {
                    rela[r1]=r2;
                }
                else
                {
                    //cout<<"CHECK:"<<check<<endl;
                    flag=0;
                }
            }
            //cout<<sum1<<" "<<sum2<<endl;
            if(sum1!=sum2)
                flag=0;
            if(flag)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        return 0;
    }

