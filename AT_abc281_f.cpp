#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[150005];
ll dfs(ll l,ll r,ll bit){
    if(bit<0)return 0;
    if(((a[l]>>bit)&1)==((a[r]>>bit)&1))return dfs(l,r,bit-1);
    ll mid=lower_bound(a+l,a+r+1,(a[l]&~((1ll<<(bit+1))-1))|(1ll<<bit))-a;
    return (1ll<<bit)+min(dfs(l,mid-1,bit-1),dfs(mid,r,bit-1));
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    cout<<dfs(1,n,30)<<endl;
    return 0;
}