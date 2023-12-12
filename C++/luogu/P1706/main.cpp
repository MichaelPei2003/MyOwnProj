#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n,i,j;
    j=1;
    cin>>n;
    int a[n]={0};
    for(i=0;i<=n-1;i++){
        a[i]=i+1;
        j*=(i+1);
    }
    for(i=0;i<=j-1;i++){
        for(int k=0;k<=n-1;k++){
            cout<<"    "<<a[k];
        }
        next_permutation(a,a+n);
        cout<<endl;
    }
}
