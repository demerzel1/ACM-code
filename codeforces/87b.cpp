#include<bits/stdc++.h>
using namespace std;
#define INF 100000
map<string,int> mymap;

int main() {
    int n;
    scanf("%d",&n);
    string op,a,b;
    while(n--) {
        cin>>op;
        if(op=="typedef") {
            cin>>a>>b;
            int la=a.length();
            int cnt1=0,cnt2=0;
            for(int i=0; a[i]=='&'; i++)     cnt1++;
            for(int i=0; i<la; i++) {
                if(a[i]=='*')
                    cnt2++;
            }
            string x=a.substr(cnt1,la-cnt2-cnt1);
            if(x=="void") {
                mymap[b]=cnt2-cnt1;
                if(mymap[b]<0)
                    mymap[b]=-INF;
            }
                   else {
              //  cout<<x<<endl;
                if(mymap.count(x)==0&&x!="void")
                    mymap[b]=-INF;
                else{
                    if(mymap[x]==-INF)
                        mymap[b]=-INF;
                    else {
                        mymap[b]=mymap[x]+cnt2-cnt1;
                        if(mymap[b]<0)
                            mymap[b]=-INF;
                    }
                }
            }
        } else if(op=="typeof") {
            string x;
            cin>>x;

            int la=x.length();
            int cnt1=0,cnt2=0;
            for(int i=0; x[i]=='&'; i++)     cnt1++;
            for(int i=0; i<la; i++) {
                if(x[i]=='*')
                    cnt2++;
            }
            string S=x.substr(cnt1,la-cnt2-cnt1);
          //  cout<<S<<endl;

         //   printf("%d",mymap.count(S));

            if(mymap.count(S)==0&&S!="void")
                printf("errtype\n");
            else{
                int ans=mymap[S]+cnt2-cnt1;
                if(ans<0)
                    ans=-INF;
                if(ans==-INF)
                    printf("errtype\n");
                else {
                    printf("void");
                    int num=ans;
                    for(int i=0; i<num; i++)
                        putchar('*');
                    printf("\n");
                }
            }
        }
    }

    return 0;
}
