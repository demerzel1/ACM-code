vector<ll>num;
int getid(ll x){
    return 1+distance(num.begin(),lower_bound(num.begin(),num.end(),x));
}
 sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()),num.end());