#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll x[200005],d[200005];
struct Node{
    ll x,d;
}a[200005];
ll r[200005];
ll f[200005];
bool cmp(Node u,Node v){
    return u.x<v.x;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].x>>a[i].d;
    }
    sort(a+1,a+n+1,cmp);
    for(ll i=1;i<=n;i++){
        x[i]=a[i].x;
        d[i]=a[i].d;
    }
    stack<ll>sta;
    for(ll i=n;i>=1;i--){
        r[i]=i;
        while(!sta.empty()&&x[sta.top()]<x[i]+d[i]){
            r[i]=max(r[i],r[sta.top()]);
            sta.pop();
        }
        sta.push(i);
    }
    f[n+1]=1;
    for(ll i=n;i>=1;i--){
        f[i]+=(f[i+1]+f[r[i]+1])%998244353;
    }
    cout<<f[1];
    return 0;
}