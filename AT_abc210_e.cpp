#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m;
struct node{
    ll a,c;
};
node e[100005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;i++)cin>>e[i].a>>e[i].c;
    sort(e+1,e+m+1,[](node x,node y){
        return x.c<y.c;
    });
    ll cnt=n;
    ll ans=0;
    for(ll i=1;i<=m;i++){
        if(cnt==1)break;
        ll t=__gcd(cnt,e[i].a);
        ll tt=cnt-t;
        ans+=tt*e[i].c;
        cnt=t;
    }
    if(cnt!=1)cout<<"-1\n";
    else cout<<ans<<'\n';
    return 0;
}