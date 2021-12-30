#include <stdio.h>
#include <stdlib.h>

struct birthday
    {
        int year;
        int month;
        int day;
    };

struct student
{
    char stuNum;
    char stuName;
    struct birthday birthday;
    char stuPhone;
    double score;
    char addr;
};

void LoadData(struct student a[],int n)
{
    n=100;
    FILE *fp=fopen("student.txt","r+");
    if(!fp)
    {
        printf("�ļ��򿪳���");
        return 0;
    }
    //�������һ�����������ݣ������ڣ�
    char oneLine[1024];
    fgets(oneLine,1024,fp);//���ļ�fp�ж�ȡ1024���ַ�
    int i=0,cnt;
    while((!feof(fp))&&(i<n))
    {
        if(fscanf(fp,"%s%s%s%d%d%d%s%lf%s",a[i].stuNum,a[i].stuName,a[i].birthday.year,a[i].birthday.month,a[i].birthday.day,a[i].stuPhone,a[i].score,a[i].addr)!=9)
        {
            break;
        }
        i++;
        cnt++;
    }
    fclose(fp);

}

int main()
{
    LoadData();
    return 0;
}
