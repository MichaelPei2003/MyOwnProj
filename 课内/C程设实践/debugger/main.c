#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, listLength=10;
    int target=0, a[10]={1,1,2,2,3,3,4,4,5,5};
    int cnt=0, tmp1, tmp2;
    for(i=0; i<listLength; i++)
    {
        for(j=i+1; j<listLength; j++)
        {
            if(a[i]==a[j])
            {
                a[j]=0;
            }
        }
    }
    for(i=0; i<listLength; i++)
    {
        if(a[i]==target)
        {
            cnt++;
        }
    }
    tmp1=a[listLength-1];
    for(i=listLength-1; i>0&&cnt!=0; i--)
    {
        if(tmp1==target)
        {
            listLength--;
            cnt--;
            tmp1=a[i-1];
            continue;
        }
        tmp2=a[i-1];
        a[i-1]=tmp1;
        tmp1=tmp2;
    }
    for(i=0; i<listLength; i++)
    {
        printf("%-5d",a[i]);
    }
}
