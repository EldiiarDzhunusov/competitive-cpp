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
    long long k,x;
    long long counter =0;
    cin>>k>>x;
    for (int i = 1; i <= k; i++) {
        counter++;
        if((i*(i+1))/2>=x){
            cout<<i<<endl;
            return;
        }
    }
    long long sum1 = (k*(k+1))/2;
    for (int i = k-1; i >= 1; i--) {
        sum1+=i;
        counter++;
        if(sum1>=x){
            cout<<counter<<endl;
            return;
        }

    }
    cout<<counter<<endl;
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
