#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,L,q,val[100005],dp[100005][20],lg[20];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>val[i];
	cin>>L;
	lg[0]=1;
	for(ll i=1;i<=16;i++)lg[i]=lg[i-1]<<1;
	ll t=1;
	for(ll i=1;i<=n;i++){
		while(t<n&&val[t+1]-val[i]<=L)t++;
		dp[i][0]=t;
	}
	for(ll k=1;k<=16;k++)
		for(ll i=1;i<=n;i++)
			dp[i][k]=dp[dp[i][k-1]][k-1];
	cin>>q;
	while(q--){
		ll l,r;cin>>l>>r;
		if(l>r)swap(l,r);
		ll ans=0;
		for(ll i=16;i>=0;i--)
			if(dp[l][i]<r)l=dp[l][i],ans+=lg[i];
		cout<<ans+1<<'\n';
	}
	return 0;
}