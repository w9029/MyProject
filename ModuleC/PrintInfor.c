#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"STU_struct.h"
#include"LES_struct.h"

extern STU STU_head;
extern LES LES_head;

void PrintSTU(STU *a)
{
	int i;
	printf("%s\t%s\t%d\t%d\t",a->STU_Number,a->STU_Name,
			a->Credit,a->LesCount);
	for(i=0;i<a->LesCount;i++)
	{
		printf("%s\t",a->Lessons[i]);
	}
	printf("\n");
}

void PrintLES(LES *a)
{
	printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n",
		a->LES_Number,a->LES_Name,a->LES_Type,
		a->LES_Time,a->LES_Credit,a->StuCount,a->MaxStuCount);
}

void PrintAllSTU()
{
	system("clear");
	printf("学号\t姓名\t学分\t课程数\t课程名\n");
	STU *p=STU_head.next;
	while(p)
	{
		PrintSTU(p);
		p=p->next;
	}
}

void PrintAllLES()
{
	system("clear");
	printf("课程编号 课程名 课程性质 学时 学分 已选人数 最大选课人数\n");
	LES *p=LES_head.next;
	while(p)
	{
		PrintLES(p);
		p=p->next;
	}
}

