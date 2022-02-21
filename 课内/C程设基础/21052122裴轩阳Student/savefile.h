#ifndef _SAVEFILE_H_
#define _SAVEFILE_H_

int SaveData(struct student s[],int n)
{
    FILE *fp=fopen("stu.txt","r+");
    if(!fp)
    {
        printf("�ļ���ʧ�ܣ�");
        return 0;
    }
    int i=0;
    for(i=0; i<n; i++)
    {
        fprintf(fp,"%s\t%s\t%s\t%d��%d��%d��\t%s\t%.2lf\t%s\n",
                s[i].stuNo,s[i].stuName,s[i].gender,s[i].birthday.year,
                s[i].birthday.month,s[i].birthday.day,s[i].stuPhone,
                s[i].score,s[i].addr);
    }

    printf("����%d�����ݵ������ļ�",n);
    fclose(fp);
}

#endif
