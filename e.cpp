#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b , a%b);
}
long gcd(long a, long b)
{
    if (b == 0)
        return a;
    return gcd(b , a%b);
}
string to_string(vector<int> v1){
    bool isFirst = true;
    string ans = "[";
    for (int i = 0; i < v1.size(); i++) {
        if(isFirst){
            ans+= to_string(v1[i]);
            isFirst= false;
        }else{
            ans+=", "+ to_string(v1[i]);
        }
    }
    ans+="]";
    return ans;
}
string to_string(vector<vector<int>> v1){
    bool isFirst = true;
    string ans = "[";
    for (int i = 0; i < v1.size(); i++) {
        if(isFirst){
            ans+= to_string(v1[i]);
            isFirst= false;
        }else{
            ans+=", "+ to_string(v1[i]);
        }
    }
    ans+="]";
    return ans;
}

void solve(){
    //insert your code here
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long t = 1;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}
