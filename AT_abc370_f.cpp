#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,k,a[400005],nxt[400005],bz[25][400005],m;
void initX(ll x){
    memset(nxt,0x3f,sizeof nxt);
    ll r=1;
    ll s=0;
    for(ll l=1;l<=m-1;l++){
        while(r<=m-1&&s<x){
            s+=a[r];
            r++;
        }
        if(s>=x){
            nxt[l]=r;
        }else{
            nxt[l]=nxt[0];
        }
        s-=a[l];
    }
}
void initBZ(){
    for(ll i=1;i<=m;i++){
        bz[0][i]=nxt[i];
    }
    for(ll i=1;i<=20;i++){
        for(ll j=1;j<=m;j++){
            ll t=bz[i-1][j];
            if(t>m){
                bz[i][j]=nxt[0];
            }else{
                bz[i][j]=bz[i-1][t];
            }
        }
    }
}
ll jp(ll s){
    ll t=s;
    for(ll i=20;i>=0;i--){
        if(k>>i&1){
            t=bz[i][t];
            if(t>m){
                return nxt[0];
            }
        }
    }
    return t;
}
ll ans(ll x){
    initX(x);
    initBZ();
    ll ret=0;
    for(ll cnt=1;cnt<=n;cnt++){
        ll t=cnt+1;
        ll tt=jp(t);
        if(tt<=t+n){
            ret++;
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    m=2*n+1;
    ll sum=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        a[i+n]=a[i];
    }
    ll l=0;
    ll r=sum+1;
    while(r-l>1){
        ll mid=(l+r)/2;
        if(ans(mid)>0){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<l<<" "<<n-ans(l);
    return 0;
}
