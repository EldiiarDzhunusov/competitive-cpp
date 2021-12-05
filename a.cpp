#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}

void solve() {
    //insert your code here
    int n; cin>>n;
    vector<int> v1(n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++) {
        cin>>v1[i];
    }
    unordered_map<int,int> map2;
    for (int i = 0; i < n; i++) {
        cin>>v2[i];
        map2[v2[i]]++;
    }
    std::sort(v1.begin(), v1.end());
    for (int i = 0; i < n; i++) {
        if(map2[v1[i]]>0){
            map2[v1[i]]--;
        }else if(map2[v1[i]+1]>0){
            map2[v1[i]+1]--;
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long t = 1;
    cin>>t;
    for (int i = 1; i <= t; i++) {
//        cout<<"Case #"<<i<<+": ";
        solve();
    }
}
