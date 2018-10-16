#include"STU_struct.h"
#include"LES_struct.h"
#include"PrintInfor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

extern STU STU_head;
extern LES LES_head;


void STU_Search()
{
	int i=0,flag=0,success=0;
	STU *pstu;
	char SEA_STU[20];

	pstu=STU_head.next;

	printf("请输入要查找的学生姓名或学号\n");
	scanf("%s",SEA_STU);
	while(SEA_STU[i])
	{
		if(isalpha(SEA_STU[i]))	//	判断输入内容是姓名还是学号
		{
			flag=1;			//	字符串中出现字母 判断字符串为姓名
			break;
		}
		i++;
	}

	if(flag==1)					//	查找姓名匹配的学生
	{
		while(pstu && strcmp(pstu->STU_Name,SEA_STU)!=0)
		{
			pstu=pstu->next;
		}
		if(pstu!=NULL)			//	查找成功
			success=1;
		else success=0;
	}
	else						//	查找学号匹配的学生
	{
		while(pstu && strcmp(pstu->STU_Number,SEA_STU)!=0)
		{
			pstu=pstu->next;
		}
		if(pstu!=NULL)			//	查找成功
			success=1;
		else success=0;
	}
	if(success)
	{
		system("clear");
		printf("学号\t姓名\t学分\t课程数\t课程名\n");
		PrintSTU(pstu);
		printf("\n");
	}
	else
	{
		printf("未找到该学生，");
	}
}


