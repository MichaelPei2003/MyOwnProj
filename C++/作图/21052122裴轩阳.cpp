#include<bits/stdc++.h>

using namespace std;


void ChineseMenu()
{
	printf("\n\t这里是菜单。。。。。。。。\n");
	cout<<"1.正方形  2.三角形  3菱形 4.退出"<<endl;
}

int main(void)
{
	int choice=0;
	while(choice!=24)
	{
		ChineseMenu();

		printf("\n\t请选择：");
		while( !scanf("%d", &choice) || (choice<1) || (choice>4) )
		{
			fflush(stdin); //清空输入buffer
			printf("\n\t输入无效，请重新输入：");
		}



		switch(choice)
		{
			case 1:
				printf("\n\t你选择了%d....", choice);
				printf("\n\t########################");
				printf("\n\t#                      #");
				printf("\n\t#                      #");
				printf("\n\t#                      #");
				printf("\n\t#                      #");
				printf("\n\t#                      #");
				printf("\n\t#                      #");
				printf("\n\t#                      #");
				printf("\n\t#                      #");
				printf("\n\t########################");

				break;

			case 2:
				printf("\n\t你选择了%d....\n", choice);
				cout<<"\t            #"<<endl;
				cout<<"\t           # #"<<endl;
				cout<<"\t          #   #"<<endl;
				cout<<"\t         #     #"<<endl;
				cout<<"\t        #       #"<<endl;
				cout<<"\t       ###########"<<endl;
				break;

			case 3:
				printf("\n\t你选择了%d....\n", choice);
				cout<<"\t        #"<<endl;
				cout<<"\t       # #"<<endl;
				cout<<"\t      #   #"<<endl;
				cout<<"\t     #     #"<<endl;
				cout<<"\t      #   #"<<endl;
				cout<<"\t       # #"<<endl;
				cout<<"\t        #"<<endl;
				break;

			case 4:
				printf("\n\t你选择了%d....", choice);
				printf("\n\t谢谢使用，再见！");
				exit(0);

			default:
				printf("\n\t输入无效。");
				break;
		}
	}
}

