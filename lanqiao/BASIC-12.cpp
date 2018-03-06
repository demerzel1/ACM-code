#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int hex_to_dec ( char in ) {
    if ( ( in >= '0' ) && ( in <= '9' ) )        return int ( in - '0' );
    else        return int ( in - 'A' ) + 10;
}
char bin_to_oct ( char a, char b, char c ) {
    int aa = int ( a - '0' );
    int bb = int ( b - '0' );
    int cc = int ( c - '0' );
    int goal = 4 * aa + 2 * bb + cc;
    return char ( goal + '0' );
}
void output ( char* in ) {
    char via[400000];
    char out[133334];
    int lenin = strlen ( in );
    int lenvia = lenin * 4;
    int lenout = ( lenvia - 1 ) / 3 + 1;
    int rmd = lenvia % 3;
    for ( int i = 0; i < lenin; i++ )    {
        int begin = hex_to_dec ( in[i] );
        via[i * 4 + 3] = begin % 2 + '0';
        begin = begin / 2;
        via[i * 4 + 2] = begin % 2 + '0';
        begin = begin / 2;
        via[i * 4 + 1] = begin % 2 + '0';
        begin = begin / 2;
        via[i * 4] = begin + '0';
    }
    for ( int i = lenout - 1; i > 0; i-- )    {
        int begin = lenvia - lenout * 3 + i * 3 + 2;
        out[i] = bin_to_oct ( via[begin - 2], via[begin - 1], via[begin] );
    }
    if ( rmd == 0 )        out[0] = bin_to_oct ( via[0], via[1], via[2] );
    if ( rmd == 1 )        out[0] = bin_to_oct ( '0', '0', via[0] );
    if ( rmd == 2 )        out[0] = bin_to_oct ( '0', via[0], via[1] );
    int j = 0;
    for ( j = 0; j < lenout; j++ )    {
        if ( out[j] != '0' )            break;
    }
    for ( ; j < lenout; j++ )        cout << out[j];
    cout << endl;
}
int main () {
    int n;
    cin >> n;
    char in[10][100000];
    for ( int i = 0; i < n; i++ )        cin >> in[i];
    for ( int i = 0; i < n; i++ )        output ( in[i] );
    system ( "pause" );
    return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//int myans[20];
//int main(){
//    int n;
//    cin>>n;
//    string s;
//    long long ans=0;
//    while(n--){
//        memset(myans,0,sizeof(myans));
//        cin>>s;
//        int l=s.length();
//        int p=1;
//        for(int i=l-1;i>=0;i--){
//            if(s[i]>='A'&&s[i]<='F'){
//                ans+=(s[i]-'A'+10)*p;
//            }else{
//                ans+=(s[i]-'0')*p;
//            }
//            p*=16;
//        }
//   //     cout<<ans<<endl;
//        p=8;
//        int pos=0;
//        while(ans>=p/8){
//            myans[pos]=(ans%p)/(p/8);
//            ans-=myans[pos]*(p/8);
//       //     cout<<p<<" "<<myans[pos]<<" "<<ans<<endl;
//            pos++;
//            p*=8;
//        }
//        for(int i=pos-1;i>=0;i--)
//            printf("%d",myans[i]);
//    }
//    return 0;
//}
