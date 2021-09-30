#include <iostream>

using namespace std;

int main()
{
    char a[110];
    cin>>a;
    for(int i=0;i<=100;i++)
    {
        if ('a'<=a[i]&&a[i]<='z')
        {
            a[i]-='a'-'A';
        }
    }
    cout<<a<<endl;
}
