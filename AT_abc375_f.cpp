#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,q;
ll dist[305][305];
struct query{
    ll opt;
    ll d;
    ll x,y;
} que[200005];
struct edge{
    ll u,v,w;
}e[50000];
ll d[50000];
ll cnt;
ll ans[200005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>q;
    memset(dist,0x3f,sizeof dist);
    for(ll i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(ll i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(ll i=1;i<=q;i++){
        ll opt;
        cin>>opt;
        que[i].opt=opt;
        if(opt==1){
            que[i].opt=1;
            cin>>que[i].d;
            d[que[i].d]=1;
        }else{
            cin>>que[i].x>>que[i].y;
        }
    }
    for(ll k=1;k<=m;k++){
        if(!d[k]){
            ll u,v,w;
            u=e[k].u,v=e[k].v,w=e[k].w;
            dist[u][v]=min(dist[u][v],w);
            dist[v][u]=dist[u][v];
        }
    }
    //
    for(ll k=1;k<=n;k++)
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    //
    for(ll i=q;i>=1;i--){
        if(que[i].opt==2){
            if(dist[que[i].x][que[i].y]==dist[0][0]){
                ans[++cnt]=-1;
            }else{
                ans[++cnt]=dist[que[i].x][que[i].y];
            }
        }else{
            ll u=e[que[i].d].u,v=e[que[i].d].v,w=e[que[i].d].w;
            for(ll i=1;i<=n;i++)
                for(ll j=1;j<=n;j++){
                    dist[i][j]=min({dist[i][j],dist[i][u]+dist[v][j]+w,dist[i][v]+dist[u][j]+w});
                }
        }
    }
    //
    //
    while(cnt--){
        cout<<ans[cnt+1]<<"\n";
    }
    return 0;
}