#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,q;
ll dfn[300005];
ll siz[300005];
pair<ll,ll>e[300005];
ll p[300005];
ll bit[300005];
ll step;
vector<ll>g[300005];
ll lowbit(ll x){
    return x&(-x);
}
void dfs(ll u,ll fa){
    siz[u]=1;
    p[u]=fa;
    dfn[u]=++step;
    for(auto &v:g[u]){
        if(v==fa)continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
void add(ll x,ll k){
    for(ll i=x;i<=n;i+=lowbit(i)){
        bit[i]+=k;
    }
}
ll sum(ll x){
    ll res=0;
    for(ll i=x;i>0;i-=lowbit(i)){
        res+=bit[i];
    }
    return res;
}
ll query(ll l,ll r){
    return sum(r)-sum(l-1);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<n;i++){
        cin>>e[i].first>>e[i].second;
            g[e[i].first].push_back(e[i].second);
            g[e[i].second].push_back(e[i].first);
    }
    dfs(1,0);
    ll tot=n;
    for(ll i=1;i<=n;i++){
        add(dfn[i],1);
    }

    cin>>q;
    while(q--){
        ll opt;
        cin>>opt;
        if(opt==1){
            ll x,w;
            cin>>x>>w;
            add(dfn[x],w);
            tot+=w;
        }else{
            ll y;
            cin>>y;
            auto [u,v]=e[y];
            ll ch;
            if(p[u]==v){
                ch=u;
            }else{
                ch=v;
            }
            ll l=dfn[ch],r=dfn[ch]+siz[ch]-1;
            cout<<llabs(tot-2*query(l,r))<<"\n";
        }
    }
    return 0;
}