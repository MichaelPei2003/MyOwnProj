#include <stdio.h>
#include <stdlib.h>

int languageValue;//LanguageValue: 1=CN 0=EN

int CnMenu()
{
    languageValue = 1;
    printf("*****************˳����������ϵͳ*****************\n");
    printf("* 1.����˳���                2.��ʾ˳���         *\n");
    printf("* 3.���˳���                4.˳�������         *\n");
    printf("* 5.��λ�ò���Ԫ��            6.��ֵ����Ԫ��       *\n");
    printf("* 7.ָ��λ�ò���Ԫ��          8.��λ��ɾ��Ԫ��     *\n");
    printf("* 9.��ֵɾ��Ԫ��              10.ɾ���ظ�Ԫ��      *\n");
    printf("* 11.����˳���               12.����˳���        *\n");
    printf("* 13.���ļ�����˳���         14.���˳������ļ�  *\n");
    printf("* 15.���ƽ̨                 16.�˳�              *\n");
    printf("*                                                  *\n");
    printf("*******************��0�л�Ӣ�Ĳ˵�******************\n\n");
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
