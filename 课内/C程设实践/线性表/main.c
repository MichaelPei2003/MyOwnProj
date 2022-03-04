#include <stdio.h>
#include <stdlib.h>

int languageValue;//LanguageValue: 1=CN 0=EN
int a[101]= {0};
int listLength=0;
int i, j;//for loops only

int CnMenu()
{
    languageValue = 1;
    printf("*****************顺序表本操作系统*****************\n");
    printf("* 1.创建顺序表                2.显示顺序表         *\n");
    printf("* 3.清空顺序表                4.顺序表排序         *\n");
    printf("* 5.按位置查找元素            6.按值查找元素       *\n");
    printf("* 7.指定位置插入元素          8.按位置删除元素     *\n");
    printf("* 9.按值删除元素              10.删除重复元素      *\n");
    printf("* 11.置逆顺序表               12.划分顺序表        *\n");
    printf("* 13.从文件导入顺序表         14.输出顺序表至文件  *\n");
    printf("* 15.最大平台                 16.退出              *\n");
    printf("*                                                  *\n");
    printf("*******************按0切换英文菜单******************\n\n");
    printf("Please Enter:");
    int tmp;
    scanf("%d", &tmp);
    Switch(tmp);
}

int EnMenu()
{
    languageValue = 0;
    printf("*****************SequenceListSystem*****************\n");
    printf("* 1.Create List               2.Show List          *\n");//49
    printf("* 3.Clear List                4.Sort List          *\n");//112
    printf("* 5.Search By Location        6.Search By Value    *\n");//118
    printf("* 7.Insert By Location        8.Delete By Location *\n");//170
    printf("* 9.Delete By Value           10.Delete Dulplicate *\n");//196
    printf("* 11.Reverse List             12.Partation List    *\n");//250
    printf("* 13.Import From File         14.Export To File    *\n");//279
    printf("* 15.Max Platform             16.Exit              *\n");//342
    printf("*                                                  *\n");
    printf("**************Press 0 For Chinese Menu**************\n\n");
    printf("Please Enter:");
    int tmp;
    scanf("%d",&tmp);
    Switch(tmp);
}

void CreateList()
{
    if(languageValue==1)
    {
        printf("请输入需要的顺序表长度（0~100）：");
    }
    else
    {
        printf("Please enter required length for the sequence list(0~100):");
    }
    scanf("%d",&listLength);
    for(i = 0; i < listLength; i++)
    {
        static unsigned int seed = 0;                 //
        seed++;                                       //
        srand((unsigned) time(NULL) + seed * seed);   //这里是生成真随机数
        a[i] = rand()%100;                            //
        if(a[i] == 0)
        {
            i--;
            continue;
        }
        printf("%-6d",a[i]);
        if((i+1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    MenuSelection();
}

void ShowList()
{
    if(a[0] == 0)
    {
        printf("EMPTY\nLength=0\n\n");
    }
    else
    {
        for(i=0; i<listLength; i++)
        {
            printf("%-6d", a[i]);
            if((i+1) % 10 == 0)
            {
                printf("\n");
            }
        }
        printf("\nLength=%d",listLength);
        printf("\n\n");
    }
    MenuSelection();
}

void ClearList()
{
    for(i=0; i<100; i++)
    {
        a[i] = 0;
    }
    MenuSelection();
}

void SortList()
{
    RevSort(0, listLength);
    ShowList();
}

void SearchByLoc()
{
    int target;
    if(languageValue == 1)
    {
        printf("请输入要查找的值的位置：");
    }
    else
    {
        printf("Please enter target location:");
    }
    scanf("%d", &target);
    printf("Value of target is: %d\n", a[target]);
    MenuSelection();
}

void SearchByVal()
{
    int target, tmp[101]= {0}, cnt=0;
    if(languageValue == 1)
    {
        printf("请输入要查找的值：");
    }
    else
    {
        printf("Please enter target value:");
    }
    scanf("%d", &target);
    for(i=0; i<listLength; i++)
    {
        if(a[i]==target)
        {
            tmp[cnt]=i;
            cnt++;
        }
    }
    if(cnt==0)
    {
        printf("Target value not found!");
    }
    else
    {
        printf("Target value found at location:");
        for(i=0; i<cnt; i++)
        {
            printf("%-4d", tmp[i]);
        }
    }
    printf("\n\n");
    MenuSelection();
}

void InsertByLoc()
{
    int value, location;
    if(listLength == 100)
    {
        printf("Maximum length reached!\n\n");
        MenuSelection();
    }
    if(languageValue == 1)
    {
        printf("请输入要插入值的位置以及值，‘值 位置’：");
    }
    else
    {
        printf("Please enter value and target location,'value location':");
    }
    scanf("%d %d",&value, &location);
    for(i=listLength-1; i>=location; i--)
    {
        a[i+1]=a[i];
    }
    listLength++;
    a[location]=value;
    ShowList();
}

void DelByLoc()
{
    int location;
    if(languageValue == 1)
    {
        printf("请输入要删除的项的位置：");
    }
    else
    {
        printf("Please enter target location to delete:");
    }
    scanf("%d", &location);
    for(i=listLength-1; i>location; i--)
    {
        a[i-1]=a[i];
    }
    listLength-=1;
    ShowList();
}

void DelByVal()
{
    int target, tmp1=0,tmp2=0, cnt=0;
    if(languageValue==1)
    {
        printf("请输入要删除的项的值：");
    }
    else
    {
        printf("Please enter target value:");
    }
    scanf("%d",&target);
    Delete(target);
    ShowList();
}

void DelDuplicate()
{
    for(i=0; i<listLength; i++)
    {
        for(j=i+1; j<listLength; j++)
        {
            if(a[i]==a[j])
            {
                a[j]=0;
            }
        }
    }
//    Debugger();
//    system("pause");
    Delete(0);
    ShowList();
}

void ReverseList()
{
    int tmp;
    for(i=0; i<listLength/2; i++)
    {
        tmp=a[i];
        a[i]=a[listLength-1-i];
        a[listLength-i-1]=tmp;
    }
    ShowList();
}

void PartitionList()
{
    int value, max=0, min=0, flag=0, tmp=0;
    if(languageValue==1)
    {
        printf("请输入划分位置：");
    }
    else
    {
        printf("Please enter partition value:");
    }
    scanf("%d",&value);
    RevSort(value+1, listLength);
    Sort(0, value);
    ShowList();
}

void ImportFromFile()
{
    if(languageValue=1)
    {
        printf("请输入文件地址：");
    }
    else
    {
        printf("Please enter file address:");
    }
    char n[20];
    scanf("%s",n);
    FILE *fp=NULL;
    fp=fopen(n, "r");
    if(fp==NULL)
    {
        printf("File not found!");
        ImportFromFile();
    }
    i=0;
    int tmp;
    while(!feof(fp))
    {
        fscanf(fp, "%d", &tmp);
        a[i]=tmp;
        i++;
        listLength++;
    }
    fclose(fp);
    ShowList();
}

void ExportToFile()
{
    if(languageValue=1)
    {
        printf("请输入文件地址：");
    }
    else
    {
        printf("Please enter file address:");
    }
    char n[20];
    scanf("%s", n);
    FILE *fp;
    fopen(n, "w");
    if(!(fp=fopen(n,"w")))
    {
        printf("Error!");
        ExportToFile();
    }
    for(i=0; i<listLength; i++)
    {
        fprintf(fp, "%-6d", a[i]);
        if((i+1) % 10 == 0)
        {
            fprintf(fp,"\n");
        }
    }
    fclose(fp);
    MenuSelection();
}

void MaxPlatform()
{
    int start, cnt1=0, cnt2=0, flag=-1, value=0;
    Sort(0, listLength);
//    Debugger();
    for(i=0; i<listLength; i++)
    {
        if(a[i+1]==a[i])
        {
            if(i==0)
            {
                start=0;
            }
            else if(a[i-1]!=a[i])
            {
                start=i;
            }
            if(a[i+2]!=a[i+1])
            {
                if(cnt1>cnt2)
                {
                    value=a[i];
                    flag=start;
                    cnt2=cnt1;
                    cnt1=0;
                }
            }
            else
            {
                cnt1++;
            }
        }
    }
    if(flag==-1||value==0)
    {
        printf("No platform in list!");
        MenuSelection();
    }
    printf("Max platform locates at:%d, platform value =%d.\n", flag, value);
    MenuSelection();
}

void MenuSelection()
{
    fflush(stdin);
    if(languageValue == 1)
    {
        CnMenu();
    }
    else
    {
        EnMenu();
    }
}

void Switch(int imput)//LanguageValue: 1=CN 0=EN
{
    switch(imput)
    {
    case 0:
        if(languageValue == 1)
        {
            EnMenu();
        }
        else
        {
            CnMenu();
        }
    case 1:
        CreateList();
    case 2:
        ShowList();
    case 3:
        ClearList();
    case 4:
        SortList();
    case 5:
        SearchByLoc();
    case 6:
        SearchByVal();
    case 7:
        InsertByLoc();
    case 8:
        DelByLoc();
    case 9:
        DelByVal();
    case 10:
        DelDuplicate();
    case 11:
        ReverseList();
    case 12:
        PartitionList();
    case 13:
        ImportFromFile();
    case 14:
        ExportToFile();
    case 15:
        MaxPlatform();
    case 16:
        exit(0);
    }
}

void Delete(int target)
{
    int cnt=0, tmp1, tmp2;
    for(i=0; i<listLength; i++)
    {
        if(a[i]==target)
        {
            cnt++;
        }
    }
    for(i=0; i<listLength;)
    {
        if(a[i]==target)
        {
            for(j=i; j<listLength-1; j++)
            {
                a[j]=a[j+1];
            }
            listLength--;
            cnt--;
            continue;
        }
        i++;
    }
}

void Sort(int start, int length)
{
    int max, flag, tmp=0, tag=0;
    for(i=start; i<length-1; i++)
    {
        flag = i;
        for(j=i+1; j<length; j++)
        {
            if(a[j]<a[flag])
            {
                flag=j;
            }
        }
        tmp=a[i];
        a[i]=a[flag];
        a[flag]=tmp;
    }
}

void RevSort(int start, int length)
{
    int max, flag, tmp=0, tag=0;
    for(i=start; i<length-1; i++)
    {
        flag = i;
        for(j=i+1; j<length; j++)
        {
            if(a[j]>a[flag])
            {
                flag=j;
            }
        }
        tmp=a[flag];
        a[flag]=a[i];
        a[i]=tmp;
    }
}

void Debugger()
{
    int tag = 0;
    for(i=0; i<listLength; i++)
    {
        printf("%-6d", a[i]);
        tag++;
        if(tag % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\nLength=%d",listLength);
    printf("\n\n");
}

int main()
{
    CnMenu();
}
