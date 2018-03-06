 #include<iostream>
 #include<cstdio>
 #include<cstring>
 using namespace std;
int n;
char qx[100];
char zx[100];

void rec(int ql,int qr,int zl,int zr,int root){
    if(ql>qr)
        return;
  //  root=zl;
    for(root=zl;zx[root]!=qx[ql];++root);
        rec(ql+1,ql+root-zl,zl,root-1,0);
        rec(ql+root-zl+1,qr,root+1,zr,0);
        if((zx[root]>=65&&zx[root]<=90)||(zx[root]>=97&&zx[root]<=122)){
            cout<<zx[root];
        }

     //   cout<<"ÎÒÔÚÊä³ö";
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int N;
        cin>>N;
       // getchar();
       cin>>qx>>zx;
    //  cout<<qx<<"a"<<endl;
   //   cout<<zx<<"a"<<endl;
        rec(0,N,0,N,0);
 //    cout<<N;
        cout<<endl;
    }
    return 0;
}

