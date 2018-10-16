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

void STU_Interface()
{
	int flag=1;
	while(flag!=6)
	{
		fflush(stdin);
		system("clear");
		printf("********学生管理系统********\n");
		printf("*                          *\n");
		printf("*     1.添加学生信息       *\n");
		printf("*                          *\n");
		printf("*     2.删除学生信息       *\n");
		printf("*                          *\n");
		printf("*     3.更改学生课程       *\n");
		printf("*                          *\n");
		printf("*     4.查找学生信息       *\n");
		printf("*                          *\n");
		printf("*     5.查看所有学生信息   *\n");
		printf("*                          *\n");
		printf("*     6.退出系统           *\n");
		printf("*                          *\n");
		printf("****************************\n");
		printf("请输入您的选择:");

		scanf("%d",&flag);

		switch(flag)
		{
		case 1:
			STU_Insert();
			break;
		case 2:
			STU_Delete();
			break;
		case 3:
			STU_Change();
			break;
		case 4:
			STU_Search();
			break;
		case 5:
			PrintAllSTU();
			break;
		case 6:
			printf("exit\n");
			break;
		default:
			break;
		}
		
		//写入文件
		if(flag!=4 && flag!=5 && flag!=6)
			FileOutput();

		if(flag!=6 && flag!=5)
		{
			char c;
			while(c=getchar()!='\n' && c!=EOF);
			printf("请按任意键继续\n");
			getchar();
		}

	}
}

