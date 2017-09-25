/*
Author: TangLi
Time: 17/9/25
Problem: L - Three Square Gym - 101291L
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct NU
{
    int l,h;
}nu[3];

bool cmp(NU a,NU b)
{
    if(a.h==b.h) return a.l<b.l;
    else return a.h<b.h;
}
int main()
{
    //while(1)
    //{
        for(int i=0; i<3; i++)
        {
            cin>>nu[i].l>>nu[i].h;
            if(nu[i].l>nu[i].h) swap(nu[i].l,nu[i].h);
        }
        sort(nu,nu+3,cmp);

        //for(int i=0; i<3; i++)
        //    cout<<nu[i].l<<" "<<nu[i].h<<endl;

        bool ok=false;
        if(nu[0].h==nu[1].h && nu[1].h==nu[2].h && (nu[0].l+nu[1].l+nu[2].l)==nu[0].h) ok=1;
        else if(nu[0].h==nu[1].h && (nu[0].l+nu[1].l)==nu[2].h && (nu[0].h+nu[2].l)==nu[2].h) ok=1;
        else if(nu[0].h==nu[1].l && (nu[0].l+nu[1].h)==nu[2].h && (nu[0].h+nu[2].l)==nu[2].h) ok=1;
        else if(nu[0].l==nu[1].h && (nu[0].h+nu[1].l)==nu[2].h && (nu[0].l+nu[2].l)==nu[2].h) ok=1;
        else if(nu[0].l==nu[1].l && (nu[0].h+nu[1].h)==nu[2].h && (nu[0].l+nu[2].l)==nu[2].h) ok=1;

        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    //}


    return 0;
}
