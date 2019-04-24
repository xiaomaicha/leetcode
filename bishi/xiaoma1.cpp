//
// Created by Administrator on 2019/4/21 0021.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    double n,h;
    vector<double> height;
    cin>>n>>h;
    vector<double> result(n, 0);
    for (int i = 0; i < n; ++i) {
        double data;
        cin>>data;
        height.push_back(data);
    }
    for (int i = n-1; i >= 0 ; --i) {
        for (int j = i -1; j >= 0 ; --j) {
            double maxheight = ((height[i] -h)/(i+1))*(j+1) + h;
            if(height[j] >= maxheight){
                result[i] = j+1;
                break;
            }
        }
    }

    for (auto &num: result)
        cout<<num<<endl;
    return 0;

}