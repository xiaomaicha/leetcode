//
// Created by Administrator on 2019/4/15 0015.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
void splitcard(int card_num,vector<int>& thr, int& rest){
    deque<int> card;
    for (int i = 1; i <= card_num; ++i) {
        card.push_back(i);
    }
    while (card.size()>=2){
        int first = card.front();
        thr.push_back(first);
        card.pop_front();
        int second = card.front();
        card.pop_front();
        card.push_back(second);
    }
    rest=card.front();
}
void printcard(int data){
    cout<<data<<" ";
}
int main(){
    int test_num;
    cin>>test_num;
    vector<int> card_num;
    for (int i = 0; i < test_num; ++i) {
        int data;
        cin>>data;
        card_num.push_back(data);
    }
    for (int i = 0; i < test_num; ++i) {
        vector<int> thr;
        int rest;
        splitcard(card_num[i], thr,rest);
        for_each(thr.begin(), thr.end(), printcard);
        cout<<rest<<endl;
    }
    return 0;
}

//
//int main() {
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        int num;
//        cin >> num;
//        deque<int> out;
//        for (auto it=0; it < num; it++) out.push_back(it + 1);
//        while (out.size() >= 2){
//            cout << out.front()<<" ";
//            out.pop_front();
//            out.push_back(out.front());
//            out.pop_front();
//        }
//        cout << out.front() << endl;
//    }
//    return 0;
//}