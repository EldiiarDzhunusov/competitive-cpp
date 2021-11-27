#include <bits/stdc++.h>
using namespace std;

void solve(){
    //insert your code here
}

int euclidGCD(int a, int b)
{
    if (b == 0)
        return a;
    return euclidGCD(b , a%b);
}
int findGCD(vector<int>& nums) {
    int min1 = *min_element(nums.begin(),nums.end());
    int max1 = *max_element(nums.begin(),nums.end());
    return euclidGCD(min1,max1);
}
string reversePrefix(string word, char ch) {
    int index = 0;
    for (int i = 0; i < word.size(); i++) {
        if(word[i]==ch){
            index = i;
            break;
        }
    }
    string ans = "";
    for (int i = index; i >= 0; i--) {
        ans+=word[i];
    }
    for (int i = index+1; i < word.size(); i++) {
        ans+=word[i];
    }
    return ans;
}
int numOfStrings(vector<string>& patterns, string word) {
    int ans = 0;
    for (int i = 0; i < patterns.size(); i++) {
        if(word.find(patterns[i])!= string::npos){
            ans++;
        }
    }
    return ans;
}
bool areOccurrencesEqual(string s) {
    map<char,int> map1;
    int n = -1;
    for (int i = 0; i < s.size(); i++) {
        map1[s[i]] = map1[s[i]]+1;
        n=map1[s[i]];
    }

    for(auto x: map1){
        if(x.second!=n){
            return false;
        }
    }
    return true;
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

int sumOfUnique(vector<int>& nums) {
    map<int,int> map1;
    int ans =0 ;
    for (int i = 0; i < nums.size(); i++) {
        map1[nums[i]]++;
        if(map1[nums[i]]==1){
            ans+=nums[i];
        }
        if(map1[nums[i]]==2){
            ans-=nums[i];
        }
    }

    return ans;

}
int romanToInt(string s) {
    map<char,int> map1;
    map1['I']=1;
    map1['V']=5;
    map1['X']=10;
    map1['L']=50;
    map1['C']=100;
    map1['D']=500;
    map1['M']=1000;
    int temp = 0;
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if(map1[s[i]]>=temp){
            temp = map1[s[i]];
            ans+=temp;
        }else{
            ans-=map1[s[i]];
        }
    }
    return ans;
}
int removeDuplicates(vector<int>& nums) {
    if(nums.size()==0){
        return 0;
    }

    int j = 1;
    for (int i = 1; i < nums.size(); i++) {

        if(nums[j-1]!=nums[i]){
            nums[j] = nums[i];
            j++;
        }
//        cout<<j<<" "<<i<<endl;
//        cout<<to_string(nums)<<endl;
    }
    return j;

}
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    int localMax = 0;
    for (int i = 0; i < nums.size(); i++) {
        localMax = max(nums[i],localMax+nums[i]);
        maxSum = max(localMax,maxSum);
    }
    return maxSum;
}
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> arr;
    vector<int> tempV{1};
    arr.push_back(tempV);
    for (int i = 2; i <= numRows; i++) {
//        cout<<numRows<<endl;
        vector<int> v1;
        for (int j = 0; j < i; j++) {
            if(j==0 || j==i-1){
                v1.push_back(1);
            }else{
                v1.push_back(arr[i-2][j-1]+arr[i-2][j]);
            }
//            cout<<to_string(v1)<<endl;
        }
        arr.push_back(v1);
//        cout<<to_string(arr)<<endl;
    }

    return arr;
}
vector<int> countBits(int n) {
    vector<int> vec(n+1);
    int pow1= 0;
    int i = 2;
    if(n==0){
        vec[0]=0;
        return vec;
    }
    vec[0]=0;
    vec[1]=1;
    if(n==1){
        return vec;
    }
    while(i<=n){
        int num = pow(2,pow1);
        for (int j = 0; j < num; j++) {
            vec[i] = vec[i-(num)];
            if(i==n){
                return vec;
            }
            i++;
        }
        for (int j = 0; j < num; j++) {
            vec[i] = vec[i-(num*2)]+1;
            if(i==n){
                return vec;
            }
            i++;
        }
        pow1++;
    }
    return vec;
}
vector<int> sortByBits(vector<int>& arr) {
    vector<vector<int>> v1(arr.size(),vector<int> (2, 0));
    for (int i = 0; i < arr.size(); i++) {
        v1[i][0] = __builtin_popcount(arr[i]);
        v1[i][1] = arr[i];
    }
    sort(v1.begin(),v1.end());
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = v1[i][1];
    }
    return arr;
}
int countGoodSubstrings(string s) {
    int ans = 0;
    for (int i = 2; i < s.size(); i++) {
        if(s[i-1]!=s[i-2] && s[i]!=s[i-1] && s[i]!=s[i-2]){
            ans++;
        }
    }
    return ans;
}
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans(nums1.size());
    for (int i = 0; i < nums1.size(); i++) {
        int index = -1;
        for (int j = 0; j < nums2.size(); j++) {

        }
        
    }
}
int smallestEqual(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      if(i%10==nums[i]){
          return i;
      }
    }
    return -1;
}
string mergeAlternately(string word1, string word2) {
    int i =0;
    int j =0;
    string ans ="";
    int index = 0;
    while(i<word1.size() && j<word2.size()){
        if(index%2==0){
            ans+=word1[i++];
        }else{
            ans+=word2[j++];
        }
        index++;
    }
    while(i<word1.size()){
        ans+=word1[i++];
    }
    while(j<word2.size()){
        ans+=word2[j++];
    }
    return ans;
}
int main(){
    cout<<(10 % 2 == 1)<<endl;
    vector<int> x = countBits(10);
    for( auto b: x){
        cout<<b<<" ";
    }
    cout<<endl;

}

