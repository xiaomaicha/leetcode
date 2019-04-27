//
// Created by Administrator on 2019/4/27.
//

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>

using namespace std;

void splitcard(int card_num,vector<int>& deskcard,deque<int>& card){
    for (int i = 0; i < 2; ++i) {
        card.push_front(deskcard[i]);
    }

    for (int i = 2; i < card_num; ++i) {
        card.push_front(card.back());
        card.pop_back();
        card.push_front(deskcard[i]);
    }

}

void split(const string& s,vector<int>& sv,const char flag = ' ') {
    sv.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        sv.push_back(stoi(temp));
    }
}

int main(){
    unsigned int test_n;
    cin>>test_n;
    cin.get();
    vector<vector<int>> card_seq(test_n);
    for (int i = 0; i < test_n; ++i) {
        string nums;
        getline(cin,nums);
        split(nums, card_seq[i], ' ');
    }

    for (int i = 0; i < test_n; ++i) {
        deque<int> original_card;
        splitcard(card_seq[i].size(),card_seq[i],original_card);
        for(auto& data:original_card){
            cout<<data<<" ";
        }
        original_card.clear();
        cout<<endl;
    }

    return 0;
}