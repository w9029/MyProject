#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"STU_Operate.h"
#include"LES_Operate.h"
#include"STU_struct.h"
#include"LES_struct.h"

void Interface();			//系统选择菜单
void PrintSTU();			//输出学生信息
void PrintLES();			//输出课程信息

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

void PrintSTU(STU *a)
{
	int i;
	printf("%s %s %d ",a->STU_Number,a->STU_Name,a->LesCount);
	for(i=0;i<a->LesCount;i++)
	{
		printf("%s ",a->Lessons[i]);
	}
	printf("%d\n",a->Credit);
}

void PrintLES(LES *a)
{
	printf("%s %s %s %d %d\n",a->LES_Number,a->LES_Name,a->LES_Type,
	a->LES_Time,a->MaxStuCount);
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

