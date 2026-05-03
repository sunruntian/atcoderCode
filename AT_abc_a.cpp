#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll a[4][7];
    double t[4][4];
    for(ll i=1;i<=3;i++){
        ll cnt4=0,cnt5=0,cnt6=0;
        for(ll j=1;j<=6;j++){
            cin>>a[i][j];
            if(a[i][j]==4)cnt4++;
            if(a[i][j]==5)cnt5++;
            if(a[i][j]==6)cnt6++;
        }
        t[i][1]=cnt4/6.0;
        t[i][2]=cnt5/6.0;
        t[i][3]=cnt6/6.0;
    }
    ll p[6][3]={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
    double ans=0;
    for(ll k=0;k<6;k++){
        double tt=1;
        for(ll i=1;i<=3;i++)tt*=t[i][p[k][i-1]];
        ans+=tt;
    }
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}