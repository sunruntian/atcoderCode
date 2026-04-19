#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a,b;vector<pair<ll,ll>>p;
void add(ll i,ll j){
    if(i==a&&j==b)return;
    p.push_back({i,j});
}
void solve(){
    
    cin>>n>>a>>b;
    if((n&1)&&((a+b)&1)==0){
        cout<<"No"<<'\n';
        return;
    }
    p.clear();
    for(ll i=1;i<=n;i++){
        if(i&1==0)
            for(ll j=n;j>0;j--)
                add(i,j);
        else 
            for(ll j=1;j<=n;j++)
                add(i,j);
    }
    cout<<"Yes\n";
    for(ll i=1;i<p.size();i++){
        auto [x,y]=p[i];
        auto [px,py]=p[i-1];
        if(x-px==1)
            cout<<"D";
        else if(x-px==-1)
            cout<<"U";
        else if(y-py==1)
            cout<<"R";
        else if(y-py==-1)
            cout<<"L";
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll T;
    cin>>T;
    while(T--)solve();
    return 0;
}