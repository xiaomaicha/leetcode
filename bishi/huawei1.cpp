////
//// Created by Administrator on 2019/4/24 0024.
////
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool issymmerty1(string& str)
{
    int size = str.size();
    if(size==0 || size&1 || size>=1000){
        cout<<"false"<<endl;
        return false;
    }
    int middle = size>>1;
    if(middle&1)
        middle--;
    for (int i = 0; i < middle; i=i+2) {
        if(str[i] - str[size-i-1] || str[i] - str[i+1]){
            cout<<"false"<<endl;
            return false;
        }
    }
    if(!(middle&1)){
        if(str[middle]!=str[middle+1]){
            cout<<"false"<<endl;
            return false;
        }
    }
    for (int i = 0; i < size; i=i+2) {
        cout<<str[i];
    }
    return true;
}
//
int main(){
    string str;
//    vector<string> str_vec;
    do {
        getline(cin,str);
        bool res = issymmerty1(str);
//        cout<<bool(res)<<endl;
//        str_vec.push_back(str);
    }while (getchar() !='\n');

//    for (auto& s:str_vec){
//        bool res = issymmerty(s);
//        cout<<bool(res)<<endl;
//    }
    return 0;
}

//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
//using namespace std;
//void issymmerty(string& str) {
//    string string_reverse(str.rbegin(), str.rend());
//    if (str.size() % 2 == 0 && str == string_reverse && !str.empty() && str.size()<=1000) {
//        auto it1 = str.begin();
//        auto it2 = str.begin()+1;
//        while (it2 < str.end()) {
//            if (*it1 != *it2) {
//                cout << "false" << endl;
//                return;
//            }
//            it1 += 2;
//            it2 += 2;
//        }
//        it1 = str.begin();
//        while (it1 < str.end()){
//            cout<<*it1;
//            it1+=2;
//        }
//    }
//    else
//        cout << "false" << endl;
//}
//
//int main() {
//    string str;
//    while(cin>>str){
//        issymmerty(str);
//    }
//    return 0;
//}