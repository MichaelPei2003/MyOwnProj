#include <stdio.h>
#include <stdlib.h>

int story1()
{
    char a[20],b[20],c[20],d[20];
    printf("请输入一个颜色：");
    scanf("%s",a);
    printf("\n请输入一个名词：");
    scanf("%s",b);
    printf("\n请输入一个地点（例如花丛）：");
    scanf("%s",c);
    printf("\n请输入一个人称代词：");
    scanf("%s",d);
    printf("从前，%s是一只小变色龙，%s挑食，只吃%s的食物。妈妈对%s说：“孩子，你可不能挑食，只吃%s色的%s，你就不会变别的颜色了。\
要是被抓，到时候就什么都晚了。”\n  有一天，%s躺在%s上，有一个小女孩走了过来，看到了%s，%s差一点就被抓了，%s扑到妈妈怀里哭。\
从此，%s再也不挑食了。",d,d,a,d,a,b,d,c,d,d,d,d);
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
            | 1.小故事1         2.小故事2        |\n\
            | 3.小故事3         4.退出           |\n\
            |注：2，3为空白                      |\n\
            |------------------------------------|\n");
    int a;
    printf("请输入:");
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
            default:printf("无效输入，请重新输入:");
        }
    }
}
