#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m;
ll a[300005],b[300005];
map<ll,set<ll>>mp;
set<ll>ans;
set<ll>t1;
set<ll>t2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        mp[a[i]].insert(b[i]);
    }
    ans.insert(1);
    t1.insert(1);
    do{
        //cout<<1;
        
        t2.clear();
        for(ll x:t1){
            if(mp.count(x)==0){
                t1.erase(x);
                continue;
            }
            for(ll y:mp[x]){
                if(ans.count(y)==0){
                    ans.insert(y);
                    t2.insert(y);
                }
            }
            t1.erase(x);
        }
        t1=t2;
    }while(!t2.empty());
    
    cout<<ans.size();
    return 0;
}
