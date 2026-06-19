#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m,dep[N],l,r,a[N],b[N],t;
vector<ll>g[N];
ll s[N];
void dfs(ll u,ll fa){
	dep[u]=dep[fa]+1;
	for(ll i=0;i<g[u].size();i++){
		ll v=g[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}
int main(){
	cin>>n;
	for(ll i=1;i<n;i++){
		ll u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(ll i=1;i<=n;i++)if(dep[i]>dep[l]) l=i;
	dfs(l,0);
	for(ll i=1;i<=n;i++)if(dep[i]>dep[r]) r=i;
	for(ll i=1;i<=n;i++)a[i]=dep[i]-1;
	t=max(t,dep[r]-1);
	dfs(r,0);
	for(ll i=1;i<=n;i++)a[i]=max(a[i],dep[i]-1);
	
	cin>>m;
	memset(dep,0,sizeof(dep));
	l=r=0;
	for(ll i=0;i<=max(n,m)+1;i++)g[i].clear();
	for(ll i=1;i<m;i++){
		ll u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(ll i=1;i<=m;i++)if(dep[i]>dep[l]) l=i;
	dfs(l,0);
	for(ll i=1;i<=m;i++)if(dep[i]>dep[r]) r=i;
	for(ll i=1;i<=m;i++)b[i]=dep[i]-1;
	t=max(t,dep[r]-1);
	dfs(r,0);
	for(ll i=1;i<=m;i++)b[i]=max(b[i],dep[i]-1);
	sort(b+1,b+1+m);
	for(ll i=1;i<=m;i++)s[i]=s[i-1]+b[i];
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll pos=lower_bound(b+1,b+1+m,t-a[i])-b;
		ans+=t*(pos-1)+(m-pos+1)*(a[i]+1)+s[m]-s[pos-1];
	}
	cout<<ans;
	return 0;
}
