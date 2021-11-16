#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[10];
    int m,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        if(m==0)
        {
            a[1]+="XXX";
            a[2]+="X.X";
            a[3]+="X.X";
            a[4]+="X.X";
            a[5]+="XXX";
        }
        if(m==1)
        {
            a[1]+="..X";
            a[2]+="..X";
            a[3]+="..X";
            a[4]+="..X";
            a[5]+="..X";
        }
        if(m==2)
        {
            a[1]+="XXX";
            a[2]+="..X";
            a[3]+="XXX";
            a[4]+="X..";
            a[5]+="XXX";
        }
        if(m==3)
        {
            a[1]+="XXX";
            a[2]+="..X";
            a[3]+="XXX";
            a[4]+="..X";
            a[5]+="XXX";
        }
        if(m==4)
        {
            a[1]+="X.X";
            a[2]+="X.X";
            a[3]+="XXX";
            a[4]+="..X";
            a[5]+="..X";
        }
        if(m==5)
        {
            a[1]+="XXX";
            a[2]+="X..";
            a[3]+="XXX";
            a[4]+="..X";
            a[5]+="XXX";
        }
        if(m==6)
        {
            a[1]+="XXX";
            a[2]+="X..";
            a[3]+="XXX";
            a[4]+="X.X";
            a[5]+="XXX";
        }
        if(m==7)
        {

        }
    }
}


