#include"STU_struct.h"
#include"LES_struct.h"
#include"PrintInfor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

extern STU STU_head;
extern LES LES_head;


void LES_Search()
{
	int i=0,flag=0,success=0;
	LES *ples;
	char SEA_LES[20];

	ples=LES_head.next;

	printf("请输入要查找的课程名或编号\n");
	scanf("%s",SEA_LES);
	while(SEA_LES[i])
	{
		if(isalpha(SEA_LES[i]))	//	判断输入内容是课程名还是编号
		{
			flag=1;			//	字符串中出现字母 判断字符串为课程名
			break;
		}
		i++;
	}

	if(flag==1)					//	查找课程名匹配的课程
	{
		while(ples && strcmp(ples->LES_Name,SEA_LES)!=0)
		{
			ples=ples->next;
		}
		if(ples!=NULL)			//	查找成功
			success=1;
		else success=0;
	}
	else						//	查找编号匹配的课程
	{
		while(ples && strcmp(ples->LES_Number,SEA_LES)!=0)
		{
			ples=ples->next;
		}
		if(ples!=NULL)			//	查找成功
			success=1;
		else success=0;
	}
	if(success)
	{
		system("clear");
		printf("课程编号 课程名 课程性质 学时 学分 已选人数 最大选课人数\n");
		PrintLES(ples);
		printf("\n\n");
	}
	else
	{
		printf("未找到该课程，\n");
	}

}

