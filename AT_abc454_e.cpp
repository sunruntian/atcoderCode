#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a,b;
string ans;
void solve(){
    cin>>n>>a>>b;
    if(n%2==1||(a+b)%2==0){
        cout<<"No\n";
        return;
    }
    ll flag=false;
    if(a%2==1){
        swap(a,b);
        flag=true;
    }
    cout<<"Yes\n";
    char l,r,d,u;
    if(!flag){
        l='L',r='R',d='D',u='U';
    }
    else{
        l='U',r='D',d='R',u='L';
    }
    for(ll i=1;i<=a-2;i+=2){
        for(ll j=2;j<=n;j++){
            ans+=r;
            //cout<<1<<"\n";
        }
        ans+=d;
        i--;
        for(ll j=2;j<=n;j++){
            ans+=l;
            //cout<<2<<"\n";
        }
        ans+=d;
        i++;
    }
    //ans+=" ";
    for(ll i=1;i<=b-1;i+=2){
        ans+=d;
        ans+=r;
        ans+=u;
        ans+=r;
    }
    //if()
    ans+=r;
    ans+=d;
    for(ll i=b+1;i<n;i+=2){
        
        ans+=r;
        ans+=u;
        ans+=r;
        ans+=d;
    }
    //ans+=" ";
    for(ll i=a+1;i<n;i++){
        if(i==a+1){
            ans+=d;
        }
        if(i%2==1){
            for(ll j=2;j<=n;j++){
                ans+=l;
            }
            ans+=d;
        }else{
            for(ll j=2;j<=n;j++){
                ans+=r;
            }
            ans+=d;
        }
    }
    for(ll i=2;i<=(n-a==0?0:n);i++){
        ans+=r;
    }
    cout<<ans<<"\n";
    ans="";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}