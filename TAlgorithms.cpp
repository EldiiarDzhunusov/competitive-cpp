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

//Segment Tree

const int N = 1e5+5;
const int inf = 1e9+5;
int k,x,y,n;
int a[N]; //origin values should be here from index 1

struct Node{
    int mn;
    int mx;
    Node(){
        mn = inf;
        mx = -inf;
    }
};

Node t[N*4];



Node combine(Node a, Node b){ //adds two nodes, can be added in any way, depends on the question and structure
    Node c;
    c.mn = min(a.mn,b.mn);
    c.mx = max(a.mx,b.mx);
    return c;
}
void build(int v = 1, int tl = 1, int tr = n){ //for the build of the tree (usually is used 1 time at the beginning)
    if(tl==tr){
        t[v].mn = a[tl];
        t[v].mx = a[tl];
    }else{
        int tm = (tl+tr)/2;
        build(v+v, tl,tm);
        build(v+v+1, tm+1,tr);
        t[v] = combine(t[v+v],t[v+v+1]);
    }
}
Node get (int l,int r, int v = 1, int tl = 1, int tr = n){ //gets the needed node in the range of l and r (if they are different, combines)
    if(r<tl || tr<l){
        return Node();
    }
    if(l<=tl && r>=tr){
        return t[v];
    }
    int tm = (tl+tr)/2;

    return combine(get(l,r,v+v,tl,tm), get(l,r,v+v+1,tm+1,tr));
}

void update(int pos,int new_val, int v = 1, int tl=1, int tr = n){ //updates the values in the position of pos with the new value
    if(tl==tr){
        t[v].mn = new_val;
        t[v].mx = new_val;
    }else{
        int tm = (tl+tr)/2;
        if(pos<=tm){
            update(pos, new_val, v+v, tl,tm);
        }else{
            update(pos,new_val, v+v+1, tm+1,tr);
        }
        t[v] = combine(t[v+v],t[v+v+1]);
    }
}

int main(){

}
