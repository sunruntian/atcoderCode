#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
unordered_map<ull,ull>mp;
mt19937_64 rng(time(0));
uniform_int_distribution<ull>rnd(1ull,1000000000000000000ull);
ll a[200005],b[200005],cnta[200005],cntb[200005],xora[200005],xorb[200005];
ull get(ull x){
    if(mp.find(x)==mp.end()){
        mp[x]=rnd(rng);
    }
    return mp[x];
}
set<ull>sta,stb;
ll n,q;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)cin>>b[i];
    ll ta=0,tb=0;
    for(ll i=1;i<=n;i++){
        if(sta.find(a[i])==sta.end()){
            ta^=get(a[i]);
            sta.insert(a[i]);
        }
        cnta[i]=sta.size();
        xora[i]=ta;
        if(stb.find(b[i])==stb.end()){
            tb^=get(b[i]);
            stb.insert(b[i]);
        }
        xorb[i]=tb;
        cntb[i]=stb.size();
    }
    cin>>q;
    while(q--){
        ll x,y;
        cin>>x>>y;
        if(xora[x]==xorb[y]&&cnta[x]==cntb[y]){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}