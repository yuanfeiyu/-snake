#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//����  ��������
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4


//����ڵ���������
typedef struct _snake_t {
	//������
	int x;
	int y;

	struct _snake_t* next;//ָ����
}snake_t;

//�����ı�����ɫ
int setColor(int c);

//���ù���λ��
int gotoXY(int x, int y);

//�����ַ��� --��
int printSnake(void);

//��ӭ����
int  welcomGame(void);

//��Ϸ��������
int aboutGame(void);

//������Ϸ��ͼ
int printMap(void);

//��ʾ��������ʾ��Ϣ
int showScoreTips(void);

//���ļ��ж�ȡ��߷�  ALT + Enter 
int readFile(void);

//��ʼ����
int initSnake(void);

//���ʳ��
int randFood(void);

//�ߵ��ƶ�
int moveSnake(void);

//ͨ�����������ߵ��ƶ�
int moveKeyControl(void);

//�����ߵ��ƶ�
int speedUp(void);

//�����ߵ��ƶ�
int speedDown(void);

//�ж��Ƿ�ײ��ǽ�� ײǽ�˾ͷ���1 ���򷵻�0
int isHitWall(void);

//�ж��Ƿ�ҧ���Լ� ҧ���Լ��ͷ���1 ���򷵻�0
int isBitSelf(void);

//��Ϸʧ�ܽ���߿�
void failGameUi(void);

//������Ϸ
int endGame(void);

//����߷�д���ļ���
int writeFile(int score);

//������
int destroySnake(void);
