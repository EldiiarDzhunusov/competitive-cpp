#include <bits/stdc++.h>
#define ll long long
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

void solve(){
    //insert your code here
//    cout<<"fasd"<<endl;
    int n,m,a,b; cin>>n>>m;
    char string1[n];
//    cout<<"hh"<<endl;

    for (int i = 0; i < n; i++) {
//        cout<<"he"<<endl;
        string1[i]='1';
    }

    long ans = 0;
    for (int i = 0; i < m; i++) {
        cin>>a;
        cin>>b;
//        cout<<a<<" "<<b<<endl;
        for (int j = a; j <= b; j++) {
            string1[j] = '0';
        }
//        cout<<string1<<endl;
    }
    for (int i = 0; i < n; i++) {
        if(string1[i]=='1'){
            ans++;
        }
    }
//    cout<<string1<<endl;
    cout<<ans<<endl;

}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long t = 1;
//    cin>>t;
    for (int i = 1; i <= t; i++) {
//        cout<<"Case #"<<i<<+": ";
        solve();
    }
}
