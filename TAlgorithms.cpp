#include <bits/stdc++.h>
using namespace std;

bool checkerForBinarySearch(vector<long long> &v1, long long num){
    //check for binary search if the selected number works
    //Not implemented yet
    return false;
}

long long lBinSearch(long long l, long long r, vector<long long> &v1){
    //Assuming that we know that the elements exists there for sure, but we want to find the most optimal one
    //After some point all numbers will be considered as "Good"
    //We need to find most left "Good" number
    while(l<r){
        long long m = l + (r-l)/2;
        if(checkerForBinarySearch(v1, m)){
            r = m;
        }else{
            l = m+1;
        }
    }
    return l;
}
long long rBinSearch(long long l, long long r, vector<long long> &v1){
    //Assuming that we know that the elements exists there for sure, but we want to find the most optimal one
    //After some point all numbers will be considered as "Bad"
    //We need to find most Right "Good" number
    while(l<r){
        long long m = l + (r-l+1)/2;
        if(checkerForBinarySearch(v1,m)){
            l = m;
        }else{
            r = m-1;
        }
    }
    return l;
}

int main(){

}
