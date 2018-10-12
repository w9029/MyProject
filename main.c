#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"STU_Operate.h"
#include"LES_Operate.h"
#include"STU_struct.h"
#include"LES_struct.h"
#include"PrintInfor.h"


void Interface();			//系统选择菜单

STU STU_head;
LES LES_head;

int main()
{
	STU_head.next=NULL;
	LES_head.next=NULL;
	
	//选择数据输入方式
	int flag;
	flag=InputInformation();
	if(flag==0)return 0;
	
	//选择学生/课程管理系统
	Interface();

	return 0;
}


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
			//学生管理系统
			STU_Interface();
			break;
		case 2:
			//课程管理系统
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

