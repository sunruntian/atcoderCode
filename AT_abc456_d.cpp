#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<long long, int>,null_type,less<>,rb_tree_tag,tree_order_statistics_node_update>tr;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    ll x,q;
    cin>>x>>q;
    tr t;
    ll id=0;
    t.insert({x,id++});
    for(ll i=1;i<=q;++i) {
        ll a,b;
        cin>>a>>b;
        t.insert({a,id++});
        t.insert({b,id++});
        cout<<t.find_by_order(i)->first<<"\n";
    }
    return 0;
}