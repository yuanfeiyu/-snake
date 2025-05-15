
#include "snake.h"
#include <time.h>

int main(void)
{
	int choice = 0;

	//���ÿ���̨�Ŀ��
	system("mode con cols=100 lines=30");

	//�����������
	srand(time(NULL));

	//ѭ�������û���ѡ��
	while (1)
	{
		//��ʾ��ӭ����
		choice = welcomGame();

		switch (choice)
		{
			//��ʼ��Ϸ
		case 1:
			//printf("��ʼ��Ϸ");
			printMap();
			showScoreTips();

			//��ʼ����
			initSnake();

			//���ʳ��
			randFood();

			//ͨ������������ߵ��ƶ�
			moveKeyControl();

			break;

			//��Ϸ˵��
		case 2:
			//printf("��Ϸ˵��");
			aboutGame();
			break;

			//�˳���Ϸ
		case 3:
			//printf("�˳���Ϸ");
			//ϵͳ�ṩ�ĺ��� ��������
			exit(0);
			break;

			//����Ƿ� ��������
		default:
			//printf("ѡ��Ƿ�");
			setColor(12);
			gotoXY(45, 28);
			printf("�Ƿ���ѡ��,���»س�������");
			//getchar();
		}

		//���»س�������
		getchar();
	}

	system("pause");

	return 0;
}


