#include <bits/stdc++.h>
#define ll long long

using namespace std;

string to_string(vector<bool> v) { bool first = true; string res = "["; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) { res += ", ";} first = false; res += to_string(v[i]);} res += "]"; return res;}
template <typename A>
string to_string(A v) { bool first = true; string res = "["; for (const auto &x : v) { if (!first) {res += ", "; } first = false; res += to_string(x);} res += "]"; return res;}


int main(){
    ll n = 9999999999999999;
    long long div = 8;
    long long divisor = 20;
    cout<<(n/(double)div)<<endl;
    if(n%div==0){
        cout<<((n /div))*divisor <<endl;
    }else{
        cout<<((n /div)+1)*divisor <<endl;
    }

}