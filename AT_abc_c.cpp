#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    
    ll n=s.size(),ans=0,dp=1;s=" "+s;
    ans+=dp;
    for(ll i=2;i<=n;i++){
        if(s[i]!=s[i-1])dp=(dp+1)%998244353;
        else dp=1;
        ans=(ans+dp)%998244353;
    }
    cout<<ans<<'\n';
    return 0;
}