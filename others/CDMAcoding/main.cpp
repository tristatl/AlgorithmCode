/*
name: tangli
time: 2017/10/25
problem: CDMA����
**�����ж�5��8λ����ƬM1��M2��M3��M4��M5�Ƿ񻥲�����
**java ���ڵ���CDMAcoding.java
*/
#include <iostream>

using namespace std;
int* change(int n)  //ʮ����ת�����ƣ����ڳ�ʼ����Ƭ
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
bool judge(int *a,int *b) //�ж������������λ��˺�Ϊ0�򷵻�1
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
        num[i]=change(i);  //��ʼ����Ƭ
    }
    for(int i=0;i<256;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(num[i][j]==0)
                num[i][j]=-1;  //��0��ת��Ϊ-1
        }
    }
    int m[5]; //�����û���������5������
    int *M[5]; //���û������5������ת��Ϊ��Ӧ����Ƭ
    int flag;
    do{
        flag=0;
        cout<<"���������5��0��255������"<<endl;
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
                        cout<<"�����"<<i<<"��"<<j<<"�����Ƭ�������ģ�����������"<<endl;
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
    cout<<"ʵ��������:"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"��"<<i+1<<"����Ƭ��������"<<endl;
        for(int p=0;p<8;p++)
            cout<<M[i][p]<<" "<<endl;
        cout<<endl;
        cout<<"���"<<i+1<<"����Ƭ������Ƭ���� ��"<<endl;
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
        cout<<"���"<<i+1<<"����Ƭ�������� "<<c[i]<<" ��"<<endl;
    }
//   for(int i=0;i<256;i++){
//        for(int j=0;j<8;j++)
//            cout<<num[i][j]<<" ";
//        cout<<endl;
//   }
    return 0;
}
