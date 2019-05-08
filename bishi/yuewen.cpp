//
// Created by Administrator on 2019/4/20.
//

#include <cmath>
#include <iostream>
#include <string>
using namespace std;


bool char2double(char* pchar, int plen, double& result){
    if(pchar == nullptr || plen < 1)
        return false;
    int  sign=1;
    double base = 0.0;
    while (*(pchar) == ' ')
        pchar++;
    while (*pchar=='+' || *pchar=='-'){
        sign = *pchar++=='+'? 1:-1;
    }
    while (*pchar!='\0'){
        if(*pchar>='0' && *pchar<='9'){
            base*=10;
            base+=*pchar++ - '0';
        }
        else if(*pchar=='.')
            break;
        else
            return false;
    }
    pchar++;
    int count = 1;
    while (*pchar!='\0'){
        if(*pchar>='0' && *pchar<='9'){
            base += (*pchar++ - '0')/(pow(10, count));
            count++;
        }
        else
            return false;

    }

    result = base * sign;
    return *pchar == '\0';
}

int main(){
    char* str = const_cast<char *>("+-551.+355");
    double result;
    bool istrans =  char2double(str,7,result);

    if(istrans)
        std::cout<<result;
    else
        std::cout<<"can't trans"<<endl;

//    string num = "adf";
//    cout<<int(*num.end());



    return 0;
}