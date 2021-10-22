#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    char a[200];
    int t=0;
    cin>>a;
    for(a=0;a<=210;a++)
    {
        switch(a)
        {
            case 'a':t+=1;break;
            case 'b':t+=2;break;
            case 'c':t+=3;break;
            case 'd':t+=1;
        }
    }
}
