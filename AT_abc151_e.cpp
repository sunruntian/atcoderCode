#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD=1e9+7;
ll power(ll a,ll b,ll c){
    ll ret=1;
    a%=c; 
    while(b){
        if(b&1){ 
            ret=(ret*a)%c;
        }
        a=(a*a)%c;
        b>>=1;
    }
    return ret;
}
ll inv(ll a,ll mod){
    return power(a,mod-2,mod);
}
ll fact[100005];
void init(){
    fact[0]=1;
    for(ll i=1;i<100001;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
}
ll C(ll n,ll r,ll mod){
    if(r>n)return 0;
    return (fact[n]*inv(fact[r],mod)%mod)*inv(fact[n-r],mod)%mod;
}
ll n,k;
ll a[100005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    init();
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll smax=0;
    ll smin=0;
    for(ll i=1;i<=n;i++){
        smax=(smax+C(i-1,k-1,MOD)*a[i]%MOD)%MOD;
        smin=(smin+C(n-i,k-1,MOD)*a[i]%MOD)%MOD;
    }
    cout<<(smax-smin+MOD)%MOD<<"\n";

    return 0;
}