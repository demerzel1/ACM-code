#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){
    string codes;
    while(1){
        cin>>codes;
        if(codes[0]=='#')
            break;
        int i;
         int l=codes.length();
      //  cout<<l<<endl;
        for(i=l-1;i>0;i--){
            if(codes[i]>codes[i-1])
                break;
        }
    //   printf("i=%d\n",i);
        if(i==0)
            printf("No Successor\n");
        else{
            int j;
            char m=codes[i];
            int nm=i;
            for(j=i+1;codes[j]!='\0';j++){
                if(codes[j]<m&&codes[j]>codes[i-1]){
                    m=codes[j];
                    nm=j;
                }

            }
      //     printf("m=%c,nm=%d\n",m,nm);
            char sw;
            sw=m;
            codes[nm]=codes[i-1];
            codes[i-1]=sw;
    //        cout<<codes<<endl;
            int mi=i;
            for(;i<l;i++){
          //          printf("i=%d\n",i);
                for(j=mi;j<l-1;j++){
                    if(codes[j]>codes[j+1]){
          //                 printf("j=%d\n",j);
                        sw=codes[j];
                        codes[j]=codes[j+1];
                        codes[j+1]=sw;
              //         cout<<codes<<endl;
                    }
                }

            }
            cout<<codes<<endl;
        }

    }
    return 0;
}
