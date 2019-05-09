//
// Created by Administrator on 2019/5/8 0008.
//

#include <iostream>
#include <vector>

using namespace std;

void gift(unsigned int gift_num, unsigned int child_k,int cur_gift, int cur_k, vector<int>& out, vector<vector<int>>& res){
    if(cur_k==child_k){
        int num = gift_num - cur_gift;
        out.push_back(num);
        res.push_back(out);
        out.pop_back();
        return;
    }

    for (int i = cur_gift; i <= gift_num; ++i) {
        int num = i - cur_gift;
        out.push_back(num);
        gift(gift_num,child_k,i,cur_k+1,out,res);
        out.pop_back();
    }
}

int main(){
    unsigned int n,k;
    cin>>n>>k;
    vector<vector<int>> res;
    vector<int> out;
    gift(n,k,0,1,out,res);
    cout<<res.size()<<endl;

    for (int l = res.size()-1; l >=0; --l) {
        for (int i = 0; i < res[l].size(); ++i) {
            for (int j = 0; j <res[l][i] ; ++j) {
                cout<<char(42);
            }
            if(i!=res[l].size()-1){
                cout<<char(124);
            }
        }
        cout<<endl;
    }


    return 0;
}