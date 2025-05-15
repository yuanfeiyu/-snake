
#include "snake.h"
#include <time.h>

int main(void)
{
	int choice = 0;

	//���ÿ���̨�Ŀ��
	system("mode con cols=100 lines=30");

	//�����������
	srand(time(NULL));

	while (1)
	{
		//��ʾ��ӭ����
		choice = welcomGame();

		switch (choice)
		{
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

		case 2:
			//printf("��Ϸ˵��");
			aboutGame();
			break;

		case 3:
			//printf("�˳���Ϸ");
			exit(0);
			break;
		default:
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


