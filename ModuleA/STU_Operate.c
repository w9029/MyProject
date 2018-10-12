#include"STU_struct.h"
#include"LES_struct.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void STU_Insert();
void STU_Delete();
void STU_Search();
void STU_Change();


extern STU STU_head;
extern LES LES_head;

void STU_Interface()
{
	int flag=1;
	while(flag!=6)
	{
		system("clear");
		printf("********学生管理系统********\n");
		printf("*                          *\n");
		printf("*     1.添加学生信息       *\n");
		printf("*                          *\n");
		printf("*     2.删除学生信息       *\n");
		printf("*                          *\n");
		printf("*     3.修改学生信息       *\n");
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
			//	printf("Insert\n");
			STU_Insert();
			break;
		case 2:
			//	printf("Delete\n");
			STU_Delete();
			break;
		case 3:
			printf("Change\n");
			break;
		case 4:
			printf("Search\n");
			break;
		case 5:
			//	输出所有学生信息
			PrintAllSTU();
			printf("按任意键继续\n");
			getchar();
			getchar();
			break;
		case 6:
			printf("exit\n");
			break;
		default:
			printf("input error, please try again\n");
			break;
		}
	}
}

void STU_Insert()			//	添加学生信息
{
	int i;
	STU *pstu,*s;

	pstu=&STU_head;
	while(pstu->next)pstu=pstu->next;//	移动到学生链表结尾
	s=(STU*)malloc(sizeof(STU));

	printf("请输入学生信息(学号，姓名，课程数，课程名):\n");
	scanf("%s%s%d",s->STU_Number,s->STU_Name,&s->LesCount);
	s->Credit=0;
	for(i=0; i<s->LesCount; i++)
	{	
		scanf("%s",s->Lessons[i]);

		LES *ples=LES_head.next;
		while(ples)
		{
			if(strcmp(ples->LES_Name,s->Lessons[i])==0)
			{
				ples->StuCount++;
				s->Credit+=ples->LES_Credit;
				break;
			}
			ples=ples->next;
		}
	}

	//	检查学号重复功能



	pstu->next=s;
	s->next=NULL;
	printf("添加成功，按任意键继续\n");
	getchar();
	getchar();
}

void STU_Delete()
{
	int i=0,flag=0,success=1;
	STU *pstu,*q;
	char DEL_STU[20];

	pstu=STU_head.next;			//	被删除的学生
	q=&STU_head;				//	指向要删除的学生的前一个

	printf("请输入要删除的学生姓名或学号\n");
	scanf("%s",DEL_STU);
	while(DEL_STU[i])
	{
		if(isalpha(DEL_STU[i]))	//	判断输入内容是姓名还是学号
		{
			flag=1;			//	字符串中出现字母 判断字符串为姓名
			break;
		}
		i++;
	}

	if(flag==1)					//	查找姓名匹配的学生
	{
		while(pstu && strcmp(pstu->STU_Name,DEL_STU)!=0)
		{
			q=pstu;
			pstu=pstu->next;
		}
		if(pstu!=NULL)			//	查找成功 进行删除
			success=1;
		else success=0;
	}
	else						//	查找学号匹配的学生
	{
		while(pstu && strcmp(pstu->STU_Number,DEL_STU)!=0)
		{
			q=pstu;
			pstu=pstu->next;
		}
		if(pstu!=NULL)			//	查找成功 进行删除
			success=1;
		else success=0;
	}
	if(success)
	{
		for(i=0; i<pstu->LesCount; i++)//删除此学生的选课
		{	
			LES *ples=LES_head.next;
			while(ples)
			{
				if(strcmp(ples->LES_Name,pstu->Lessons[i])==0)
				{
					ples->StuCount--;
					break;
				}
				ples=ples->next;
			}
		}

		q->next=pstu->next;		//删除学生信息
		free(pstu);

		printf("删除成功，按任意键继续\n");
		getchar();
		getchar();
	}
	else
	{
		printf("未找到该学生，按任意键继续\n");
		getchar();
		getchar();
	}
}

void STU_Search()
{
	/*
	int i=0,flag=0;
	STU *pstu,*q;
	char SEA_STU[20];

	pstu=STU_head.next;

	printf("请输入要查找的学生姓名或学号\n");
	scanf("%s",SEA_STU);
	while(DEL_STU[i])
	{
		if(isalpha(DEL_STU[i]))	//	判断输入内容是姓名还是学号
		{
			flag=1;			//	字符串中出现字母 判断字符串为姓名
			break;
		}
		i++;
	}
	if()

*/
}

void STU_Change()
{

}

