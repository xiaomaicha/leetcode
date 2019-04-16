//
// Created by Administrator on 2019/4/16.
//

#include<iostream>
//using namespace std;
//#define SIZE_M 2
//#define SIZE_N 3
//#define SIZE_S 4
//
//int main(){
//
//	int matrix_a[SIZE_M] [SIZE_N]={{1,2,3},{4,5,6}};//a矩阵2X3
//	int matrix_b[SIZE_N] [SIZE_S]={{1,2,3,4},{5,6,7,8},{1,2,3,4}};//b矩阵3X4
//	int matrix_result[SIZE_M][SIZE_S];//结果矩阵2X4
//
//
//	for(int m=0;m<SIZE_M;m++){
//		for(int s=0;s<SIZE_S;s++){
//			matrix_result[m][s]=0;//变量使用前记得初始化,否则结果具有不确定性
//			for(int n=0;n<SIZE_N;n++){
//				matrix_result[m][s]+=matrix_a[m][n]*matrix_b[n][s];
//			}
//		}
//	}
//	for(int m=0;m<SIZE_M;m++){
//		for(int s=0;s<SIZE_S;s++){
//			cout<<matrix_result[m][s]<<"\t";
//		}
//		cout<<endl;
//	}
//	return 0;
//}

//void mul(const double * A, const double * B, double AB, int m, int n, int k){
//
//}

//
//void mult(const double* A, const double * B, double*AxB, const int M, const int N, const int K) {
//    for (int m = 0; m < M; m++) {
//        for (int k = 0; k < K; k++) {
//            double tmp = 0;
//            for (int n = 0; n < N; n++) {
//                tmp += A[m*N + n] * B[n*K + k];
//            }
//            AxB[m*K + k] = tmp;
//        }
//    }
//}
//int main(){
//    double a[6] = {1,1,1,1,1,1};
//    double b[9] = {1,2,3,4,5,6,7,8,9};
//    double c[6] = {0};
//    mult(a,b,c,2,3,3);
//    return 0;
//}

#include<iostream>
#include <vector>
#include <algorithm>
#define EP 0.00001

using namespace std;

struct point{
    double x,y;
};

struct boundindbox{
    point topleft, lowwerright;
};

bool cmp_x(point& a, point& b){
    return  a.x<b.x;
}

bool cmp_y(point& a, point& b){
    return  a.y<b.y;
}

void calbbox(const vector<point>& pts, boundindbox* bb)
{

    sort(pts.begin(),pts.end(),cmp_x);
    bb->topleft.x = pts.front().x;
    bb->lowwerright.x = pts.back().x;

    sort(pts.begin(),pts.end(),cmp_y);
    bb->topleft.y = pts.front().y;
    bb->lowwerright.y = pts.back().y;

}

//template <class T = double>
//class point
//{
//public:
//    T x;
//    T y;
//    point()	{};
//    point(T a,T b)
//    {
//        x = a;
//        y = b;
//    }
//    point(const point<T>& a)
//    {
//        x = a.x;
//        y = a.y;
//    }
//    point<T>& operator = (const point<T>& p)
//    {
//        x = p.x;
//        y = p.y;
//    }
//    friend point<T> operator - (point<T>& p1, point<T>& p2)
//    {
//        point<T> p(p1.x - p2.x, p1.y - p2.y);
//        return p;
//    }
//    void MoveTo(T a,T b)
//    {
//        x = a;
//        y = b;
//    }
//    void SetX(T a)
//    {
//        x = a;
//    }
//    void SetY(T a)
//    {
//        y = a;
//    }
//    T GetX()
//    {
//        return x;
//    }
//    T GetY()
//    {
//        return y;
//    }
//    friend T crossProduct(point<T> p1, point<T> p2) //向量叉积
//    {
//        return p1.x * p2.y - p1.y * p2.x;
//    }
//    friend T direction(point<T> p1, point<T> p2, point<T> pO) // 向量叉积 之差 判断方向
//    {
//        return crossProduct(p1 - pO, p2 - pO);
//    }
//    friend bool operator == (point<T>& p1, point<T>& p2) //判断位置
//    {
//        return (abs(p1.x - p2.x) < EP && abs(p1.y - p2.y) < EP);
//    }
//    friend T dist(point<T> p1, point<T> p2) //计算距离
//    {
//        return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
//    }
//    friend istream& operator >> (istream& input, point<T>& p) //输入
//    {
//        input >> p.x;
//        input >> p.y;
//        return input;
//    }
//    friend ostream& operator << (ostream& output, point<T>& p) //输出
//    {
//        output << p.x << ' ' << p.y;
//        return output;
//    }
//};


