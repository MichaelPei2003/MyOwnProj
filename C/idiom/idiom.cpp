#include "idiom.h"			//�Խ�ͷ�ļ����Զ��岢ʵ�ֺ�������ǿ����� 
#include<bits/stdc++.h>		//��Ҫʹ�����е�time.h iostream ��ͷ�ļ������� 
//#include <time.h>			//ʵ�ּ�ʱ����
//#include <iostream>		//ʵ��C++������������� 
//#include <stdio.h>		//ʵ��C���Ե������������
//#include <vector>			//ʵ��c++�е�����
//#include <cstring>		//ʵ��c++�е�string�� 
#include <conio.h>			//��Ҫʹ������_getstr������ȡ����̨�е����ַ� 
#include <Windows.h>		//ʵ���������� 

using namespace std;

vector<string> idiom;       //��������λ��data.txt�еĳ���
vector<string> correct;     //������Ϸ��������һش���ȷ�ĳ���
vector<string> wrong;       //������Ϸ��������һش����ĳ���

time_t startTime, endTime;  //�ֱ����ʼʱ��ͽ���ʱ�䣬���ڼ�ʱ
int lastTime = 0;           //�������ʱ��

void GotoXY(int x, int y) {
    HANDLE hout;
    COORD cor;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    cor.X = x;
    cor.Y = y;
    SetConsoleCursorPosition(hout, cor);
}

void Hide() {
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//PXY EDITED
int LevelSelection() {
    GotoXY(40, 4);
    cout << "��ѡ���Ѷ�";
    GotoXY(40, 6);
    cout << "�򵥣�1��";
    GotoXY(40, 8);
    cout << "���ѣ�2��";
    GotoXY(40, 10);
    Hide();
    char level = _getch();
    GotoXY(40, 12);
    cout << "��ѡ���Ѷ�" << level;
    GotoXY(40, 14);
    cout << "���������ʼ��Ϸ";
    char ch = _getch();
    system("cls");
    switch (level) {
        case '1':
            return 1;
        case '2':
            return 2;
    }
}

bool GameStart2() {
    int pos;
    int lack;
    GotoXY(WID + 16, 2);
    printf("��ǰ������ʱ:%d.00s", lastTime);
    GotoXY(WID + 16, 4);
    printf("�ش���ȷ�ĸ���:%d", correct.size());
    GotoXY(WID + 16, 6);
    printf("�ش����ĸ���:%d", wrong.size());
    GotoXY(WID + 16, 10);
    printf("��ǰ�÷�:%d", correct.size() * 5);
    srand(time(0));
    lack = rand() % 3;                      //��ȥλ��(1)
    GotoXY(WID / 2 - 1, HEIGHT / 2 - 1);            //���ó������λ��������
    pos = IdiomChoose();                    //ȡ��idiom�е�������
    cout << "|" << idiom[pos] << "|";                //�����Ŵ���ֵ(����ȥֵ��)
    GotoXY(WID / 2 + lack * 2, HEIGHT / 2 - 1);        //��λ������ո�
    cout << "    ";                         //Compared with level 1, 1 more character hidden
    GotoXY(WID / 2 - 5, HEIGHT / 2 + 5);
    cout << "��Ĵ���:                 ";
    GotoXY(WID / 2 - 5, HEIGHT / 2 + 5);
    cout << "��Ĵ���:";
    string ch;
    cin >> ch;
    //����ڳ������ҵ�����ϵı����������ȷ
    GotoXY(WID / 2 - 2, HEIGHT / 2 + 8);
    if (ch.length() != 4) {                                    //Wrong length -> go straight to wrong
        printf("���ˣ���ȷ�𰸣�");
        cout << idiom[pos];
        wrong.push_back(idiom[pos]);                           //������Ĵ�����wrong������
    } else {
        if (idiom[pos].substr(2 * lack, 4).find(ch) != string::npos) {
            printf("��ȷ���������                 ");
            correct.push_back(idiom[pos]);//����ȷ�Ĵ�����correct������
        } else {
            printf("���ˣ���ȷ�𰸣�");
            cout << idiom[pos];        //������Ĵ�����wrong������
            wrong.push_back(idiom[pos]);
        }
    }
    endTime = time(NULL);                            //���µ�ǰʱ��
    lastTime = difftime(endTime, startTime);                //���µ�ǰ����ʱ��
    idiom.erase(idiom.begin() + pos);                //��idiom��ɾȥ��ǰ��������ظ�ѡȡ
    int allq;
    allq = 50 - idiom.size();                    //allq�����Ѿ����ֵ���Ŀ����
    if (allq == 50 || correct.size() == 20) return false;  //�Ѿ�����50����ߵ÷�100���˳�
    return true;
}
//END OF PXY EDITED


int Menu() {
	GotoXY(38,4);
	cout<<"��ӭ��������������С��Ϸ";
    GotoXY(44, 10);
    printf("1.��ʼ��Ϸ");
    GotoXY(46, 12);
    printf("2.����");
    GotoXY(46, 14);
    printf("3.����");
	GotoXY(34, 24);
	printf("**��Ϸ;�а�����Q/q����ʱ�˳���Ϸ**");
    GotoXY(40, 22);
    printf("����������˳���Ϸ");
    Hide();
    char ch;
    int result = 0;
    ch = _getch();
    printf("%c", ch);
    switch(ch){
        case '1': result = 1; break;
        case '2': result = 2; break;
        case '3': result = 3; break;
    }
    printf("choose finish");
    system("cls");
	return result;
}

void Help() {
    GotoXY(34, 14);
    printf("������ȱ����������ȷ�ĺ��ּ��ɹ���");
    GotoXY(40, 26);
    printf("������������ϼ��˵�");
    Hide();
    char ch = _getch();
    system("cls");
}

void About() {
    GotoXY(30, 4);
    printf("���ݵ��ӿƼ���ѧ�����ѧԺ��ĩ�γ�ʵ������");
    GotoXY(43, 10);
    printf("������������Ϸ");
    GotoXY(40, 26);
    printf("������������ϼ��˵�");
    Hide();
    char ch = _getch();
    system("cls");
}

void IdiomRead() {
    ifstream ifs;       //���ļ������ж��Ƿ�򿪳ɹ�
    ifs.open("data.txt", ios::in);
    if (!ifs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //������
    string s;
    while (ifs >> s) idiom.push_back(s);
    //�ر��ļ�
    //cout<<idiom[0];
    ifs.close();
}

int IdiomChoose() {
    int size = idiom.size();
    int k;
    srand(time(0));
    k = rand() % size;        //���ѡȡһ��������
    return k;                   //���ر��
}

//��ʼ����Ϸ��������
//������ͼ��ܣ��ش���ȷ��ش����ĸ��� 
void InitMap() {
    Hide();
    for (int i = 0; i < HEIGHT; i++) {
        GotoXY(0, i);
        printf("=");
        GotoXY(WID + 13, i);
        printf("=");
    }
    for (int i = 0; i < WID + 14; i++) {
        GotoXY(i, 0);
        printf("=");
        GotoXY(i, HEIGHT);
        printf("=");
    }
    GotoXY(WID + 16, 2);
    printf("��ǰ������ʱ:0");
    GotoXY(WID + 16, 4);
    printf("�ش���ȷ�ĸ���:0");
    GotoXY(WID + 16, 6);
    printf("�ش����ĸ���:0");
    GotoXY(WID + 16, 10);
    printf("��ǰ�÷�:0");
    startTime = time(NULL);
    endTime = time(NULL);
}

bool GameStart() {
    int pos;
    int lack;
    GotoXY(WID + 16, 2);
    printf("��ǰ������ʱ:%d.00s", lastTime);
    GotoXY(WID + 16, 4);
    printf("�ش���ȷ�ĸ���:%d", correct.size());
    GotoXY(WID + 16, 6);
    printf("�ش����ĸ���:%d", wrong.size());
    GotoXY(WID + 16, 10);
    printf("��ǰ�÷�:%d", correct.size() * 5);
    srand(time(0));
    lack = rand() % 4;                      //��ȥλ��(1)
    //srand(time(0));
    GotoXY(WID / 2 - 1, HEIGHT / 2 - 1);            //���ó������λ��������
    pos = IdiomChoose();                    //ȡ��idiom�е�������
    cout << "|" << idiom[pos] << "|";                //�����Ŵ���ֵ(����ȥֵ��)
    GotoXY(WID / 2 + lack * 2, HEIGHT / 2 - 1);        //��λ������ո�
    cout << "  ";
    GotoXY(WID / 2 - 5, HEIGHT / 2 + 5);
    cout << "��Ĵ���:            ";
    GotoXY(WID / 2 - 5, HEIGHT / 2 + 5);
    cout << "��Ĵ���:";
    string ch;
    cin >> ch;
    //����ڳ������ҵ�����ϵı����������ȷ
    GotoXY(WID / 2 - 2, HEIGHT / 2 + 8);
    //PXY EDITED
    if (ch.length() != 2) {                                    //Wrong length -> go straight to wrong
        printf("���ˣ���ȷ�𰸣�");
        cout << idiom[pos];
        wrong.push_back(idiom[pos]);                           //������Ĵ�����wrong������
    } else {
        if (idiom[pos].substr(2 * lack, 2).find(ch) != string::npos) {
            printf("��ȷ���������                 ");
            correct.push_back(idiom[pos]);//����ȷ�Ĵ�����correct������
        } else {
            printf("���ˣ���ȷ�𰸣�");
            cout << idiom[pos];        //������Ĵ�����wrong������
            wrong.push_back(idiom[pos]);
        }
    }
    //END OF PXY EDITED
    endTime = time(NULL);                            //���µ�ǰʱ��
    lastTime = difftime(endTime, startTime);                //���µ�ǰ����ʱ��
    idiom.erase(idiom.begin() + pos);                //��idiom��ɾȥ��ǰ��������ظ�ѡȡ
    int allq;
    allq = 50 - idiom.size();                    //allq�����Ѿ����ֵ���Ŀ����
    if (allq == 50 || correct.size() == 20) return false;  //�Ѿ�����50����ߵ÷�100���˳�
    return true;
}

void Result()
{
	system("cls");
	GotoXY(20,4);
	if(correct.size()==20)
	{
		cout<<"��Ϸ�ɹ�";
	}
	else
	{
		cout<<"��Ϸʧ��";
	}
	GotoXY(4,10);
	cout<<"|����б�|";
	GotoXY(4, 12);
	int sz=correct.size();
	int printPos;                       //��ӡλ��
	for(int i=0;i<sz;i++)
	{
		cout<<correct[i]<<"  ";
		if((i+1)%3==0)        //ÿ��������ͻ���
		{
			GotoXY(4,12+2*(i/3));
		}
	}
	GotoXY(35, 10);
	cout<<"|����б�|";
	GotoXY(35, 12);
	sz=wrong.size();
	for(int i=0;i<sz;i++)
	{
		cout<<wrong[i]<<"  ";
		if((i+1)%3==0)        //ÿ��������ͻ���
		{
			GotoXY(35,12+2*(i/3));
		}
	}
	char ch;
	GotoXY(18,23);
	cout<<"��������ص��˵�";
	GotoXY(0,0);
	ch=getchar();
	ch=getchar();
	system("cls");
}

void color(short x)	//�Զ��庯���ݲ����ı���ɫ
{
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ
    else//Ĭ�ϵ���ɫ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

