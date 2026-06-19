#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,k;
ll t[300005],a[300005];
priority_queue<ll>pq;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>t[i]>>a[i];
    ll ans=-4e18;
    ll sum=0;
    for(ll i=n;i>=1;i--){
        if(k<0)break;
        if(pq.size()>k){
            sum+=pq.top();
            pq.pop();
        }
        if(t[i]==1){
            ans=max(ans,sum+a[i]);
            k--;
        }
        else{
            if(a[i]>0){
                sum+=a[i];
            }else{
                pq.push(a[i]);
            }
        }
    }
    if(pq.size()>k){
        sum+=pq.top();
        pq.pop();
    }
    ans=max(ans,sum);
    cout<<ans;
    return 0;
}