#ifndef _STUDENT_H_
#define _STUDENT_H_

struct Date
{
    int year;
    int month;
    int day;
};

struct student
{
    char stuNo[20];
    char stuName[50];
    char gender[10];

    struct Date birthday;

    char stuPhone[20];
    double score;
    char addr[50];
};

void printStudent(struct student stu)
{
    printf("%s\t%s\t%s\t%d年%d月%d日\t%s\t%.2lf\t%s\n",
           stu.stuNo,stu.stuName,stu.gender,stu.birthday.year,
           stu.birthday.month,stu.birthday.day,stu.stuPhone,
           stu.score,stu.addr);
}

void printAllStudent(struct student stu[], int n)
{
    for(int i=0;i<n;i++)
    {
        printStudent(stu[i]);
    }
}

int LoadData(struct student a[],int n)
{
    FILE *fp=fopen("stu.txt","r+");
    if(!fp)
    {
        printf("文件读取失败！");
        return 0;
    }
    char oneLine[1024];
    fgets(oneLine,1024,fp);
    int i=0,cnt=0;
    while(!feof(fp)&&i<n)
    {
        if(fscanf(fp,"%s%s%s%d%d%d%s%lf%s",a[i].stuNo,a[i].stuName,a[i].gender,&a[i].birthday.year,&a[i].birthday.month,&a[i].birthday.day,a[i].stuPhone,&a[i].score,a[i].addr)!=9)
        {
            break;
        }
        i++;
        cnt++;
    }
    for(i=0; i<cnt; i++)
    {
        printStudent(a[i]);
    }
    printf("共导入了%d个学生\n\n",cnt);
    fclose(fp);
    return cnt;
}

int AddStudent(struct student s[], int n)
{
    printf("\n\t开始添加学生\n");
    printf("\n请输入学号：");
    scanf("%s",s[n].stuNo);
    printf("\n请输入姓名：");
    scanf("%s",s[n].stuName);
    printf("\n请输入性别：");
    scanf("%s",s[n].gender);
    printf("\n请输入出生日期(yyyy mm dd)：");
    scanf("%d%d%d",&s[n].birthday.year,&s[n].birthday.month,&s[n].birthday.day);
    printf("\n请输入手机号：");
    scanf("%s",s[n].stuPhone);
    printf("\n请输入分数：");
    scanf("%lf",&s[n].score);
    printf("\n请输入地址：");
    scanf("%s",s[n].addr);
    printAllStudent(s,n+1);
    }

int deleteStudent(struct student s[], int n)
{
    char str[20];
    printf("开始删除学生\n请输入学号：");
    scanf("%s",str);
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].stuNo,str)==0)
        {
            for(j=i;j<n;j++)
            {
                s[j]=s[j+1];
            }
        }
    }
    printf("删除学生成功，当前学生列表为：\n");
    printAllStudent(s,n-1);
}

#endif
