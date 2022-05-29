//
// Created by 19832 on 2022/5/28.
//
#include "idiom.h"
#include<bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

vector<string> idiom;
vector<string> correct;
vector<string> wrong;

void GotoXY(int x, int y){
    HANDLE hout;
    COORD cor;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    cor.X = x;
    cor.Y = y;
    SetConsoleCursorPosition(hout, cor);
}

void Hide(){
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int Menu(){
    GotoXY(40,4);
    printf("��ӭ��������������С��Ϸ");
    GotoXY(43, 10);
    printf("1.��ʼ��Ϸ");
    GotoXY(43, 12);
    printf("2.����");
    GotoXY(43, 14);
    printf("3.����");
    GotoXY(40, 20);
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

void Help(){
    GotoXY(34, 14);
    printf("������ȱ����������ȷ�ĺ��ּ��ɹ���");
    GotoXY(40, 26);
    printf("������������ϼ��˵�");
    Hide();
    char ch = _getch();
    system("cls");
}

void About(){
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

void IdiomRead(){
    ifstream ifs;       //���ļ������ж��Ƿ�򿪳ɹ�
    ifs.open("data.txt",ios::in) ;
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

int IdiomChoose(){
    int size = idiom.size();
    int k;
    srand(time(0));
    k = rand() % size;        //���ѡȡһ��������
    return k;                   //���ر��
}

//��ʼ����Ϸ��������
void InitMap(){
    Hide();


}

bool GameStart(){
    int pos;
    int lack;
    lack = rand() % 4 + 1;                      //��ȥλ��(1)
    srand(time(0));
    GotoXY(WID/2-1, HEIGHT/2-1);          //���ó������λ��������
    pos = IdiomChoose();                       //ȡ��idiom�е�������
    //�����Ŵ���ֵ(����ȥֵ��)
    //printf("%d %d", lack, pos);
    char id[5];
    strcpy(id,idiom[pos].c_str());
    //cout<<idiom[pos];
    for(int i = 0; i < 4; i++){
        if(i == lack) printf("1");
        else printf("%c", id[i]);
    }
    GotoXY(20, 18);
    printf("answer is:");
    char ch = _getch();
    if(ch != idiom[pos][lack]) return false;
    return true;
}
