/*
name: tangli
time: 2017/10/12/23/30
problem: ABalabcedContest
https://www.codechef.com/OCT17/problems/PERFCONT
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int prob,tot,sig;
        scanf("%d%d",&prob,&tot);

        int cake = 0, hard = 0;
        for(int i = 0; i < prob; i++)
        {
            scanf("%d",&sig);
            if(sig >= tot/2) cake++;
            else if(sig <= tot/10) hard++;
        }
        if(cake == 1 && hard == 2)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
