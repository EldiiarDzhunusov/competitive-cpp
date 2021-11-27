#include <bits/stdc++.h>
#define ll long long
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
string to_string(vector<long long> v1){
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
    int n; cin>>n;
    vector<vector<ll>> v1(n+1 , vector<ll> (2, 0));
    for (int i = 1; i <=n ; i++) {
        cin>>v1[i][0]; v1[i][1] = i;
    }
    map<ll,ll> map1; //stores index and their coordinate
    map1[0] = 0;
    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
//    cout<<to_string(v1)<<endl;
    ll l = -1;
    ll r = 1;
    ll  ans = 0;
    for (ll i = 0; i < n + 1; i++) {
        if(i==n){
            map1[0] = 0;
        }
        else if(abs(l)<r){
            ans+=abs(l)*2 *v1[i][0];
            map1[v1[i][1]] = l--;
        }else{
            ans+=abs(r)*2 *v1[i][0];
            map1[v1[i][1]]= r++;
        }
    }
//    cout<<"map: "<<endl;
//    for(auto x: map1){
//        cout<<x.first<<" " <<x.second<<endl;
//    }
//    cout<<endl;
    cout<<ans<<endl;
    for (ll i = 0; i < n + 1; i++) {
        cout<<map1[i]<<" ";
    }
    cout<<endl;

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
