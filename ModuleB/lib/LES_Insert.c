#include"STU_struct.h"
#include"LES_struct.h"
#include"PrintInfor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

extern STU STU_head;
extern LES LES_head;
extern char logfile[30];

void LES_Insert()
{
	LES *ples,*s,*temp;

	ples=&LES_head;
	temp=LES_head.next;
	while(ples->next)ples=ples->next;
	s=(LES*)malloc(sizeof(LES));
	printf("请输入课程信息(编号，课程名，课程性质，学时，学分，最大选课人数):\n");
	scanf("%s%s%s%d%d%d",s->LES_Number,s->LES_Name,s->LES_Type,
			&s->LES_Time,&s->LES_Credit,&s->MaxStuCount);

	while(temp)
	{
		if(strcmp(temp->LES_Number,s->LES_Number)==0)
		{
			printf("此编号已存在！请使用其他编号\n");
			fflush(stdin);
			return;
		}
		temp=temp->next;
	}

	s->StuCount=0;
	ples->next=s;
	s->next=NULL;

	printf("添加成功，");

	//写入日志
	char time[20]="date >> ";
	strcat(time,logfile);
	system(time);

	FILE *fp;
	while((fp=fopen(logfile,"a"))==NULL)
	{
		printf("请输入日志文件路径\n");
		scanf("%s",logfile);
	}
	fprintf(fp,"Insert Class\t%s\t(%s)\n\n",ples->LES_Number,ples->LES_Name);
	fclose(fp);
}


