#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,d;
ll cf[1000005],sum[1000005];
ll st[25][1000005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>d;
    for(ll i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        if(y-d>=x){
            cf[x]+=1;
            cf[y-d+1]-=1;
        }
    }
    for(ll i=1;i<=1000000;i++){
        sum[i]=sum[i-1]+cf[i];
        st[0][i]=sum[i];
    }
    ll ans=0;
    for(ll i=1;i<=1000000-d+1;i++){
        ll k=__lg(d);
        ll q=sum[i];
        if(q>=2){
            ans+=q*(q-1)/2;
        }
    }
    cout<<ans;
    return 0;
}
