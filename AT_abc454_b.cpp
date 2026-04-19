#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll f[105];
set<ll>s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>f[i];
        s.insert(f[i]);
    }
    if(s.size()<n){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
    }
    ll flag=0;
    for(ll i=1;i<=m;i++){
        if(0==s.count(i)){
            flag=1;
        }
    }
    if(flag){
        cout<<"No";
    }else{
        cout<<"Yes";
    }
    return 0;
}