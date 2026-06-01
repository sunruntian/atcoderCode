#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,s;
ll a[250005],p[250005],f[250005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>s;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    ll sum=0;
    ll pos=1;
    for(ll i=1;i<=n;i++){
        while(pos<=n&&sum+a[pos]<=s){
            sum+=a[pos];
            pos++;
        }
        p[i]=pos;
        sum-=a[i];
    }
    ll ans=0;
    for(ll i=n;i>=1;i--){
        ll cnt=n-i+1;
        f[i]=cnt+f[p[i]];
        ans+=f[i];
    }
    cout<<ans;
    return 0;
}