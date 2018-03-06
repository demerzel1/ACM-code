#include<bits/stdc++.h>
using namespace std;
#define Max 100000
bool prime[Max];
void IsPrime() {
    prime[0] = prime[1] = 0;
    prime[2] = 1;
    for ( int i = 3; i < Max; i++ )
        prime[i] = i % 2 == 0 ? 0 : 1;
    int t = ( int ) sqrt ( Max * 1.0 );
    for ( int i = 3; i <= t; i++ )
        if ( prime[i] )
            for ( int j = i * i; j < Max; j += 2 * i ) //ÓÅ»¯
                prime[j] = 0;
}
int main() {
    IsPrime();
    int a, b;
    scanf ( "%d%d", &a, &b );
    for ( int i = a; i <= b; i++ ) {
        printf ( "%d=", i );
        int x = i;
        int pos = 2;
        bool f = false;
        while ( x > 1 ) {
            if ( !f ) {
                if ( x % pos == 0 ) {
                    f=true;
                    printf("%d",pos);
                    x=x/pos;
                }else{
                    pos++;
                    while(!prime[pos]) pos++;
                }
           //     printf("pos%d",pos);
            }else{
                if ( x % pos == 0 ) {
                    printf("*%d",pos);
                    x=x/pos;
                }else{
                    pos++;
                    while(!prime[pos]) pos++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
