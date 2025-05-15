
#define _CRT_SECURE_NO_WARNINGS
#include "snake.h"


//�÷�
int score = 0;

//�Ե�ÿһ��ʳ��ĵ÷�
int add = 1;

//�ߵ��ƶ�����
int direction = RIGHT;

//˯��ʱ��
int sleepTime = 350;

//�����ı�־
int endStatus = 0;

//�����ͷָ��
snake_t* head = NULL;

//ʳ��Ľڵ�ָ��
snake_t* foodNode = NULL;

//�����ı�����ɫ  c������ɫֵ
int setColor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}

//���ù�������  
int gotoXY(int x, int y)
{
	//����ṹ������
	COORD c;

	//������
	c.X = x;
	//������
	c.Y = y;

	//STD_OUTPUT_HANDLE ��ʾ��׼���
	//c ����ֵ
	//GetStdHandle(STD_OUTPUT_HANDLE) ��ȡ��ǰ��׼������
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	return 0;
}



//��ӭ����
int welcomGame(void)
{
	int choice;


	int i = 0;
	int j = 0;
	system("cls");

	//�������
	//�����ı���ɫ 11
	setColor(11);
	//���ù��λ��(45, 18)
	gotoXY(45, 6);
	printf("̰������Ϸ");

	//���Ʊ߿�
	setColor(11);

	for (i = 8; i <= 14; i++)
	{

		for (j = 27; j <= 74; j++)
		{
			//������±߿�
			if (i == 8|| i == 14)
			{
				gotoXY(j, i);
				printf("-");
			}
			else if (j == 27 || j == 74)
			{
				//������ұ߿�
				gotoXY(j, i);
				printf("|");
			}
			else
			{
				//ע�⣺�ո��ַ�
				printf(" ");
			}
		}
	}

	//����˵�ѡ��
	//�����ı�������
	setColor(11);

	//��ʼ��Ϸ
	gotoXY(35, 10);
	printf("1. ��ʼ��Ϸ");

	//��Ϸ˵��
	gotoXY(55, 10);
	printf("2. ��Ϸ˵��");

	//�˳���Ϸ
	gotoXY(35, 12);
	printf("3. �˳���Ϸ");

	//�����ʾ��Ϣ
	gotoXY(27, 15);
	printf("��ѡ��[1 2 3]: ");

	scanf("%d", &choice);

	//������з�  3 \n
	getchar();

	return choice;
}

//��Ϸ˵������
int aboutGame(void)
{
	int i = 0;
	int j = 0;

	//����
	system("cls");

	//�������
	setColor(14);
	gotoXY(44, 3);
	printf("��Ϸ˵��");

	//�����������ұ߿�
	//������
	for (i = 6; i <= 22; i++)
	{
		//������
		for (j = 20; j <= 75; j++)
		{
			//���±߿� =
			if (i == 6 || i == 22)
			{
				gotoXY(j, i);
				printf("=");
			}
			else if (j == 20 || j == 75)
			{
				gotoXY(j, i);
				printf("|");
			}
			else
			{

			}
		}
	}

	//����˵�ѡ��
	setColor(11);
	gotoXY(30, 8);
	printf("1. ����ײ��ǽ������ҧ���Լ�");

	setColor(11);
	gotoXY(30, 11);
	printf("2. F1����ǰ����F2����ǰ��");

	setColor(11);
	gotoXY(30, 14);
	printf("3. ʹ�ÿո���ͣ��Ϸ���߼�����Ϸ");

	setColor(11);
	gotoXY(30, 17);
	printf("4. ʹ�÷��������ǰ���ķ���");

	setColor(11);
	gotoXY(30, 20);
	printf("5. ����ESC���˳���Ϸ");

	//�����ʾ��Ϣ
	setColor(14);
	gotoXY(20, 24);
	printf("���»س�������������");

	return 0;
}


//������Ϸ��ͼ
int printMap(void)
{
	int i = 0;
	int j = 0;

	//����
	system("cls");

	//������
	for (i = 0; i <= 26; i++)
	{
		//������
		for (j = 0; j <= 56; j = j + 2)
		{
			//��λ���
			gotoXY(j, i);
			if (0 == i || 26 == i || 0 == j || 56 == j)
			{
				setColor(5);
				printf("��");
			}
			else
			{
				setColor(3);
				printf("��");
			}
		}
	}

	return 0;
}

//��ʾ��������ʾ��Ϣ
int showScoreTips(void)
{
	int highScore = 0;

	//���ļ��ж�ȡ��߷�
	highScore = readFile();


	//��ʾ��߷�
	setColor(3);
	gotoXY(64, 4);
	printf("��߼�¼: %d", highScore);

	//��ʾ��ǰ�÷�
	setColor(14);
	gotoXY(64, 8);
	printf("�÷�: %d", score);

	//��ʾ��ܰ��ʾ
	setColor(12);
	gotoXY(72, 12);
	printf("�� ܰ �� ʾ");

	//�������±߿�
	setColor(15);
	gotoXY(60, 13);
	printf("==================================");

	gotoXY(60, 25);
	printf("==================================");

	//�����ʾ��Ϣ
	setColor(15);
	gotoXY(64, 14);
	printf("�Ե�ÿ��ʳ��÷�: %d", add);

	gotoXY(64, 16);
	printf("����ײ��ǽ�ڣ�����ҧ���Լ�");

	gotoXY(64, 18);
	printf("F1����ǰ����F2����ǰ��");

	gotoXY(64, 20);
	printf("ʹ�ÿո���ͣ��Ϸ���߼�����Ϸ");

	gotoXY(64, 22);
	printf("ʹ�á�����������ǰ���ķ���");

	gotoXY(64, 24);
	printf("����ESC�˳���Ϸ");

	return 0;
}

//��ȡ�ļ�����߷�  ��߷ֱ�����sava.txt�ļ���
int readFile(void)
{
	int ret = -1;
	char buf[32];

	FILE* fp = NULL;

	//1. ��ֻ���ķ�ʽ���ļ�
	fp = fopen("save.txt", "r");
	if (NULL == fp)
	{
		printf("fopen failed...\n");
		return 0;
	}

	//2. ��ȡ�ļ�����
	memset(buf, 0, sizeof(buf));
	ret = fread(buf, sizeof(char), sizeof(buf), fp);
	if (ret <= 0)
	{
		printf("fread failed...\n");
		return 0;
	}


	//3. �ر��ļ�
	fclose(fp);

	//atoi --> ���ַ���������ת��Ϊ����  "123" --> 123
	return atoi(buf);
}

//��ʼ���������ͷ
int initSnake(void)
{
	int i = 0;

	snake_t* new = NULL;
	snake_t* tmp = NULL;


	//ѭ�������ĸ��ڵ�
	for (i = 0; i < 4; i++)
	{
		//����ռ�
		new = malloc(sizeof(snake_t));
		if (NULL == new)
		{
			printf("malloc initSnake failed....\n");
			return -1;
		}
		memset(new, 0, sizeof(snake_t));

		//��ֵ
		new->x = 24 + i * 2;
		new->y = 5;

		//ͷ�巨
		new->next = head;
		head = new;
	}

	//��������
	tmp = head;
	while (NULL != tmp)
	{
		//�����ߵ���ɫ 14 ��ɫ
		setColor(14);
		//��λ���
		gotoXY(tmp->x, tmp->y);

		//��һ���ڵ�������ǵ���ͷ�ڵ�
		if (head == tmp)
		{
			printf("��");
		}
		else
		{
			printf("��");
		}

		tmp = tmp->next;
	}


	return 0;
}

//���ʳ��
int randFood(void)
{
	snake_t* tmp = NULL;

	//�����ʳ�ﲻ�ܹ�������ǽ����
	//�����ʳ�ﲻ�ܹ�������������
	//�����ʳ��x����һ����ż��

	//����ռ�
	foodNode = malloc(sizeof(snake_t));
	if (NULL == foodNode)
	{
		gotoXY(1, 28);
		printf("malloc failed...\n");
		return -1;
	}
	memset(foodNode, 0, sizeof(snake_t));

	while (1)
	{
		while (1)
		{
			//��֤X������ż�� ͬʱ��Ӧ�ó�����ǽ��(2, 54)
			foodNode->x = rand() % 53 + 2;

			if (0 == foodNode->x % 2)
			{
				break;
			}
		}

		//y�����ǣ�1,25��
		foodNode->y = rand() % 25 + 1;  //(0,24) --> (1, 25)

		//�ж�ʳ�ﲻ�ܹ���������
		tmp = head;

		while (NULL != tmp)
		{
			if ((foodNode->x == tmp->x) && (foodNode->y == tmp->y))
			{
				break;
			}

			tmp = tmp->next;
		}

		//ʳ��û�����ߵ�����
		if (NULL == tmp)
		{
			gotoXY(foodNode->x, foodNode->y);
			setColor(12);
			printf("��");
			break;
		}
		else
		{
			continue;
		}

	}

	return 0;
}

//�����ߵ��ƶ�
int moveSnake(void)
{
	snake_t* new = NULL;
	snake_t* tmp = NULL;
	snake_t* save = NULL;

	//�����µĽڵ�
	new = malloc(sizeof(snake_t));
	if (NULL == new)
	{
		printf("malloc failed...\n");
		return -1;
	}
	memset(new, 0, sizeof(snake_t));

	//����
	if (UP == direction)
	{
		new->x = head->x;
		new->y = head->y - 1;
	}

	//����
	if (DOWN == direction)
	{
		new->x = head->x;
		new->y = head->y + 1;
	}

	//����
	if (LEFT == direction)
	{
		new->x = head->x - 2;
		new->y = head->y;
	}

	//����
	if (RIGHT == direction)
	{
		new->x = head->x + 2;
		new->y = head->y;
	}

	//ͷ�巨
	new->next = head;
	head = new;

	tmp = head;
	setColor(14);

	//�ж��Ƿ�Ϊʳ��
	if ((new->x == foodNode->x) && (foodNode->y == new->y))
	{
		//ѭ��������
		while (NULL != tmp)
		{
			gotoXY(tmp->x, tmp->y);
			if (head == tmp)
			{
				printf("��");
			}
			else
			{
				printf("��");
			}

			tmp = tmp->next;
		}

		//�Ե�һ��ʳ�� ���ӷ���
		score = score + add;

		//���ʳ��
		randFood();
	}
	else
	{
		while (NULL != tmp->next)
		{
			gotoXY(tmp->x, tmp->y);
			if (head == tmp)
			{
				printf("��");
			}
			else
			{
				printf("��");
			}

			save = tmp;
			tmp = tmp->next;
		}

		//�����һ���ڵ��ͷ�
		gotoXY(tmp->x, tmp->y);
		setColor(3);
		printf("��");

		save->next = NULL;
		free(tmp);
	}

	return 0;
}

//ͨ������������ߵ��ƶ�
int moveKeyControl(void)
{
	//Ĭ�Ϸ����������
	direction = RIGHT;

	while (1)
	{
		//��ʾ�Ҳ��С��ʾ
		showScoreTips();

		//����
		if (GetAsyncKeyState(VK_UP) && direction != DOWN)
		{
			direction = UP;
		}

		//����
		if (GetAsyncKeyState(VK_DOWN) && direction != UP)
		{
			direction = DOWN;
		}


		//����
		if (GetAsyncKeyState(VK_LEFT) && direction != RIGHT)
		{
			direction = LEFT;
		}

		//����
		if (GetAsyncKeyState(VK_RIGHT) && direction != LEFT)
		{
			direction = RIGHT;
		}

		//���¿ո���ͣ��Ϸ���߼�����Ϸ
		if (GetAsyncKeyState(VK_SPACE))
		{
			while (1)
			{
				Sleep(300);
				if (GetAsyncKeyState(VK_SPACE))
				{
					break;
				}
			}
		}

		//����F8����
		if (GetAsyncKeyState(VK_F8))
		{
			//����˯��ʱ��  ����˯�ߵ�ʱ�䲻��С��50ms
			speedUp();
		}

		//����F9����
		if (GetAsyncKeyState(VK_F9))
		{
			//����˯�ߵ�ʱ��
			speedDown();
		}

		//����ESC�� ������Ϸ
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			//��ʾ�û�����ESC��������Ϸ
			endStatus = 3;

			endGame();

			//exit(1);
			break;
		}


		Sleep(sleepTime);

		moveSnake();

		//�ж��Ƿ�ײ��ǽ��
		if (isHitWall())
		{
			endStatus = 1;
			endGame();
			break;
		}

		//�ж��Ƿ�ҧ���Լ�
		if (isBitSelf())
		{
			endStatus = 2;
			endGame();
			break;
		}
	}

	return 0;
}

//�����ߵ��ƶ�
int speedUp(void)
{
	//�����ٶ� ˯��ʱ��50ms
	if (sleepTime > 50)
	{
		sleepTime = sleepTime - 20;
		add = add + 2;
	}

	return 0;
}


//�����ߵ��ƶ�  ����˯�ߵ�ʱ��
int speedDown(void)
{
	if (sleepTime < 350)
	{
		sleepTime = sleepTime + 20;

		//�������ӵķ���
		add = add - 2;
	}

	if (add <= 0)
	{
		add = 1;
	}

	return 0;
}

//�ж��Ƿ�ײ��ǽ��
int isHitWall(void)
{
	//��ʾײ��ǽ��
	if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
	{
		return 1;
	}

	//��ʾû��ײ��ǽ��
	return 0;
}

//�ж��Ƿ�ҧ���Լ�
int isBitSelf(void)
{
	snake_t* tmp = NULL;

	//�ӵڶ����ڵ㿪ʼ��
	tmp = head->next;

	while (NULL != tmp)
	{
		if ((head->x == tmp->x) && (head->y == tmp->y))
		{
			return 1;
		}

		//ָ����һ���ڵ�
		tmp = tmp->next;
	}

	return 0;
}

//��Ϸʧ�ܽ���߿�
void failGameUi(void)
{
	int i = 0;

	//����
	system("cls");

	//��ʾ��Ϸʧ����ʾ
	setColor(12);
	gotoXY(44, 3);
	printf("�� Ϸ ʧ ��!!!");

	//���ñ߿����ɫ
	setColor(11);
	gotoXY(17, 5);

	//�����ϱ߿�
	printf("+----------------------------------------------------------------+");

	//�����±߿�
	gotoXY(17, 20);
	printf("+----------------------------------------------------------------+");

	//�������ұ߿�
	for (i = 6; i < 20; i++)
	{
		gotoXY(17, i);
		printf("|");

		gotoXY(82, i);
		printf("|");
	}
}

//������Ϸ
int endGame(void)
{
	int n = 0;
	int highScore = 0;

	while (1)
	{
		//��ʾ��Ϸʧ�ܽ���
		failGameUi();

		setColor(12);
		gotoXY(38, 9);

		//��ͬ��״̬ ��ʾ��ͬʧ����ʾ endStatus
		switch (endStatus)
		{
			//ײ��ǽ��
		case 1:
			printf("��ײ��ǽ�ˣ���Ϸ����!!!");
			break;

			//ҧ���Լ�
		case 2:
			printf("��ҧ�������ˣ���Ϸ����!!!");
			break;

			//�û�����ESC
		case 3:
			printf("���Ѿ���������Ϸ����Ϸ����!!!");
			break;

		default:
			;
		}

		//��ʾ���ĵ÷�
		setColor(13);
		gotoXY(43, 12);
		printf("���ĵ÷�: %d", score);

		//��ʾ��߷�
		//���ļ��ж�ȡ��߷�
		highScore = readFile();

		if (score > highScore)
		{
			setColor(10);
			gotoXY(38, 16);
			printf("�¼�¼������");

			//����߷�д���ļ�
			writeFile(score);
		}
		else
		{
			setColor(10);
			gotoXY(43, 16);
			printf("��ߵ÷֣�%d", highScore);
		}

		//����û�ѡ�����Ϣ
		gotoXY(25, 23);
		setColor(12);
		printf("����һ�������룺1");

		gotoXY(52, 23);
		printf("ֱ���˳������룺2");

		gotoXY(46, 25);
		setColor(11);
		printf("��ѡ��: ");

		scanf("%d", &n);
		

		if (1 == n)
		{
			score = 0;
			sleepTime = 350;
			add = 1;

			//������
			destroySnake();

			break;
		}
		else if (2 == n)
		{
			exit(0);
		}
		else
		{
			gotoXY(30, 27);
			setColor(12);
			printf("���������������������룬���»س�������");
			getchar();
		}
	}
	return 0;
}


//����߷�д���ļ���
int writeFile(int score)
{
	FILE* fp = NULL;

	//���ļ�
	fp = fopen("save.txt", "w+");
	if (NULL == fp)
	{
		printf("���ļ�ʧ��\n");
		return -1;
	}

	//����߷�д���ļ���
	fprintf(fp, "%d", score);

	//�ر��ļ�
	fclose(fp);

	return 0;
}

//������
int destroySnake(void)
{
	snake_t* tmp = NULL;
	snake_t* save = NULL;

	tmp = head;
	while (NULL != tmp)
	{
		save = tmp->next;
		free(tmp);

		tmp = save;
	}

	head = NULL;

	return 0;
}
