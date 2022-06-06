#include "idiom.h"
#include<bits/stdc++.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

vector<string> idiom;
vector<string> correct;
vector<string> wrong;

time_t startTime, endTime;
int lastTime = 0;        //�������ʱ��

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
    GotoXY(40, 4);
    cout << "��ӭ��������������С��Ϸ";
    GotoXY(43, 10);
    printf("1.��ʼ��Ϸ");
    GotoXY(43, 14);
    printf("3.����");
    GotoXY(43, 16);
    printf("4.����");

    //PXY EDITED
    GotoXY(43, 12);
    cout << "2.�Ʒְ�";
    //END OF PXY EDITED

    GotoXY(40, 20);
    printf("����������˳���Ϸ");
    Hide();
    char ch;
    int result = 0;
    ch = _getch();
    printf("%c", ch);
    switch (ch) {
        case '1':
            result = 1;
            break;
        case '2':
            result = 2;
            break;
        case '3':
            result = 3;
            break;
        case '4':
            result = 4;
            break;
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
    ifs.open("../data.txt", ios::in);
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
//    if (idiom[pos].find(ch) != string::npos) {
//        printf("��ȷ���������      ");
//        correct.push_back(idiom[pos]);            //����ȷ�Ĵ�����correct������
//    } else {
//        printf("���ˣ���ȷ�𰸣�");
//        cout << idiom[pos].substr(2 * lack, 2);        //������Ĵ�����wrong������
//        wrong.push_back(idiom[pos]);
//    }
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
