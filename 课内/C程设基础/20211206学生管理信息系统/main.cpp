/*
    学生管理信息系统
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
    printf("\n学号    \t姓名\t电话\t        性别\t分数\t地址\n");
}

void printStudent(struct student stu)
{
    printf("%s\t%s\t%s\t%s\t%.2lf\t%s\n",stu.stuNum,stu.stuName,stu.gender,stu.stuPhone,stu.score,stu.addr);
}

void Search(struct student stu[],int n)
{
    char str[20];
    printf("\n请输入要查找的内容：");
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
    printf("共找到%d个学生",cnt);
}

int main()
{
    struct student stu[10]=
    {
        {"21052122","我","男","99887665",59,"某地"},
        {"21052123","我","男","99887665",59,"某地"},
        {"21052124","我","男","99887665",59,"某地"},
        {"21052125","我","男","99887665",59,"某地"},
        {"21052126","我","男","99887665",59,"某地"},
        {"21052127","我","男","99887665",59,"某地"},
        {"21052128","我","男","99887665",59,"某地"},
        {"21052129","我","男","99887665",59,"某地"},
        {"21052120","我","男","99887665",59,"某地"},
        {"21052119","我","男","99887665",59,"某地"},
    };
    printTitle();
    for(int i=0; i<10; i++)
    {
        printStudent(stu[i]);
    }
    Search(stu,10);
    return 0;
}
