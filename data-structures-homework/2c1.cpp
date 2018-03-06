# include <iostream>
# include <cstdio>
using namespace std;
const int maxN=1000005;
int m, p, q, sum = 0, root = 0;
int ll[maxN];
int rr[maxN];
int key[maxN];
int num[maxN];
int size[maxN];

inline void ll_Rotate( int &t )
{
    int k = rr[t] ;
    rr[t] = ll[k] ;
    ll[k] = t ;
    size[k] = size[t] ;
    size[t] = size[ll[t]] + size[rr[t]] + 1 ;
    t = k;
}

inline void rr_Rotate( int &t )
{
    int k = ll[t] ;
    ll[t] = rr[k] ;
    rr[k] = t ;
    size[k] = size[t] ;
    size[t] = size[ll[t]] + size[rr[t]] + 1;
    t = k;
}

inline void Maintain( int &t , bool flag )
{
    if ( ! flag ) {
        if ( size[ll[ll[t]]] > size[rr[t]] ) rr_Rotate(t) ;
        else if ( size[rr[ll[t]]] > size[rr[t]] ) {
            ll_Rotate( ll[t] ) ;
            rr_Rotate( t ) ;
        } else return ;
    } else {
        if ( size[rr[rr[t]]] > size[ll[t]] ) ll_Rotate(t) ;
        else if ( size[ll[rr[t]]] > size[ll[t]] ) {
            rr_Rotate( rr[t] ) ;
            ll_Rotate( t );
        } else return;
    }
    Maintain( ll[t] , false ) ;
    Maintain( rr[t] , true ) ;
    Maintain( t , false ) ;
    Maintain( t , true ) ;
}

inline void Insert( int &t , int p , int q )
{
    if ( t == 0 ){
        t = ++sum ;
        key[t] = q ; num [t] = p ; size [t] = 1 ;
        ll[t] = 0 ; rr[t] = 0 ; return ;
    }
    ++size[t] ;
    if ( q < key[t] ) Insert( ll[t] , p , q ) ;
    else Insert( rr[t] , p , q );
    Maintain( t , q >= key[t] ) ;
}

inline void Get_Max( int &t )
{
    if ( rr[t] == 0 ) {
        --size[t]; printf( "%d\n", num[t] );
        t = ll[t] ; return ;
    }
    --size[t] ;
    Get_Max( rr[t] ) ;
    Maintain( t , false );
}

inline void Get_Min( int &t )
{
    if (ll[t] == 0 ) {
        --size[t] ; printf( "%d\n" , num[t] );
        t = rr[t] ; return ;
    }
    --size[t];
    Get_Min( ll[t] ) ;
    Maintain( t , true );
}

int main()
{
    scanf( "%d" , &m );
    while (m != 0 ) {
        if ( m == 1 ) {
            scanf( "%d%d", &p , &q );
            Insert( root , p , q );
        } else if ( m == 2) Get_Max( root ) ;
        else Get_Min( root ) ;
        scanf( "%d", &m );
    }
    return 0;
}
