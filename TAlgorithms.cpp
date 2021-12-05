#include <bits/stdc++.h>
using namespace std;

bool checkerForBinarySearch(vector<long long> &v1){
    //check for binary search if the selected number works
    //Not implemented yet
    return false;
}

long long lBinSearch(int l, int r, vector<long long> &v1){
    //Assuming that we know that the elements exists there for sure, but we want to find the most optimal one
    //After some point all numbers will be considered as "Good"
    //We need to find most left "Good" number
    while(l<r){
        int m = l + (r-l)/2;
        if(checkerForBinarySearch(v1)){
            r = m;
        }else{
            l = m+1;
        }
    }
    return l;
}
long long rBinSearch(int l, int r, vector<long long> &v1){
    //Assuming that we know that the elements exists there for sure, but we want to find the most optimal one
    //After some point all numbers will be considered as "Bad"
    //We need to find most Right "Good" number
    while(l<r){
        int m = l + (r-l+1)/2;
        if(checkerForBinarySearch(v1)){
            l = m;
        }else{
            r = m-1;
        }
    }
    return l;
}

int main(){

}
