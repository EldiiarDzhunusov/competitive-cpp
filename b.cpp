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
    int n,a,b;
    cin>>n>>a>>b;
    if((a>n/2+1) || (b<n/2) || (a<=n/2 && b<=n/2) || (a>n/2 && b>n/2)){
        cout<<-1<<endl;
    }else
    {
        cout<<a<<" ";
        set<int> set1;
        for (int i = n; i >=1; i--) {
            if(i!=b && i!=a){
                cout<<i<<" ";
                set1.insert(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            if(i!=b && i!=a && set1.count(i)<1){
                cout<<i<<" ";
            }
        }
        cout<<b<<endl;
    }
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
