#include<bits/stdc++.h>

using namespace std;


void ChineseMenu()
{
	printf("\n\t�����ǲ˵�����������������\n");
	cout<<"1.������  2.������  3���� 4.�˳�"<<endl;
}

int main(void)
{
	int choice=0;
	while(choice!=24)
	{
		ChineseMenu();

		printf("\n\t��ѡ��");
		while( !scanf("%d", &choice) || (choice<1) || (choice>4) )
		{
			fflush(stdin); //�������buffer
			printf("\n\t������Ч�����������룺");
		}



		switch(choice)
		{
			case 1:
				printf("\n\t��ѡ����%d....", choice);
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
				printf("\n\t��ѡ����%d....\n", choice);
				cout<<"\t            #"<<endl;
				cout<<"\t           # #"<<endl;
				cout<<"\t          #   #"<<endl;
				cout<<"\t         #     #"<<endl;
				cout<<"\t        #       #"<<endl;
				cout<<"\t       ###########"<<endl;
				break;

			case 3:
				printf("\n\t��ѡ����%d....\n", choice);
				cout<<"\t        #"<<endl;
				cout<<"\t       # #"<<endl;
				cout<<"\t      #   #"<<endl;
				cout<<"\t     #     #"<<endl;
				cout<<"\t      #   #"<<endl;
				cout<<"\t       # #"<<endl;
				cout<<"\t        #"<<endl;
				break;

			case 4:
				printf("\n\t��ѡ����%d....", choice);
				printf("\n\tллʹ�ã��ټ���");
				exit(0);

			default:
				printf("\n\t������Ч��");
				break;
		}
	}
}

