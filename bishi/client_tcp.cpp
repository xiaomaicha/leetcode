//#include <WinSock2.h>
//#include <stdio.h>
//
//#pragma comment(lib, "ws2_32.lib")
//
//int main()
//{
//    //加载套接字
//    WSADATA wsaData;
//    char* buff = new char[1024];
//    memset(buff, 0, 1024);
//
//    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//    {
//        printf("Failed to load Winsock");
//        return 1;
//    }
//
//    SOCKADDR_IN addrSrv;
//    addrSrv.sin_family = AF_INET;
//    addrSrv.sin_port = htons(5099);
//    addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
//
//    //创建套接字
//    SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
//    if(SOCKET_ERROR == sockClient){
//        printf("Socket() error:%d", WSAGetLastError());
//        return 1;
//    }
//
//    //向服务器发出连接请求
//    if(connect(sockClient, (struct  sockaddr*)&addrSrv, sizeof(addrSrv)) == INVALID_SOCKET){
//        printf("Connect failed:%d", WSAGetLastError());
//        return 1;
//    }else
//    {
//        //接收数据
//        recv(sockClient, buff, sizeof(buff), 0);
//        printf("%s\n", buff);
//    }
//
//    //发送数据
//     buff = const_cast<char *>("hello, this is a Client....");
//    send(sockClient, buff, sizeof(buff), 0);
//
//    //关闭套接字
//    closesocket(sockClient);
//    WSACleanup();
//}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define MAXLINE 4096

int main(int argc, char** argv)
{
    int    sockfd, n;
    char    recvline[4096], sendline[4096];
    struct sockaddr_in    servaddr;

    if( argc != 2){
        printf("usage: ./client <ipaddress>\n");
        exit(0);
    }

    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    if( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
        printf("inet_pton error for %s\n",argv[1]);
        exit(0);
    }

    if( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0);
    }

    printf("send msg to server: \n");
    fgets(sendline, 4096, stdin);
    if( send(sockfd, sendline, strlen(sendline), 0) < 0)
    {
        printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    }

    close(sockfd);
    exit(0);
}