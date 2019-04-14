//
// Created by Administrator on 2019/4/13.
//


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void substr_set_op(string strt, vector<string> out, vector<vector<string>>& res){
    if(strt.empty()){
        res.push_back(out);
        return;
    } else{
        for(unsigned int i=0; i<=strt.size();++i){
            if(i==0&&strt.size()>=1){
                substr_set_op(strt.substr(i+1), out, res);
                continue;
            }
            string substr = strt.substr(0,i);
            out.push_back(substr);
            substr_set_op(strt.substr(i), out, res);
            out.pop_back();
        }
    }
}

int main(){
    unsigned int m;
    vector<string> strs;
    string strt;
    cin>>m;
    cin.get();
    for (int i = 0; i < m; ++i) {
        string nums;
        getline(cin,nums);
        strs.push_back(nums);
    }
//    cin.get();
    getline(cin,strt);

    vector<vector<string>> substr_set;
    vector<string> substr;
    substr_set_op(strt, substr,substr_set);

    cout<<endl;


    return 0;

}




