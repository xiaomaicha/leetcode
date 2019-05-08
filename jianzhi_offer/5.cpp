//
// Created by Administrator on 2019/4/26 0026.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

void replacestr(string& data){
    int spacecnt = 0;
    for (char& i : data) {
        if(i == ' '){
            spacecnt++;
        }
    }
    auto it1 = data.end() - 1;
    for (int i = 0; i < spacecnt; ++i) {
        data.push_back(' ');
        data.push_back(' ');
    }
    auto it2 = data.end() - 1;
    while (it1 != data.begin()){
        if(*it1 == ' '){
            *it2-- = '0';
            *it2-- = '2';
            *it2-- = '%';
            it1--;
        } else{
            *it2-- = *it1--;
        }
    }
}

int main(){
    string data = "i love china";
    replacestr(data);
    cout<<endl;
    return 0;
}