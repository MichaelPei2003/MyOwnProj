#ifndef IDIOM_H
#define IDIOM_H

#define HEIGHT 20   //��Ϸ����߶�
#define WID 40      //��Ϸ������
#define MAX 50      //����������������ʱʹ�ô˺�

void GotoXY(int x, int y);       //ָ�����λ��
void Hide();                    //���ع��
int Menu();
void Help();
void About();
void IdiomRead();
int IdiomChoose();
void InitMap();
bool GameStart();
void Result(); 
//PXY EDITED
int LevelSelection();
bool GameStart2();
void color(short x);
//END OF PXY EDITED

#endif

