#include"STU_struct.h"
#include"LES_struct.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void LES_Insert();
void LES_Delete();

extern STU STU_head;
extern LES LES_head;

void LES_Interface()
{
	int flag=1;
	while(flag!=6)
	{
		system("clear");
		printf("********课程管理系统********\n");
		printf("*                          *\n");
		printf("*     1.新增课程           *\n");
		printf("*                          *\n");
		printf("*     2.删除课程           *\n");
		printf("*                          *\n");
		printf("*     3.查看课程信息       *\n");
		printf("*                          *\n");
		printf("*     4.修改课程信息       *\n");
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
			//printf("Insert\n");
			LES_Insert();
			break;
		case 2:
			//printf("Delete\n");
			LES_Delete();
			break;
		case 3:
			printf("Search\n");
			break;
		case 4:
			printf("Change\n");
			break;
		case 5:
			//输出所有课程信息
			PrintAllLES();
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


void LES_Insert()
{
	LES *ples,*s;

	ples=&LES_head;
	while(ples->next)ples=ples->next;
	s=(LES*)malloc(sizeof(LES));
	printf("请输入课程信息(编号，课程名，课程性质，学时，学分，最大选课人数):\n");
	scanf("%s%s%s%d%d%d",s->LES_Number,s->LES_Name,s->LES_Type,
			&s->LES_Time,&s->LES_Credit,&s->MaxStuCount);
	s->StuCount=0;
	ples->next=s;
	s->next=NULL;

	printf("添加成功，按任意键继续\n");
	getchar();
	getchar();
}

void LES_Delete()
{
	int i=0,flag=0,success=1;
	LES *ples,*q;
	char DEL_LES[20];

	ples=LES_head.next;				//被删除的课程
	q=&LES_head;					//指向要删除的课程的前一个

	printf("请输入要删除的学生姓名或学号\n");
	scanf("%s",DEL_LES);
	while(DEL_LES[i])
	{
		if(isalpha(DEL_LES[i]))		//判断输入内容是课程名还是编号
		{
			flag=1;					//字符串中出现字母 判断字符串为课程名
			break;
		}
		i++;
	}

	if(flag==1)						//查找课程名匹配的课程
	{
		while(ples && strcmp(ples->LES_Name,DEL_LES)!=0)
		{
			q=ples;
			ples=ples->next;
		}
		if(ples!=NULL)				//查找成功
			success=1;
		else success=0;
	}
	else							//查找编号匹配的课程
	{
		while(ples && strcmp(ples->LES_Number,DEL_LES)!=0)
		{
			q=ples;
			ples=ples->next;
		}
		if(ples!=NULL)				//查找成功
			success=1;
		else success=0;
	}
	if(success)
	{
		
		//删除学生选课
		STU *pstu;
		pstu=STU_head.next;
		while(pstu)
		{
			for(i=0;i<pstu->LesCount;i++)
			{
				if(strcmp(pstu->Lessons[i],ples->LES_Name)==0)
				{
					int j;
					for(j=i;j<pstu->LesCount-1;j++)
						strcpy(pstu->Lessons[j],pstu->Lessons[j+1]);
					pstu->Lessons[j][0]='\0';
					
					pstu->LesCount--;
				}
			}
			pstu=pstu->next;
		}
		
		
		q->next=ples->next;			//删除课程信息
		free(ples);
		
		printf("删除成功，按任意键继续\n");
		getchar();
		getchar();
	}
	else
	{
		printf("未找到该课程，按任意键继续\n");
		getchar();
		getchar();
	}

}

void LES_Search()
{

}
void LES_Change()
{

}
