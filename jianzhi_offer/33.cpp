//
// Created by Administrator on 2019/4/14.
//

#include <iostream>
#include <vector>

using namespace std;

bool vertifysequencebst(vector<int>::iterator left, vector<int>::iterator right){
    if (left==right)
        return false;
    int root = *(right-1);

    auto it1 = left;
    for (; it1!=right-1; it1++){
        if(*it1>root)
            break;
    };
    auto it2 = it1;
    for (; it2!=right-1; it2++) {
        if(*it2<root)
            return false;
    }

    bool bleft = true;
    if(it1!=left)
        bleft = vertifysequencebst(left, it1);

    bool bright = true;
    if(it1 != right-1)
        bright = vertifysequencebst(it1, right-1);

    return (bleft&&bright);

};

int main(){
    vector<int> seq1={4, 8, 6, 12, 16, 14, 10};;
    bool bseq1 = vertifysequencebst(seq1.begin(),seq1.end());
    cout<<bseq1<<endl;

    vector<int> seq2={4, 6, 7, 5};;
    bool bseq2 = vertifysequencebst(seq2.begin(),seq2.end());
    cout<<bseq2<<endl;

    vector<int> seq3={7, 4, 6, 5};;
    bool bseq3 = vertifysequencebst(seq3.begin(),seq3.end());
    cout<<bseq3<<endl;

    return 0;
}

