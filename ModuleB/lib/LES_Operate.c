#include"STU_struct.h"
#include"LES_struct.h"
#include"PrintInfor.h"
#include"OutputInfor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

extern STU STU_head;
extern LES LES_head;

void LES_Interface()
{
	int flag=1;
	while(flag!=6)
	{
		fflush(stdin);
		system("clear");
		printf("********课程管理系统********\n");
		printf("*                          *\n");
		printf("*     1.新增课程           *\n");
		printf("*                          *\n");
		printf("*     2.删除课程           *\n");
		printf("*                          *\n");
		printf("*     3.修改课程信息       *\n");
		printf("*                          *\n");
		printf("*     4.查找课程信息       *\n");
		printf("*                          *\n");
		printf("*     5.显示所有课程信息   *\n");
		printf("*                          *\n");
		printf("*     6.退出系统           *\n");
		printf("*                          *\n");
		printf("****************************\n");
		printf("请输入您的选择:");

		scanf("%d",&flag);

		switch(flag)
		{
		case 1:
			LES_Insert();
			break;
		case 2:
			LES_Delete();
			break;
		case 3:
			LES_Change();
			break;
		case 4:
			LES_Search();
			break;
		case 5:
			PrintAllLES();
			break;
		case 6:
			printf("exit\n");
			break;
		default:
			printf("\n输入有误\n");
			break;
		}
		
		//写入文件
		if(flag!=4 && flag!=5 && flag!=6)
			FileOutput();

		if(flag!=6 && flag!=5 && flag!=3)
		{
			printf("请按任意键继续\n");
			getchar();
			getchar();
		}
	}
}

