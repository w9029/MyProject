#include"STU_struct.h"
#include"LES_struct.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

extern STU STU_head;
extern LES LES_head;
extern char logfile[30];

void STU_Insert()
{
	int i;
	STU *pstu,*ptemp,*s;

	pstu=&STU_head;
	ptemp=STU_head.next;
	while(pstu->next)pstu=pstu->next;//	移动到学生链表结尾
	s=(STU*)malloc(sizeof(STU));

	printf("请输入学生信息(学号，姓名，课程数，课程名):\n");
	scanf("%s%s%d",s->STU_Number,s->STU_Name,&s->LesCount);
	
	//学号查重
	while(ptemp)
	{
		if(strcmp(s->STU_Number,ptemp->STU_Number)==0)
		{
			fflush(stdin);
			printf("此学号已被使用！\n");
			return;
		}
		ptemp=ptemp->next;
	}

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

	pstu->next=s;
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
	fprintf(fp,"Insert Student\t%s\t(%s)\n\n",s->STU_Number,s->STU_Name);
	fclose(fp);
}


