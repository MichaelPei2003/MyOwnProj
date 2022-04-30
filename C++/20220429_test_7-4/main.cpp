#include <string.h>
#include <iostream>
using namespace std;
class mystring
{
public:
    char a[10];
    char b[14];
    mystring()
    {
        cout<<"construct 0"<<endl;
    }
    mystring(char f[10])
    {
        for(int i=0;i<=9;i++)
        {
            a[i]=f[i];
        }
        cout<<"construct 1"<<endl;
    }
    mystring operator=(mystring& f)
    {
        strcat(b,f.a);
        cout<<b<<endl;
        return b;
    }
    ~mystring()
    {
        cout<<"destruct"<<endl;
    }
private:
    char * buf;
};
char b[14] = "c++";
int main()
{
    char a[10];
    cin>>a;
    mystring str1(a);
    cout<<str1.a<<endl;
    mystring str2;
    cout<<"c++"<<str1.a<<endl;
    system("pause");
    return 0;
}
