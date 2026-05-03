#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    ll dp[3]={0},ans=0;
    ll n=s.size();
    s=" "+s;
    for(ll i=1;i<=n;i++){
        ll x=s[i]-'a';
        ll t=ans+1;
        t%=998244353;
        ans=(ans*2-dp[x]+1)%998244353;
        dp[x]=t;
        ans=(ans+998244353)%998244353;
    }
    cout<<ans;
    return 0;
}
