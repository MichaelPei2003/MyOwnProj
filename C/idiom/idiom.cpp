#include "idiom.h"			//自建头文件，自定义并实现函数，增强封闭性 
#include<bits/stdc++.h>		//主要使用其中的time.h iostream 等头文件，如下 
//#include <time.h>			//实现计时功能
//#include <iostream>		//实现C++的输入输出功能 
//#include <stdio.h>		//实现C语言的输入输出功能
//#include <vector>			//实现c++中的容器
//#include <cstring>		//实现c++中的string类 
#include <conio.h>			//主要使用其中_getstr函数获取控制台中单个字符 
#include <Windows.h>		//实现清屏功能 

using namespace std;

vector<string> idiom;       //存入所有位于data.txt中的成语
vector<string> correct;     //存入游戏过程中玩家回答正确的成语
vector<string> wrong;       //存入游戏过程中玩家回答错误的成语

time_t startTime, endTime;  //分别代表开始时间和结束时间，用于计时
int lastTime = 0;           //答题持续时间

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
    cout << "请选择难度";
    GotoXY(40, 6);
    cout << "简单（1）";
    GotoXY(40, 8);
    cout << "困难（2）";
    GotoXY(40, 10);
    Hide();
    char level = _getch();
    GotoXY(40, 12);
    cout << "已选择难度" << level;
    GotoXY(40, 14);
    cout << "按任意键开始游戏";
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
    printf("当前截至用时:%d.00s", lastTime);
    GotoXY(WID + 16, 4);
    printf("回答正确的个数:%d", correct.size());
    GotoXY(WID + 16, 6);
    printf("回答错误的个数:%d", wrong.size());
    GotoXY(WID + 16, 10);
    printf("当前得分:%d", correct.size() * 5);
    srand(time(0));
    lack = rand() % 3;                      //挖去位置(1)
    GotoXY(WID / 2 - 1, HEIGHT / 2 - 1);            //设置成语出现位置在中心
    pos = IdiomChoose();                    //取得idiom中的随机编号
    cout << "|" << idiom[pos] << "|";                //输出编号代表值(除挖去值外)
    GotoXY(WID / 2 + lack * 2, HEIGHT / 2 - 1);        //定位并输出空格
    cout << "    ";                         //Compared with level 1, 1 more character hidden
    GotoXY(WID / 2 - 5, HEIGHT / 2 + 5);
    cout << "你的答案是:                 ";
    GotoXY(WID / 2 - 5, HEIGHT / 2 + 5);
    cout << "你的答案是:";
    string ch;
    cin >> ch;
    //如果在成语中找到相符合的编码则输出正确
    GotoXY(WID / 2 - 2, HEIGHT / 2 + 8);
    if (ch.length() != 4) {                                    //Wrong length -> go straight to wrong
        printf("错了，正确答案：");
        cout << idiom[pos];
        wrong.push_back(idiom[pos]);                           //将错误的答案推入wrong容器中
    } else {
        if (idiom[pos].substr(2 * lack, 4).find(ch) != string::npos) {
            printf("正确，你真棒！                 ");
            correct.push_back(idiom[pos]);//将正确的答案推入correct容器中
        } else {
            printf("错了，正确答案：");
            cout << idiom[pos];        //将错误的答案推入wrong容器中
            wrong.push_back(idiom[pos]);
        }
    }
    endTime = time(NULL);                            //更新当前时间
    lastTime = difftime(endTime, startTime);                //更新当前持续时间
    idiom.erase(idiom.begin() + pos);                //从idiom中删去当前成语，避免重复选取
    int allq;
    allq = 50 - idiom.size();                    //allq等于已经出现的题目个数
    if (allq == 50 || correct.size() == 20) return false;  //已经出现50题或者得分100后退出
    return true;
}
//END OF PXY EDITED


int Menu() {
	GotoXY(38,4);
	cout<<"欢迎来到成语填填乐小游戏";
    GotoXY(44, 10);
    printf("1.开始游戏");
    GotoXY(46, 12);
    printf("2.帮助");
    GotoXY(46, 14);
    printf("3.关于");
	GotoXY(34, 24);
	printf("**游戏途中按输入Q/q可随时退出游戏**");
    GotoXY(40, 22);
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

void Help() {
    GotoXY(34, 14);
    printf("根据所缺成语输入正确的汉字即可过关");
    GotoXY(40, 26);
    printf("按任意键返回上级菜单");
    Hide();
    char ch = _getch();
    system("cls");
}

void About() {
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

void IdiomRead() {
    ifstream ifs;       //打开文件并且判断是否打开成功
    ifs.open("data.txt", ios::in);
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

int IdiomChoose() {
    int size = idiom.size();
    int k;
    srand(time(0));
    k = rand() % size;        //随机选取一个成语编号
    return k;                   //返回编号
}

//初始化游戏基本界面
//包括地图框架，回答正确与回答错误的个数 
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
    printf("当前截至用时:0");
    GotoXY(WID + 16, 4);
    printf("回答正确的个数:0");
    GotoXY(WID + 16, 6);
    printf("回答错误的个数:0");
    GotoXY(WID + 16, 10);
    printf("当前得分:0");
    startTime = time(NULL);
    endTime = time(NULL);
}

bool GameStart() {
    int pos;
    int lack;
    GotoXY(WID + 16, 2);
    printf("当前截至用时:%d.00s", lastTime);
    GotoXY(WID + 16, 4);
    printf("回答正确的个数:%d", correct.size());
    GotoXY(WID + 16, 6);
    printf("回答错误的个数:%d", wrong.size());
    GotoXY(WID + 16, 10);
    printf("当前得分:%d", correct.size() * 5);
    srand(time(0));
    lack = rand() % 4;                      //挖去位置(1)
    //srand(time(0));
    GotoXY(WID / 2 - 1, HEIGHT / 2 - 1);            //设置成语出现位置在中心
    pos = IdiomChoose();                    //取得idiom中的随机编号
    cout << "|" << idiom[pos] << "|";                //输出编号代表值(除挖去值外)
    GotoXY(WID / 2 + lack * 2, HEIGHT / 2 - 1);        //定位并输出空格
    cout << "  ";
    GotoXY(WID / 2 - 5, HEIGHT / 2 + 5);
    cout << "你的答案是:            ";
    GotoXY(WID / 2 - 5, HEIGHT / 2 + 5);
    cout << "你的答案是:";
    string ch;
    cin >> ch;
    //如果在成语中找到相符合的编码则输出正确
    GotoXY(WID / 2 - 2, HEIGHT / 2 + 8);
    //PXY EDITED
    if (ch.length() != 2) {                                    //Wrong length -> go straight to wrong
        printf("错了，正确答案：");
        cout << idiom[pos];
        wrong.push_back(idiom[pos]);                           //将错误的答案推入wrong容器中
    } else {
        if (idiom[pos].substr(2 * lack, 2).find(ch) != string::npos) {
            printf("正确，你真棒！                 ");
            correct.push_back(idiom[pos]);//将正确的答案推入correct容器中
        } else {
            printf("错了，正确答案：");
            cout << idiom[pos];        //将错误的答案推入wrong容器中
            wrong.push_back(idiom[pos]);
        }
    }
    //END OF PXY EDITED
    endTime = time(NULL);                            //更新当前时间
    lastTime = difftime(endTime, startTime);                //更新当前持续时间
    idiom.erase(idiom.begin() + pos);                //从idiom中删去当前成语，避免重复选取
    int allq;
    allq = 50 - idiom.size();                    //allq等于已经出现的题目个数
    if (allq == 50 || correct.size() == 20) return false;  //已经出现50题或者得分100后退出
    return true;
}

void Result()
{
	system("cls");
	GotoXY(20,4);
	if(correct.size()==20)
	{
		cout<<"游戏成功";
	}
	else
	{
		cout<<"游戏失败";
	}
	GotoXY(4,10);
	cout<<"|答对列表|";
	GotoXY(4, 12);
	int sz=correct.size();
	int printPos;                       //打印位置
	for(int i=0;i<sz;i++)
	{
		cout<<correct[i]<<"  ";
		if((i+1)%3==0)        //每输出三个就换行
		{
			GotoXY(4,12+2*(i/3));
		}
	}
	GotoXY(35, 10);
	cout<<"|答错列表|";
	GotoXY(35, 12);
	sz=wrong.size();
	for(int i=0;i<sz;i++)
	{
		cout<<wrong[i]<<"  ";
		if((i+1)%3==0)        //每输出三个就换行
		{
			GotoXY(35,12+2*(i/3));
		}
	}
	char ch;
	GotoXY(18,23);
	cout<<"按任意键回到菜单";
	GotoXY(0,0);
	ch=getchar();
	ch=getchar();
	system("cls");
}

void color(short x)	//自定义函根据参数改变颜色
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色
    else//默认的颜色白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

