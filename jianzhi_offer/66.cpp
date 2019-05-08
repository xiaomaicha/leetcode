//
// Created by Administrator on 2019/4/25 0025.
//

#include <iostream>
#include <vector>

using namespace std;
//
//vector<int> multiply(vector<int>& data){
//    vector<int> res;
//    if(data.empty())
//        return res;
//    unsigned int size = data.size();
//    vector<int> front(size, 0), back(size, 0);
//
//    front[0] = 1;
//    front[1] = data[0];
//    back[size-1] = 1;
//    back[size-2] = data[size-1];
//    for (int i = 2; i < size; ++i) {
//        front[i] = front[i-1] * data[i-1];
//        back[size-1-i] = back[size-i] * data[size-i];
//    }
//    for (int i = 0; i < size; ++i) {
//        int tmp = front[i] * back[i];
//        res.push_back(tmp);
//    }
//    return res;
//}
//
//int main(){
//    vector<int> data = {1,2,3,4,5};
//    auto res = multiply(data);
//    cout<<endl;
//    return 0;
//}

#include <iostream>

using namespace std;

struct Test1
{
    Test1() // 无参构造函数
    {
        cout << "Construct Test1" << endl ;
    }

    Test1(const Test1& t1)  // 拷贝构造函数
    {
        cout << "Copy constructor for Test1" << endl ;
        this->a = t1.a ;
    }

    Test1& operator = (const Test1& t1) // 赋值运算符
    {
        cout << "assignment for Test1" << endl ;
        this->a = t1.a ;
        return *this;
    }

    int a ;
};

//struct Test2          //2.列表初始化
//{
//    Test1 test1 ;
//    Test2(Test1 &t1):test1(t1){}
//};

struct Test2           //普通初始化
{
    Test1 test1 ;
    Test2(Test1 &t1)
    {
        test1 = t1 ;
    }
};

int main(){
    Test1 t1 ;            //调用
    Test1 t2 = t1 ;
    return 0;
}