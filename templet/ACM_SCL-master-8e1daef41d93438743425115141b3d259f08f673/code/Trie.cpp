template<char L=' ',char R='~'> struct Trie{
    int size;
    struct node{
        node *son[R-L+1];
        int size;
        bool is;
    }pool[MAXN];
    node *root;
    node* add(){
        memset(&pool[size],NULL,sizeof(node));
        return &pool[size++];
    }
    Trie(){size=0;root=add();}
    pair<node*,int> find(const string& s){
        node *now=root;
        for(const auto&c:s){
            if(!now->son[c-L]){
                return make_pair(root,-1);//不存在
            }
            now=now->son[c-L];
        }
        if(now->is)
            return make_pair(now,1);//存在
        return make_pair(now,0);//只存在前缀
    }
    node* insert(const string& s){
        node *now=root;
        for(const auto&c:s){
            if(!now->son[c-L]){
                now->son[c-L]=add();
            }
            now->size++;now=now->son[c-L];
        }
        now->is=1;now->size++;
        return now;
    }
};