#include<stdio.h>
#include <iostream>
#include <fstream>
#include <direct.h>
using namespace std;

int RemoveComment(char* input,int input_size,char* output)
{
    if(!input || !output){printf("argus error \n");return -1;}//�������
    char* pIn=input;
    char* pOut=output;
    int output_size=0;
//    cout<<input_size<<endl;
    while(input_size)
    {

         if(*pIn == '/' && *(pIn+1) == '/')
         {
            while(*pIn != '\n')
            {
                pIn++;
                input_size--;
                }
             pIn++;//�������з�
            input_size--;
            }
         else if(*pIn == '/' && *(pIn+1) == '*') {
             while (*pIn != '*' || *(pIn + 1) != '/') {
                 pIn++;
                 input_size--;
             }
             pIn += 2;
             input_size -= 2;
             if (*pIn == '\n')//����ע�Ϳ��Ļ��з�������еĻ���
             {
                 pIn++;
                 input_size--;
             }
         }
             else
             {
                 *(pOut++) = *(pIn++);
                 output_size++;
                 input_size--;
             }
        }
    *pOut = '\0';
    return output_size;
}

int main(int argc, const char *argv[]){

    cout<<argv[0]<<endl;
    fstream infile;
    infile.open("../../bishi/huya1.cpp");   //���ļ����������ļ���������

    char c;
    string buf;
    infile >> noskipws;
    while (!infile.eof())
    {
        infile>>c;
        buf.push_back(c);

    }
    infile.close();             //�ر��ļ�������
 /*   char *buffer;
    //Ҳ���Խ�buffer��Ϊ�������
    if((buffer = getcwd(NULL, 0)) == NULL)
    {
        perror("getcwd error");
    }
    else
    {
        printf("%s\n", buffer);
        free(buffer);
    }
 */
//
//    string filename;
//    cout << "Please enter name for a cpp file:" << endl;
//    cin >> filename;
//    ifstream fin;
//    try {
//        fin.open(filename.c_str());
//    } catch(std::exception &e)
//    {
//        cout << e.what() << endl;
//    }
//
//    if (fin.is_open())
//    {
//        cout << "Open " << filename << " successfully!" << endl;
//    } else{
//        cout<<"no file"<<endl;
//    }
//    char buf[102400];
//    int n = fin.readsome(buf, sizeof(buf));//read(buf, sizeof(buf));
//    if (n == -1) {
//        fin.close();
//    }


//    buf = argv[0];
//    printf("%s\n", buf.c_str());
    char b[buf.size()];
    RemoveComment((char*)(buf.c_str()),buf.size(),b);
    printf("%s",b);
    return 0;
    }

