#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
class Bit{
    ll lowbit(ll x){
        return x&-x;
    }
    ll bit[1000005]={0};
    ll n;
    
    public:
        Bit(ll x){
            n=x;
        }
        void add(ll x,ll k){
            for(ll i=x;i<=n;i+=lowbit(i))
                bit[i]+=k;
        }
        ll sum(ll k){
            ll ret=0;
            for(ll i=k;i>0;i-=lowbit(i))
                ret+=bit[i];
            return ret;
        }
        ll query(ll l,ll r){
            return sum(r)-sum(l-1);
        }
};
ll n,m;
ll a[10005][105];
struct Node{
    ll val,i,rank;
};
vector<Node>b;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    Bit bit(n*m);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>a[i][j];
        }
        sort(a[i]+1,a[i]+m+1);
        for(ll j=1;j<=m;j++){
            b.push_back({a[i][j],i,j});
        }
    }
    sort(b.begin(),b.end(),[](Node x,Node y){
        return x.val<y.val;
    });
    ll ans=0;
    for(auto [val,i,rank]:b){
        ans+=rank*(n-i);
        ans+=bit.sum(n)-bit.sum(i);
        bit.add(i,1);
    }
    cout<<ans;
    return 0;
}