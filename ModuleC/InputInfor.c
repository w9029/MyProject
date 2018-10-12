#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"STU_Operate.h"
#include"LES_Operate.h"
#include"STU_struct.h"
#include"LES_struct.h"

extern STU STU_head;
extern LES LES_head;

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
	while(fscanf(fp,"%s %s %d",s->STU_Number,s->STU_Name,&s->LesCount)!=EOF)
	{
		for(i=0; i<s->LesCount; i++)
		{
			fscanf(fp,"%s",s->Lessons[i]);
		}
		fscanf(fp,"%d",&s->Credit);
		PrintSTU(s);

		p->next=s;
		s=(STU*)malloc(sizeof(STU));
	}
	s->next=NULL;
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
	while(fscanf(fp,"%s %s %s %d %d",
	s2->LES_Number,s2->LES_Name,s2->LES_Type,
	&s2->LES_Time,&s2->MaxStuCount)!=EOF)
	{
		PrintLES(s2);
		p2->next=s2;
		s2=(LES*)malloc(sizeof(LES));
	}
	s2->next=NULL;
	fclose(fp);

}

void KeyboardInput()
{
	
	
}

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
			//printf("file\n");
			FileInput();
			flag=3;
			break;
		case 2:
			//printf("keyboard\n");
			KeyboardInput();
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
