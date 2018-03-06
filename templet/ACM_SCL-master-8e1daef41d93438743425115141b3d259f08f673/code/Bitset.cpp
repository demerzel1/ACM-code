typedef unsigned long long ull;
struct Bitset{
    ull o;
    Bitset(){o=0;}
    Bitset(ull _o):o(_o){}
    Bitset(const string& s){
        assert(s.length()<65);
        o=0;for(const auto&x:s){o<<=1;o+=x-'0';}
    }
    ull real(){return o;}
    void set(){o=-1;}//全置为1
    void reset(){o=0;}//全置为0
    void flip(){o^=-1;}//取反
    void set1(uint p){o|=(1<<p);}//把某位设为1
    void set0(uint p){o&=~(1<<p);}//把某位设为0
    bool at(uint p){return (o>>p)&1;}//某位

    int count(){return __builtin_popcountll(o);}//1的个数
    int left0(){return __builtin_clzll(o);}//前导(左)0的个数,o=0时结果未定义
    int right0(){return __builtin_ffsll(o)-1;}//末尾(右)0的个数
    bool parity1(){return __builtin_parityll(o);}//1的奇偶性,1奇0偶
    void flip(uint p){//把某位取反
        if(at(p)) set0(p);
        else      set1(p);
    }
    Bitset &operator^=(Bitset p) {o^=p.o;return *this;}
    Bitset operator^(Bitset p)const{return Bitset(*this)^=p;}
    bool operator[](uint p){return at(p);}
    void write(int p){for(auto i=p-1;i>=0;i--){cout<<at(i);}cout<<'\n';}
};//低位从0开始计数
uint nextbit_permutation(uint o){
    uint t=o|(o-1);
    return (t+1)|(((~t & -~t)-1)>>(__builtin_ctz(o)+1));
}