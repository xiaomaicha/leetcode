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
    unsigned int s_size = data.size();
    for (int i = 0; i < spacecnt; ++i) {
        data.push_back(' ');
        data.push_back(' ');
    }
    auto it2 = data.end() - 1;
    while (s_size-->0){
        if(*it1 == ' '){
            *it2-- = '0';
            *it2-- = '2';
            *it2-- = '%';
            it1--;
        } else{
            *it2-- = *it1;
            it1--;
        }
    }
}

int main(){
    string data = "my name";
    replacestr(data);
    cout<<data<<endl;
    return 0;
}