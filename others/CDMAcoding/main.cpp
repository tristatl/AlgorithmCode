/*
name: tangli
time: 2017/10/25
problem: CDMA编码
**用于判断5个8位的码片M1、M2、M3、M4、M5是否互不正交
**java 用于调试CDMAcoding.java
*/
#include <iostream>

using namespace std;
int* change(int n)  //十进制转二进制，用于初始化码片
{
    int *ch=new int[8];
    for(int i=0;i<8;i++)
        ch[i]=0;
    int i=0;
    while(n)
    {
        ch[i]=n%2;
        n/=2;
        i++;
    }
    return ch;
}
bool judge(int *a,int *b) //判断正交，如果各位相乘和为0则返回1
{
    int sum=0;
    /*
    cout <<"a"<<" ";
    for(int i=0;i<8;i++)
        cout << a[i];
    cout<<endl;
    cout<<"b"<<" ";
    for(int i=0;i<8;i++)
        cout << b[i];
    cout<<endl;
    cout<<"sum"<<endl;
    */
    for(int i=0;i<8;i++)
    {
        sum+=a[i]*b[i];
        //cout<<sum<<" ";
    }
    //cout<<endl;
    if(sum==0)
        return 1;
    else
        return 0;

}
int main()
{
    int *num[256];
    for(int i=0;i<256;i++)
    {
        num[i]=change(i);  //初始化码片
    }
    for(int i=0;i<256;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(num[i][j]==0)
                num[i][j]=-1;  //将0都转化为-1
        }
    }
    int m[5]; //接受用户随机输入的5个整数
    int *M[5]; //将用户输入的5个整数转化为相应的码片
    int flag;
    do{
        flag=0;
        cout<<"请随机输入5个0到255的整数"<<endl;
        for(int i=0;i<5;i++)
        {
            cin>>m[i];
            int temp=m[i];
            M[i]=num[temp];
        }
        for(int i=0;i<5;i++)
        {
            for(int j=i+1;j<5;j++)
            {
                //cout << judge(M[i],M[j]) << endl;
                    if(judge(M[i],M[j]))
                    {
                        flag=1;
                        cout<<"输入的"<<i<<"和"<<j<<"随机码片有正交的，请重新输入"<<endl;
                        break;
                    }

            }
            if(flag==1)
            {
                cout<<"flag"<<endl;
                break;
            }

        }
    }while(flag);
//    for(int i=0;i<5;i++)
//    {
//        for(int j=0;j<8;j++)
//            cout<<M[i][j]<<" ";
//        cout<<endl;
//    }
    int c[5]={0};
    cout<<"实验结果如下:"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"第"<<i+1<<"个码片序列如下"<<endl;
        for(int p=0;p<8;p++)
            cout<<M[i][p]<<" "<<endl;
        cout<<endl;
        cout<<"与第"<<i+1<<"个码片正交码片如下 ："<<endl;
        for(int j=0;j<256;j++)
        {

            if(judge(num[j],M[i]))
            {
                c[i]++;
                if(c[i]<=10)
                    {
                        for(int k=0;k<8;k++)
                            cout<<num[j][k]<<" ";
                        cout<<endl;
                    }
            }
        }
        cout<<"与第"<<i+1<<"个码片正交的有 "<<c[i]<<" 个"<<endl;
    }
//   for(int i=0;i<256;i++){
//        for(int j=0;j<8;j++)
//            cout<<num[i][j]<<" ";
//        cout<<endl;
//   }
    return 0;
}
