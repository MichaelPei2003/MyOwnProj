#include <stdio.h>
#include <stdlib.h>

int story1()
{
    char a[20],b[20],c[20],d[20];
    printf("������һ����ɫ��");
    scanf("%s",a);
    printf("\n������һ�����ʣ�");
    scanf("%s",b);
    printf("\n������һ���ص㣨���绨�ԣ���");
    scanf("%s",c);
    printf("\n������һ���˳ƴ��ʣ�");
    scanf("%s",d);
    printf("��ǰ��%s��һֻС��ɫ����%s��ʳ��ֻ��%s��ʳ������%s˵�������ӣ���ɲ�����ʳ��ֻ��%sɫ��%s����Ͳ��������ɫ�ˡ�\
Ҫ�Ǳ�ץ����ʱ���ʲô�����ˡ���\n  ��һ�죬%s����%s�ϣ���һ��СŮ�����˹�����������%s��%s��һ��ͱ�ץ�ˣ�%s�˵����軳��ޡ�\
�Ӵˣ�%s��Ҳ����ʳ�ˡ�",d,d,a,d,a,b,d,c,d,d,d,d);
}

int story2()
{

}

int story3()
{

}

int main(void)
{
     printf("|----------------menu----------------|\n\
            | 1.С����1         2.С����2        |\n\
            | 3.С����3         4.�˳�           |\n\
            |ע��2��3Ϊ�հ�                      |\n\
            |------------------------------------|\n");
    int a;
    printf("������:");
    for(;;)
    {
        scanf("%d",&a);
        printf("\n");
        switch (a)
        {
            case 1:story1();break;
            case 2:story2();break;
            case 3:story3();break;
            case 4:exit(0);
            default:printf("��Ч���룬����������:");
        }
    }
}
