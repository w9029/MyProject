#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"STU_Operate.h"
#include"LES_Operate.h"
#include"STU_struct.h"
#include"LES_struct.h"

void FileInput();
void KeyboardInput();

extern STU STU_head;
extern LES LES_head;

int InputInformation()
{
	int flag=1;
	while(flag!=3)
	{
		system("clear");
		printf("*******学生课程管理系统*******\n");
		printf("*                            *\n");
		printf("*      1.从文件导入数据      *\n");
		printf("*                            *\n");
		printf("*      2.从键盘输入数据      *\n");
		printf("*                            *\n");
		printf("*      3.退出系统            *\n");
		printf("*                            *\n");
		printf("******************************\n");
		printf("请输入您的选择：");

		scanf("%d",&flag);
		if(flag==3)return 0;
		switch(flag)
		{
		case 1:
			FileInput();
			printf("导入成功，按任意键继续\n");
			getchar();
			getchar();
			flag=3;
			break;
		case 2:
			//printf("keyboard\n");
			KeyboardInput();
			printf("输入成功，按任意键继续\n");
			getchar();
			getchar();
			flag=3;
			break;
		case 3:
			printf("exit\n");
			break;
		default:
			printf("input error, please try again\n");
			break;
		}
	}
	return 1;
}


void FileInput()
{
	int i;
	FILE *fp;

	//从文件导入学生信息
	STU *p,*s;
	char path[30];
	printf("请输入学生信息的文件路径\n");
	scanf("%s",path);

	while((fp=fopen(path,"r"))==NULL)
	{
		printf("读取错误，请重新输入路径\n");
		scanf("%s",path);
	}

	p=&STU_head;
	s=(STU*)malloc(sizeof(STU));
	while(fscanf(fp,"%s%s%d",s->STU_Number,s->STU_Name,&s->LesCount)!=EOF)
	{
		for(i=0; i<s->LesCount; i++)
		{
			fscanf(fp,"%s",s->Lessons[i]);
		}
		fscanf(fp,"%d",&s->Credit);

		p->next=s;
		p=p->next;
		s=(STU*)malloc(sizeof(STU));
	}
	p->next=NULL;
	fclose(fp);

	//从文件导入课程信息
	LES *p2,*s2;

	printf("请输入课程信息的文件路径\n");
	scanf("%s",path);

	while((fp=fopen(path,"r"))==NULL)
	{
		printf("读取错误，请重新输入路径\n");
		scanf("%s",path);
	}

	p2=&LES_head;
	s2=(LES*)malloc(sizeof(LES));
	while(fscanf(fp,"%s%s%s%d%d%d%d",
				s2->LES_Number,s2->LES_Name,s2->LES_Type,
				&s2->LES_Time,&s2->LES_Credit,&s2->StuCount,
				&s2->MaxStuCount)!=EOF)
	{
		p2->next=s2;
		p2=p2->next;
		s2=(LES*)malloc(sizeof(LES));
	}
	p2->next=NULL;
	fclose(fp);

}

void KeyboardInput()
{
	int i;
	STU *pstu,*sstu;
	LES *ples,*sles;

	//从键盘输入学生信息
	pstu=&STU_head;
	sstu=(STU*)malloc(sizeof(STU));
	printf("请逐行输入学生信息(学号，姓名，课程数，课程名)，以end结尾\n");
	while(scanf("%s",sstu->STU_Number)!=EOF)
	{	
		if(strcmp(sstu->STU_Number,"end")==0)break;
		scanf("%s%d",sstu->STU_Name,&sstu->LesCount);

		for(i=0;i<sstu->LesCount;i++)
			scanf("%s",sstu->Lessons[i]);
		sstu->Credit=0;

		pstu->next=sstu;
		pstu=pstu->next;
		sstu=(STU*)malloc(sizeof(STU));
	}
	pstu->next=NULL;



	//从键盘输入课程信息
	ples=&LES_head;
	sles=(LES*)malloc(sizeof(LES));
	printf("请逐行输入课程信息(编号，课程名，课程性质，学时，学分，最大选课人数)，以end结尾\n");
	while(scanf("%s",sles->LES_Number)!=EOF)
	{	
		if(strcmp(sles->LES_Number,"end")==0)break;
		scanf("%s%s%d%d%d",sles->LES_Name,sles->LES_Type,
				&sles->LES_Time,&sles->LES_Credit,&sles->MaxStuCount);

		sles->StuCount=0;

		ples->next=sles;
		ples=ples->next;
		sles=(LES*)malloc(sizeof(LES));
	}
	ples->next=NULL;
}


