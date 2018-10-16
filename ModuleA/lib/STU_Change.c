#include"STU_struct.h"
#include"LES_struct.h"
#include"PrintInfor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

extern STU STU_head;
extern LES LES_head;

void STU_Change()
{
	int flag=-1,flagles=0;
	int i,success=0;
	char command[10],chstu[20],chles[20]; 
	STU *pstu;
	LES *ples;
	pstu=STU_head.next;
	ples=LES_head.next;

	printf("请按以下格式输入指令：\n");
	printf("add/del 学号 课程名\n");
	scanf("%s%s%s",command,chstu,chles);

	//判断指令
	if(strcmp(command,"add")==0)flag=1;
	else
		if(strcmp(command,"del")==0)flag=0;
		else
		{
			printf("指令错误，");
			return;
		}

	//查找该学生
	while(pstu&&strcmp(pstu->STU_Number,chstu)!=0)
	{
		pstu=pstu->next;
	}
	if(pstu==NULL)
	{
		printf("未找到该学生，");
		return;
	}

	//查询课程是否存在
	flagles=0;
	while(ples)
	{
		if(strcmp(ples->LES_Name,chles)==0)
		{
			break;
		}
		ples=ples->next;
	}
	if(ples==NULL)
	{
		printf("未找到该课程，");
		return;
	}

	//查找该学生的此课程
	flagles=0;
	for(i=0;i<pstu->LesCount;i++)
	{
		if(strcmp(pstu->Lessons[i],chles)==0)
		{
			flagles=1;//课程已存在
			break;
		}
	}

	//为学生添加课程
	if(flag==1)	
	{
		if(flagles==1)
		{
			printf("此学生已选择本课程，请勿重复选课\n");
			return;
		}
		//添加学生课程信息
		strcpy(pstu->Lessons[pstu->LesCount],chles);
		pstu->LesCount++;

		//增加学分
		pstu->Credit+=ples->LES_Credit;

		system("clear");
		printf("选课成功，此学生当前信息为：\n");
		printf("学号\t姓名\t学分\t课程数\t课程名\n");
		PrintSTU(pstu);
	}
	else if(flag==0)//为学生删除课程
	{
		if(flagles==0)
		{
			printf("该学生未选择本课程，");
			return;
		}

		for(i=0;i<pstu->LesCount;i++)//删除课程，减少学分
		{
			if(strcmp(pstu->Lessons[i],ples->LES_Name)==0)
			{
				int
					j;
				for(j=i;j<pstu->LesCount-1;j++)
					strcpy(pstu->Lessons[j],pstu->Lessons[j+1]);
				pstu->Lessons[j][0]='\0';

				pstu->LesCount--;
				pstu->Credit-=ples->LES_Credit;
				break;
			}
		}

		//课程人数减少
		ples->StuCount--;

		system("clear");
		printf("删课成功，此学生当前信息为：\n");
		printf("学号\t姓名\t学分\t课程数\t课程名\n");
		PrintSTU(pstu);
	}

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
	fprintf(fp,"Change student\t%s\t(%s)\n\n",pstu->STU_Number,pstu->STU_Name);
	fclose(fp);
	
}

