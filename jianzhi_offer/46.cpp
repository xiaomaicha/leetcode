//
// Created by Administrator on 2019/4/15.
//

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt[70] = {1,1};

int gettranslationcnt(int num){
    if(num<0)
        return 0;

    string numstr = to_string(num);

    int numsinze = numstr.size();

    for (int i = 1; i < numsinze; ++i) {
        if(numstr[i-1]=='1'){
            cnt[i+1] = cnt[i] + cnt[i-1];
        }
        else if(numstr[i-1]=='2'){
            if(numstr[i]>='0' && numstr[i]<='5'){
                cnt[i+1] = cnt[i] + cnt[i-1];
            } else{
                cnt[i+1] = cnt[i];
            }
        } else{
            cnt[i+1] = cnt[i];
        }
    }
    return cnt[numsinze];
}

int main(){
    int num;
    cin>>num;
    int res = gettranslationcnt(num);
    cout<<res;

    return 0;
}