#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll h,w;
string s[1000005];
vector<ll>a[1000005];
queue<pair<ll,ll> >q;
ll dx[]={0,-1,-1,-1,0,0,1,1,1};
ll dy[]={0,-1,0,1,-1,1,-1,0,1};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>h>>w;
    for(ll i=1;i<=h;i++){
        cin>>s[i];
        s[i]=" "+s[i];
        a[i].resize(w+5,1e18+1);
    }
    bool f=true,f1=true;
    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            if(s[i][j]=='#'){
                a[i][j]=0;
                q.push({i,j});
                f1=false;
            }
            else{
                f=false;
            }
        }
    }
    if(f||f1){
        for(ll i=1;i<=h;i++){
            for(ll j=1;j<=w;j++){
                cout<<".";
            }
            cout<<"\n";
        }
        return 0;
    }
    //cerr<<"============\n";
    while(!q.empty()){
        ll x=q.front().first,y=q.front().second;
        q.pop();
        //cerr<<"????????????\n";
        for(ll i=1;i<=8;i++){
            ll nx=x+dx[i],ny=y+dy[i];
            if(nx>=1&&nx<=h&&ny>=1&&ny<=w&&a[nx][ny]>a[x][y]+1){
                a[nx][ny]=a[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            if(a[i][j]==1) cout<<'#';
            else cout<<'.';
        }
        cout<<'\n';
    }
    
    return 0;
}




