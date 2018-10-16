#include"STU_struct.h"
#include"LES_struct.h"
#include"PrintInfor.h"
#include"OutputInfor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

extern STU STU_head;
extern LES LES_head;

void LES_Change_Name();
void LES_Change_Type();
void LES_Change_Time();
void LES_Change_Credit();
void LES_Change_MaxStuCount();

void LES_Change()
{
	int flag=1;
	while(flag!=6)
	{
		fflush(stdin);
		system("clear");
		printf("********课程修改系统********\n");
		printf("*                          *\n");
		printf("*     1.更改课程名         *\n");
		printf("*                          *\n");
		printf("*     2.更改课程性质       *\n");
		printf("*                          *\n");
		printf("*     3.更改学时           *\n");
		printf("*                          *\n");
		printf("*     4.更改学分           *\n");
		printf("*                          *\n");
		printf("*     5.更改最大人数       *\n");
		printf("*                          *\n");
		printf("*     6.退出系统           *\n");
		printf("*                          *\n");
		printf("****************************\n");
		printf("请输入您的选择:");

		scanf("%d",&flag);

		switch(flag)
		{
		case 1:
			LES_Change_Name();
			break;
		case 2:
			LES_Change_Type();
			break;
		case 3:
			LES_Change_Time();
			break;
		case 4:
			LES_Change_Credit();
			break;
		case 5:
			LES_Change_MaxStuCount();
			break;
		case 6:
			printf("exit\n");
			break;
		default:
			printf("\n输入有误，");
			break;
		}

		//写入文件
		if(flag!=6)
			FileOutput();

		if(flag!=6)
		{
			fflush(stdin);
			printf("请按任意键继续\n");
			getchar();
			getchar();
		}
	}
}

void LES_Change_Name()
{
	LES *plesold,*plesnew;
	STU *pstu;
	char oldname[20],newname[20];
	plesold=LES_head.next;
	plesnew=LES_head.next;

	printf("请输按以下格式输入指令:\n");
	printf("原课程名 新课程名\n");
	scanf("%s%s",oldname,newname);

	//查找需要修改的课程是否存在
	while(plesold)
	{
		if(strcmp(plesold->LES_Name,oldname)==0)
		{
			break;
		}
		plesold=plesold->next;
	}
	if(plesold==NULL)
	{
		printf("未找到此课程，");
		return;
	}

	//查找新名称是否已被使用
	while(plesnew)
	{
		if(strcmp(plesnew->LES_Name,newname)==0)
		{
			break;
		}
		plesnew=plesnew->next;
	}
	if(plesnew!=NULL)
	{
		printf("同名课程已存在！请使用其他名称\n");
		return;
	}

	//修改课程名
	strcpy(plesold->LES_Name,newname);

	//修改学生信息中的课程名
	pstu=STU_head.next;
	while(pstu)
	{
		int i;
		for(i=0;i<pstu->LesCount;i++)
		{
			if(strcmp(pstu->Lessons[i],oldname)==0)
			{
				strcpy(pstu->Lessons[i],newname);
				break;
			}
		}
		pstu=pstu->next;
	}

	printf("\n修改成功！");


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
	fprintf(fp,"Change Class\t%s\t(%s)\n\n",plesold->LES_Number,plesold->LES_Name);
	fclose(fp);

}

void LES_Change_Type()
{
	LES *ples;
	char lesname[20],typename[20];
	ples=LES_head.next;

	printf("请输按以下格式输入指令:\n");
	printf("课程名 新性质名\n");
	scanf("%s%s",lesname,typename);

	//查找需要修改的课程是否存在
	while(ples)
	{
		if(strcmp(ples->LES_Name,lesname)==0)
		{
			break;
		}
		ples=ples->next;
	}
	if(ples==NULL)
	{
		printf("未找到此课程，");
		return;
	}

	//修改性质名
	strcpy(ples->LES_Type,typename);

	printf("\n修改成功！");

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


}

void LES_Change_Time()
{
	LES *ples;
	char lesname[20];
	int newtime=0;
	ples=LES_head.next;

	printf("请输按以下格式输入指令:\n");
	printf("课程名 新学时\n");
	scanf("%s%d",lesname,&newtime);

	//查找需要修改的课程是否存在
	while(ples)
	{
		if(strcmp(ples->LES_Name,lesname)==0)
		{
			break;
		}
		ples=ples->next;
	}
	if(ples==NULL)
	{
		printf("未找到此课程，");
		return;
	}

	//修改性质名
	ples->LES_Time=newtime;

	printf("\n修改成功！");

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

}

void LES_Change_Credit()
{
	LES *ples;
	STU *pstu;
	char lesname[20];
	int newCredit=0,temp=0;
	ples=LES_head.next;
	pstu=STU_head.next;

	printf("请输按以下格式输入指令:\n");
	printf("课程名 新学分数\n");
	scanf("%s%d",lesname,&newCredit);

	//查找需要修改的课程是否存在
	while(ples)
	{
		if(strcmp(ples->LES_Name,lesname)==0)
		{
			break;
		}
		ples=ples->next;
	}
	if(ples==NULL)
	{
		printf("未找到此课程，");
		return;
	}

	//得到新学分与旧学分的差值
	temp = newCredit - ples->LES_Credit;

	//修改学分
	ples->LES_Credit = newCredit;

	//修改学生学分
	while(pstu)
	{
		int i;
		for(i=0;i<pstu->LesCount;i++)
		{
			if(strcmp(pstu->Lessons[i],lesname)==0)
			{
				pstu->Credit += temp;
				break;
			}
		}
		pstu=pstu->next;
	}

	printf("修改成功！");

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

}

void LES_Change_MaxStuCount()
{
	LES *ples;
	char lesname[20];
	int newmax=0;
	ples=LES_head.next;

	printf("请输按以下格式输入指令:\n");
	printf("课程名 新最大容量\n");
	scanf("%s%d",lesname,&newmax);

	//查找需要修改的课程是否存在
	while(ples)
	{
		if(strcmp(ples->LES_Name,lesname)==0)
		{
			break;
		}
		ples=ples->next;
	}
	if(ples==NULL)
	{
		printf("未找到此课程，");
		return;
	}

	//判断容量
	if(ples->StuCount>newmax)
	{
		printf("修改失败！当前选课人数超出此数值！\n");
		return;
	}

	//修改最大容量
	ples->MaxStuCount=newmax;

	printf("\n修改成功！");

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
}

