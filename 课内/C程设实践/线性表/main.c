#include <stdio.h>
#include <stdlib.h>

int languageValue;//LanguageValue: 1=CN 0=EN

int CnMenu()
{
    languageValue = 1;
    printf("*****************顺序标基本操作系统*****************\n");
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
    scanf("%d",&tmp);
    Switch(tmp);
}

int EnMenu()
{
    languageValue = 0;
    printf("*****************SequenceListSystem*****************\n");
    printf("* 1.Create List               2.Show List          *\n");
    printf("* 3.Clear List                4.Sort List          *\n");
    printf("* 5.Search By Location        6.Search By Value    *\n");
    printf("* 7.Insert By Location        8.Delete By Location *\n");
    printf("* 9.Delete By Value           10.Delete Dulplicate *\n");
    printf("* 11.Reverse List             12.Partation List    *\n");
    printf("* 13.Import From File         14.Export To File    *\n");
    printf("* 15.Max Platform             16.Exit              *\n");
    printf("*                                                  *\n");
    printf("**************Press 0 For Chinese Menu**************\n\n");
    printf("Please Enter:");
    int tmp;
    scanf("%d",&tmp);
    Switch(tmp);
}

void CreateList()
{

}

void ShowList()
{

}

void ClearList()
{

}

void SortList()
{

}

void SearchByLoc()
{

}

void SearchByVal()
{

}

void InsertByLoc()
{

}

void DelByLoc()
{

}

void DelByVal()
{

}

void DelDuplicate()
{

}

void ReverseList()
{

}

void PartitionList()
{

}

void ImportFromFile()
{

}

void ExportToFile()
{

}

void MaxPlatform()
{

}

void MenuSelection()
{
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
    switch(imput){
        case 0: if(languageValue == 1)
                    {EnMenu();}
                else
                    {CnMenu();}
        case 1: CreateList();
        case 2: ShowList();
        //case 3:
    }
}

int main()
{
    CnMenu();
}
