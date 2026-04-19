#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

string t(string s){
    string st;
    for(char c:s){
        st.push_back(c);
        if(c==')'&&st.size()>=4){
            ll n=st.size();
            if(st[n-4]=='('&&st[n-3]=='x'&&st[n-2]=='x'){
                st.pop_back();
                st.pop_back();
                st.pop_back();
                st.pop_back();
                st.push_back('x');
                st.push_back('x');
            }
        }
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    if(!(cin>>T))return 0;
    string a,b;
    while(T--){
        cin>>a>>b;
        string na=t(a);
        string nb=t(b);
        if(na==nb){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
