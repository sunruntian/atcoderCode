#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll T;
    cin>>T;
    while(T--){
        ll a,b,x,y;
        cin>>a>>b>>x>>y;
        if(x==0&&y==0)cout<<0<<"\n";
        if(a<b){
            if(x>0&&y>0){
                if(y<x){
                    if(x-y&1)cout<<a*y+(a+b)*((x-y)/2)+a<<"\n";
                    else cout<<a*y+(a+b)*((x-y)/2)<<"\n";
                }else if(x>y){
                    if(y-x&1)cout<<a*x+(a+b)*((y-x)/2)+b<<"\n";
                    else cout<<a*x+(a+b)*((y-x)/2)<<"\n";
                }else{
                    cout<<a*x<<"\n";
                }
            }
            else if(x>0&&y<0){
                if(x+y>0){
                    if(x+y&1)cout<<a*x+(a+b)*((x+y)/2)<<"\n";
                    else cout<<a*x+(a+b)*((x+y)/2)<<"\n";
                }else if(x+y<0){
                    if(x+y&1)cout<<a*x+(a+b)*(-y+(x+y)/2)+b<<"\n";
                    else cout<<a*x+(a+b)*(-y+(x+y)/2)<<"\n";
                }else{
                    cout<<a*x<<"\n";
                }
            }
            else if(x<0&&y>0){
                if(y+x>0){
                    if(y+x&1)cout<<a*y+(a+b)*(y+(x-y)/2)+b<<"\n";
                    else cout<<a*y+(a+b)*(y+(x-y)/2)<<"\n";
                }else if(y+x<0){
                    if(y+x&1)cout<<a*y+(a+b)*(-x+(y+x)/2)+a<<"\n";
                    else cout<<a*y+(a+b)*(-x+(y+x)/2)<<"\n";
                }else{
                    cout<<a*y<<"\n";
                }
            }else if(x<0&&y<0){
                if(x>y){
                    if(x-y&1)cout<<a*x+(a+b)*(-y+(x-y)/2)+b<<"\n";
                    else cout<<a*x+(a+b)*(-y+(x-y)/2)<<"\n";
                }else if(x<y){
                    if(y-x&1)cout<<a*x+(a+b)*(-x+(y-x)/2)+a<<"\n";
                    else cout<<a*x+(a+b)*(-x+(y-x)/2)<<"\n";
                }else{
                    cout<<a*x<<"\n";
                }
            }
            else if(x==0){
                if(y>0)cout<<a*y<<"\n";
                else cout<<a*y<<"\n";
            }
            else if(y==0){
                if(x>0)cout<<a*x<<"\n";
                else cout<<a*x<<"\n";
            }
        }else if(a>=b){
            if(x>0&&y>0){
                if(y<x){
                    if(x-y&1)cout<<b*y+(a+b)*((x-y)/2)+b<<"\n";
                    else cout<<b*y+(a+b)*((x-y)/2)<<"\n";
                }else if(x>y){
                    if(y-x&1)cout<<b*x+(a+b)*((y-x)/2)+a<<"\n";
                    else cout<<b*x+(a+b)*((y-x)/2)<<"\n";
                }else{
                    cout<<b*x<<"\n";
                }
            }
            else if(x>0&&y<0){
                if(x+y>0){
                    if(x+y&1)cout<<b*x+(a+b)*((x+y)/2)+a<<"\n";
                    else cout<<b*x+(a+b)*((x+y)/2)<<"\n";
                }else if(x+y<0){
                    if(x+y&1)cout<<b*x+(a+b)*(-y+(x+y)/2)+b<<"\n";
                    else cout<<b*x+(a+b)*(-y+(x+y)/2)<<"\n";
                }else{
                    cout<<b*x<<"\n";
                }
            }
            else if(x<0&&y>0){
                if(y+x>0){
                    if(y+x&1)cout<<b*y+(a+b)*(y+(x-y)/2)+a<<"\n";
                    else cout<<b*y+(a+b)*(y+(x-y)/2)<<"\n";
                }else if(y+x<0){
                    if(y+x&1)cout<<b*y+(a+b)*(-x+(y+x)/2)+b<<"\n";
                    else cout<<b*y+(a+b)*(-x+(y+x)/2)<<"\n";
                }else{
                    cout<<b*y<<"\n";
                }
            }else if(x<0&&y<0){
                if(x>y){
                    if(x-y&1)cout<<b*x+(a+b)*(-y+(x-y)/2)+a<<"\n";
                    else cout<<b*x+(a+b)*(-y+(x-y)/2)<<"\n";
                }else if(x<y){
                    if(y-x&1)cout<<b*x+(a+b)*(-x+(y-x)/2)+b<<"\n";
                    else cout<<b*x+(a+b)*(-x+(y-x)/2)<<"\n";
                }
            }
            else if(x==0){
                if(y>0)cout<<b*y<<"\n";
                else cout<<b*y<<"\n";
            }
            else if(y==0){
                if(x>0)cout<<b*x<<"\n";
                else cout<<b*x<<"\n";
                    
            }
        }
        
    }
    return 0;
}