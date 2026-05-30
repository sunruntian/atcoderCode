#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll T;cin>>T;
	while(T--){
		string s;
        cin>>s;
		ll n=s.size(),cnt[26]={},id=0;
		for(char c:s){
            cnt[c-'a']++;
            if(cnt[id]<cnt[c-'a']){
                id=c-'a';
            }
        }
		if(cnt[id]>(n+1)/2){
            cout<<"No\n";
            continue;
        }
		string ans(n,' ');
		ll idx=0;
        while(cnt[id]-->0){
            ans[idx]=id+'a';
            idx+=2;
        }
        bool f=false;
		for(ll i=0;i<26;i++){
            while(cnt[i]>0){
                cnt[i]--;
                if(!f&&idx>=n){
                    idx=1;
                    f=true;
                }
                ans[idx]=i+'a';
                idx+=2;
            }
        }
		cout<<"Yes\n"<<ans<<'\n';
	}
}