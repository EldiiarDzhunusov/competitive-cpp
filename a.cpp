#include <bits/stdc++.h>
using namespace std;

int lastEndIndex(vector<vector<string>> commands,int index){
//    finds the index of end statement for the given loop
    index++;
    int counter =1;
    for (int i = index; i < commands.size(); ++i){
        if(commands[i].size()==1){
            counter--;
            if(counter==0){
                return i;
            }
        }else if(commands[i].size()==2){
            counter++;
        }
    }
    return -1;

}
void reduce(vector<vector<string>> &commands){
    //reduce loops if there are two consecutive loops
    int index = 1;
    while(commands.size()>1 && index<commands.size()){
        if(commands[index].size()==2 && commands[index-1].size()==2){
            int end1 = lastEndIndex(commands,index);
            int end2 = lastEndIndex(commands,index-1);
            if(abs(end1-end2)==1){
                int num1 = stoi(commands[index][1]);
                int num2 = stoi(commands[index-1][1]);
                commands[index-1][1] = to_string((num1*num2)%384);
                commands.erase(commands.begin() + index);
                commands.erase(commands.begin() + end1);
            }else{
                index++;
            }
        }else{
            index++;
        }

    }
}
int execute(int arr[],vector<vector<string>> commands,int index){
    if(commands[index].size()==2){
        int num = stoi(commands[index][1]);
        num%=384;
        int endIndex = lastEndIndex(commands,index);
        for (int i = 0; i < num; i++) {
            int index1 =index+1 ;
            while(index1<endIndex){
                index1 = execute(arr,commands,index1);
            }
        }
        return endIndex+1;
    }
    if(commands[index].size()==3){
        char a = commands[index][0][0];
        int b = stoi(commands[index][2]);
        arr[a-'A'] = b%256;
        int k = 0;

    }else if(commands[index].size()==5){
        char a = commands[index][0][0];
        char b = commands[index][2][0];
        char c = commands[index][4][0];
        arr[a-'A'] = (arr[b-'A']+ arr[c-'A'])%256;

    }
    return index+1;
}

void solve(){
    int arr[] = {0,0,0,0,0,0,0,0};
    vector<vector<string>> commands;

    //input
    int n; cin>>n;
    string str1;
    getline(cin,str1);
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin,str);
        string word = "";
        vector<string> v1;
        for (auto x : str)
        {
            if (x == ' ')
            {
                v1.push_back(word);
                word = "";
            }
            else {
                word = word + x;
            }
        }
        v1.push_back(word);
        if(v1.size()==2){
            int num = stoi(v1[1]);
            num%=384;
            v1[1] = to_string(num);
        }
        commands.push_back(v1);
    }
    //end of inputs



    reduce(commands);

//    print new commands / temp code
//    cout<<"Commands after reduction: "<<endl;
//    for (int i = 0; i < commands.size(); i++) {
//
//        for (int j = 0; j < commands[i].size(); j++) {
//            cout<<commands[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
    //end of temp code

    int index = 0;
    while(index<commands.size()){
        index = execute(arr,commands,index);
    }
    for (int i = 0; i < 7; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
