#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll h,w,K;
bool t[505][505];
ll sum[505][505];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>h>>w>>K;
    for(ll i=1;i<=h;i++){
        string s;
        cin>>s;
        for(ll j=1;j<=w;j++){
            t[i][j]=s[j-1]-'0';
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t[i][j];
        }
    }
    
    ll cnt=0;
    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            for(ll k=i;k<=h;k++){ 
                ll l=j, r=w;
                while(l<r){
                    ll mid=(l+r)/2;
                    if(sum[k][mid]-sum[i-1][mid]-sum[k][j-1]+sum[i-1][j-1]<K){
                        l=mid+1;
                    }else{
                        r=mid;
                    }
                }
                ll t=l;
                if(sum[k][t]-sum[i-1][t]-sum[k][j-1]+sum[i-1][j-1]>K){
                    continue;
                }
                l=t,r=w;
                while(l<r){
                    ll mid=(l+r+1)/2;
                    if(sum[k][mid]-sum[i-1][mid]-sum[k][j-1]+sum[i-1][j-1]<=K){
                        l=mid;
                    }else{
                        r=mid-1;
                    }
                }
                if(sum[k][l]-sum[i-1][l]-sum[k][j-1]+sum[i-1][j-1]==K){
                    cnt+=l-t+1;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}