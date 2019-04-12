//
// Created by Administrator on 2019/4/8 0008.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
void split(const string& s,vector<int>& sv,const char flag = ' ') {
    sv.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        sv.push_back(stoi(temp));
    }
}

int main() {
    string nums;
    getline(cin,nums);
    vector<int> sv;
    split(nums, sv, ' ');
    for (const auto& s : sv) {
        cout << s << endl;
    }
    system("pause");
    return 0;
}

//int main()
//{   int a;
//    vector<int> num;
//
//    do {
//        cin>>a;
//        num.push_back(a);
//    }while (getchar() !='\n');
//    return 0;
//}