////
//// Created by Administrator on 2019/4/9 0009.
////
//
#include <iostream>
#include <thread>
#include <vector>
using  namespace std;

// class A{
// private:
//     int data_;
//
// public:
//     A(int data):data_(data){
//         cout<<"��ʽ���캯��"<<endl;
//         cout<<"data:"<<data<<endl;
//     }
//     A(const A& a):data_(a.data_){
//         cout<<"�������캯��"<<endl;
//     }
//     ~A()
//     {
//         cout<<"��������"<<endl;
//     }
// };
//
// int main(){
//     thread mythread;
//     int data = 1;
//     A a1(data);
//     A a2(a1);
// }


//#include<thread>
//#include<iostream>
//#include<string>
//using namespace std;
//void threadFunc(std::string &str, int *a)
//{
////    cout<<&str<<endl;
////    str = "change by threadFunc";
////    a = 13;
//    cout<<"a:"<<a<<endl;
//    cout<<str<<endl<<this_thread::get_id()<<endl;
//
//}
//void fun(){
//    std::cout<<" hello world"<<std::endl;
//}
//
//int main()
//{
//    std::string str("main");
//    int a = 9;
////    cout<<&str<<endl;
//    cout<<&a<<endl;
//    std::thread th(threadFunc, ref(str), &a);
//    std::thread t2(fun);
//    th.join();
//    t2.join();
//
//    std::cout<<"str = " << str << std::endl;
//    std::cout<<"a = " << a << std::endl;
//    auto name = 0;
//    return 0;
//}
//
//


#include <iostream>

using namespace std;

//int& test_str()
//{
//    int a = 1;
//
//    return a; //ͨ������ a �ĵ�ַ������ ֵ�ķ��أ��� a�ĵ�ַ���������ֵ��
//}

int ff(int t) //���صľ��Ǹ��� a ��ֵ��a���ھֲ�������������������ڴ��Զ��ͷţ���ַҲ�Ͳ�����
//�������� &ff��b�� �ᱨ�� :��&��Ҫ����ֵ ,��û�е�ַ����ȡ
{
    static int a = 3;
    return a;
}

int& fun(int &a)
{
    cout <<"aa "<< &a << endl;
    return a;
}
int main()
{
    /*int *p= &test_str();

    cout << *p << endl;
    cout << *p << endl;*/

    int b ;

    cout <<"b�� "<< &b << endl;
    b = 4;
    cout << "fun :" << &fun(b) << endl;

    int a;

    cout <<"a��"<< &a << endl;

    a= fun(b); //�� fun(b) ��ַ�д����ֵ ��ֵ �� a ����� a �ĵ�ַû�з����ı�
    cout <<"a :"<< &a << endl;

    /*int b = 1;
    cout << "b :" << &b << endl;

    int *p = new int;

    *p = ff(b);*/

    //cout << "ff :" << &ff(b) << endl;

    return 0;
}
