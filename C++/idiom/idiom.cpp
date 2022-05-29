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
    printf("欢迎来到成语填填乐小游戏");
    GotoXY(43, 10);
    printf("1.开始游戏");
    GotoXY(43, 12);
    printf("2.帮助");
    GotoXY(43, 14);
    printf("3.关于");
    GotoXY(40, 20);
    printf("其他任意键退出游戏");
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
    printf("根据所缺成语输入正确的汉字即可过关");
    GotoXY(40, 26);
    printf("按任意键返回上级菜单");
    Hide();
    char ch = _getch();
    system("cls");
}

void About(){
    GotoXY(30, 4);
    printf("杭州电子科技大学计算机学院期末课程实践案例");
    GotoXY(43, 10);
    printf("成语填填乐游戏");
    GotoXY(40, 26);
    printf("按任意键返回上级菜单");
    Hide();
    char ch = _getch();
    system("cls");
}

void IdiomRead(){
    ifstream ifs;       //打开文件并且判断是否打开成功
    ifs.open("data.txt",ios::in) ;
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    //读数据
    string s;
    while (ifs >> s) idiom.push_back(s);
    //关闭文件
    //cout<<idiom[0];
    ifs.close();
}

int IdiomChoose(){
    int size = idiom.size();
    int k;
    srand(time(0));
    k = rand() % size;        //随机选取一个成语编号
    return k;                   //返回编号
}

//初始化游戏基本界面
void InitMap(){
    Hide();


}

bool GameStart(){
    int pos;
    int lack;
    lack = rand() % 4 + 1;                      //挖去位置(1)
    srand(time(0));
    GotoXY(WID/2-1, HEIGHT/2-1);          //设置成语出现位置在中心
    pos = IdiomChoose();                       //取得idiom中的随机编号
    //输出编号代表值(除挖去值外)
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
