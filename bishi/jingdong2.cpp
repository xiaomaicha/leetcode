//
// Created by Administrator on 2019/4/13.
//


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void substr_set_op(const string &strt, vector<string> out, vector<vector<string>>& res){
    if(strt.empty()){
        res.push_back(out);
        return;
    } else{
        for(unsigned int i=0; i<=strt.size();++i){
            if(i==0&& !strt.empty()){
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


bool is_in_strs(string& s, vector<string>& strs){
    for (const auto &str : strs) {
        if(s == str)
            return true;
    }
    return false;
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
    getline(cin,strt);

    vector<vector<string>> substr_set;
    vector<string> substr;
    substr_set_op(strt, substr,substr_set);
    sort(substr_set.begin(),substr_set.end(),[](vector<string> a, vector<string>b){
        return a.size()>b.size();
    });

    int res_cnt = 0;
    for(vector<string> &ss:substr_set){
        int cnt = ss.size();
        bool match = true;
        for (int i = 0; i < cnt; ++i) {
            bool isin = is_in_strs(ss[i], strs);
            if (!isin){
                match = false;
                break;
            }
        }
        if (match){
            res_cnt = cnt;
            break;
        }
    }
    cout<<res_cnt<<endl;
    return 0;
}




