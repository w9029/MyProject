#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"./Include/STU_Operate.h"
#include"./Include/LES_Operate.h"
#include"./Include/STU_struct.h"
#include"./Include/LES_struct.h"

STU STU_head;
LES LES_head;

void Interface()
{
	int flag=1;
	while(flag!=3)
	{
		system("clear");
		printf("*****学生课程管理系统*****\n");
		printf("*                        *\n");
		printf("*       1.学生管理       *\n");
		printf("*                        *\n");
		printf("*       2.课程管理       *\n");
		printf("*                        *\n");
		printf("*       3.退出系统       *\n");
		printf("*                        *\n");
		printf("**************************\n");
		printf("请输入您的选择：");
		
		scanf("%d",&flag);
		
		switch(flag)
		{
			case 1:
				//printf("student\n");
				STU_Interface();
				break;
			case 2:
				//printf("lesson\n");
				LES_Interface();
				break;
			case 3:
				printf("exit\n");
				break;
			default:
				printf("input error, please try again\n");
				break;
		}
	}
}

int main()
{
	Interface();
	return 0;
}
