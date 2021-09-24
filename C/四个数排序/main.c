#include <stdio.h>
#include <stdlib.h>

int main(void)
{
     int a,b,c,d,t;
     a=3;b=1;c=2;d=4;
     if(a<b){t=a;a=b;b=t;}
     if(b<c){t=b;b=c;c=t;}
     if(c<d){t=c;c=d;d=t;}
     if(a<c){t=a;a=c;c=t;}
     if(a<b){t=a;a=b;b=t;}
     if(b<c){t=b;b=c;c=t;}
}
