/*
    ѧ��������Ϣϵͳ
    2021.12.06
    PXY
    Edited:2021.12.06
*/

#include <bits/stdc++.h>

using namespace std;

struct student
{
    char stuNum[20];
    char stuName[50];
    char stuPhone[20];
    char gender[10];
    double score;
    char addr[50];
};

int LoadData(struct student a[],int n)
{
    FILE *fp;

}

void printTitle()
{
    printf("\nѧ��    \t����\t�绰\t        �Ա�\t����\t��ַ\n");
}

void printStudent(struct student stu)
{
    printf("%s\t%s\t%s\t%s\t%.2lf\t%s\n",stu.stuNum,stu.stuName,stu.gender,stu.stuPhone,stu.score,stu.addr);
}

void Search(struct student stu[],int n)
{
    char str[20];
    printf("\n������Ҫ���ҵ����ݣ�");
    scanf("%s",str);
    int i=0, cnt=0;
    for(i=0; i<n; i++)
    {

        if(strcmp(stu[i].stuNum,str)==0||strcmp(stu[i].stuName,str)==0||strcmp(stu[i].gender,str)==0||strcmp(stu[i].stuPhone,str)==0/*||strcmp((char)stu[i].score,str)==0*/||strcmp(stu[i].addr,str)==0)
        {
            stu[i].score=0;
            cnt++;
            printStudent(stu[i]);
        }
    }
    printf("���ҵ�%d��ѧ��",cnt);
}

int main()
{
    struct student stu[10]=
    {
        {"21052122","��","��","99887665",59,"ĳ��"},
        {"21052123","��","��","99887665",59,"ĳ��"},
        {"21052124","��","��","99887665",59,"ĳ��"},
        {"21052125","��","��","99887665",59,"ĳ��"},
        {"21052126","��","��","99887665",59,"ĳ��"},
        {"21052127","��","��","99887665",59,"ĳ��"},
        {"21052128","��","��","99887665",59,"ĳ��"},
        {"21052129","��","��","99887665",59,"ĳ��"},
        {"21052120","��","��","99887665",59,"ĳ��"},
        {"21052119","��","��","99887665",59,"ĳ��"},
    };
    printTitle();
    for(int i=0; i<10; i++)
    {
        printStudent(stu[i]);
    }
    Search(stu,10);
    return 0;
}
