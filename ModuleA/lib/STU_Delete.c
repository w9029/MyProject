#include"STU_struct.h"
#include"LES_struct.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

extern STU STU_head;
extern LES LES_head;

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

		printf("删除成功，");

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
		fprintf(fp,"Delete Student\t%s\t(%s)\n\n",pstu->STU_Number,pstu->STU_Name);
		fclose(fp);
		free(pstu);
	}
	else
	{
		printf("未找到该学生，");
	}
}


