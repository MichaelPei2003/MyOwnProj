#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "savefile.h"


int main(int argc,char *argv[])
{
    struct student stu[100];
    int cnt;
    cnt=LoadData(stu,100);
    AddStudent(stu,cnt);
    cnt+=1;
    deleteStudent(stu,cnt);
    SaveData(stu,cnt);
    return 0;
}
