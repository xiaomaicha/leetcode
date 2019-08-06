//
// Created by Administrator on 2019/4/15.
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int item1, int item2){
    string m = to_string(item1);
    string n = to_string(item2);

    string mn = m+n;
    string nm = n+m;
    return mn<nm;
}

string printminnumber(vector<int> &numbers){
    string res;
    if(numbers.empty())
        return res;
    sort(numbers.begin(), numbers.end(), compare);

    for (auto& num:numbers){
        res += to_string(num);
    }
    return res;
}

int main(){
    vector<int> test = {3,32,321};
    string res = printminnumber(test);
    cout<<res<<endl;
    return 0;
}
