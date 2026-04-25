#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,c[300005],p[300005];
struct Node{
    ll prev,next;
};
ll head[300005];
Node node[300005];
bool ishead[300005];
int main(){
    cin>>n>>q;
    for(ll i=1;i<=q;i++)cin>>c[i]>>p[i];
    for(ll i=1;i<=n;i++){
        node[i].prev=node[i].next=-1;
        head[i]=i;
        ishead[i]=true;
    }
    for(ll i=1;i<=q;i++){
        if(ishead[c[i]]){
            ishead[c[i]]=false;
            head[c[i]]=-1;
        }
        else node[node[c[i]].prev].next=-1;
        node[c[i]].prev=p[i];
        node[p[i]].next=c[i];
    }
    for(ll i=1;i<=n;i++){
        ll ans=0;
        for(ll j=head[i];j!=-1;j=node[j].next){
            ans++;
        }
        cout<<ans<<" ";
    }
}