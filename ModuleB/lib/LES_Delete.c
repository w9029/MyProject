#include"STU_struct.h"
#include"LES_struct.h"
#include"PrintInfor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

extern STU STU_head;
extern LES LES_head;


void LES_Delete()
{
	int i=0,flag=0,success=1;
	LES *ples,*q;
	char DEL_LES[20];

	ples=LES_head.next;				//被删除的课程
	q=&LES_head;					//指向要删除的课程的前一个

	printf("请输入要删除的课程名称或编号\n");
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
		STU
			*pstu;
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
					break;
				}
			}
			pstu=pstu->next;
		}

		q->next=ples->next;

		//删除课程信息
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
		fprintf(fp,"Change Class\t%s\t(%s)\n\n",ples->LES_Number,ples->LES_Name);
		fclose(fp);

		free(ples);
	}
	else
	{
		printf("未找到该课程，");
	}
}

