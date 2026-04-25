#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[200005],dp[200005];
vector<ll> E[200005];
ll dfs(ll u){
    if(dp[u]!=-1e18)return dp[u]; 
    if(E[u].size()==0)return dp[u];
    for(ll &v:E[u]){
        dp[u]=max(dp[u],a[v]);
        dp[u]=max(dfs(v),dp[u]);
    }
    return dp[u];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        E[u].push_back(v);
    }
    for(ll i=1;i<=n;i++)dp[i]=-1e18;
    ll ans=-0x3f3f3f3f3f3f3f3f;
    for(ll i=1;i<=n;i++){
        dfs(i);
        //cout<<dp[i]<<" "<<a[i]<<"\n";
        ans=max(ans,dp[i]-a[i]);
    }
    cout<<ans<<"\n";
    return 0;
}