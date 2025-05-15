
#include "snake.h"
#include <time.h>

int main(void)
{
	int choice = 0;

	//设置控制台的宽高
	system("mode con cols=100 lines=30");

	//设置随机种子
	srand(time(NULL));

	while (1)
	{
		//显示欢迎界面
		choice = welcomGame();

		switch (choice)
		{
		case 1:
			//printf("开始游戏");
			printMap();
			showScoreTips();

			//初始化蛇
			initSnake();

			//随机食物
			randFood();

			//通过方向键控制蛇的移动
			moveKeyControl();

			break;

		case 2:
			//printf("游戏说明");
			aboutGame();
			break;

		case 3:
			//printf("退出游戏");
			exit(0);
			break;
		default:
			setColor(12);
			gotoXY(45, 28);
			printf("非法的选择,按下回车键继续");
			//getchar();
		}

		//按下回车键继续
		getchar();
	}

	system("pause");

	return 0;
}


