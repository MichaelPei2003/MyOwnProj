#include <bits/stdc++.h>
#define PI 3.14

using namespace std;

struct point
{
    double x;
    double y;
    double z;
};//�˴��ֺ�������

//ֱ�Ӷ��ַ������鸳ֵ��strcpy(a,"111111");���У�char a

/*int main(int argc, char *argv[])
{
    //��̬�ڴ����
    int *p,n;
    while(n!=888)
    {
        printf("\n������ռ��С������888�˳���");
        struct point a={1.0,2.0,3.0};
        while(!scanf("%d",&n)||n<1)
        {
            fflush(stdin);
            printf("��Ч���룡");
        }
        //int a[n] ���﷨��C�в���ʹ��
        p=(int*)malloc(n*sizeof(int));//����100*sizeof(int)���ȵ��ڴ�
        if(p==NULL)
        {
            printf("�ڴ����ʧ�ܣ�");
            exit(1);//ͨʶ��������������ʱ����0��������ʱ���ط���
        }
        else
        {
            printf("�ڴ����ɹ���\n");
        }
        for(int i=0; i<n; i++)
        {
            *(p+i)=i;
        }
        for(int i=0; i<n; i++)
        {
            printf("%5d ",*(p+i));
        }
        free(p);//�ͷŷ����p���ڴ�
    }
    return 0;
}
*/

struct circle
{
    float r;
    float d;
    float c;
    float s;
};

int main(void)
{
    struct circle a;
    cout<<"R=";
    cin>>a.r;
    a.d=2*a.r;
    a.c=2*PI*a.r;
    a.s=PI*a.r*a.r;
    printf("\n԰�İ뾶Ϊ%f��ֱ��Ϊ%f���ܳ�Ϊ%f�����Ϊ%f",a.r,a.d,a.c,a.s);
}
