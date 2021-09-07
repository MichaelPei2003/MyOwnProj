#include <stdio.h>
#include <math.h>
#define INF 1000000000
int main ()
{
   double n, m;
   double icase = 0;
   double sum;
   while(scanf("%lf %lf", &n, &m)&&!(m == n && m == 0))
   {
        icase++;
        sum = 0;
        for(double a = n;a <= m;a++)
        {
            sum += 1.0/pow(a,2.0);
        }
        printf("case %d = %.5lf\n",icase,sum);

   }
    return 0;
}
