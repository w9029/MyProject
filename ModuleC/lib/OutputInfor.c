#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"STU_struct.h"
#include"LES_struct.h"

void FileInput();
void KeyboardInput();

extern STU STU_head;
extern LES LES_head;
extern char pathstu[30];
extern char pathles[30];


void FileOutput()
{
	int i;
	FILE *fp;
	STU *pstu;
	LES *ples;
	pstu = STU_head.next;
	ples = LES_head.next;

	//写入学生信息
	while((fp=fopen(pathstu,"w"))==NULL)
	{
		printf("读取错误，请重新输入路径\n");
		scanf("%s",pathstu);
	}
	while(pstu)
	{
		fprintf(fp,"%s\t%s\t%d\t%d\t",pstu->STU_Number,pstu->STU_Name,
				pstu->Credit,pstu->LesCount);
		for(i=0;i<pstu->LesCount;i++)
		{
			fprintf(fp,"%s",pstu->Lessons[i]);
			if(i!=pstu->LesCount-1)
				fprintf(fp,"\t");
		}
		fprintf(fp,"\n");
		pstu=pstu->next;
	}
	fclose(fp);

	//写入课程信息
	while((fp=fopen(pathles,"w"))==NULL)
	{
		printf("读取错误，请重新输入路径\n");
		scanf("%s",pathles);
	}
	while(ples)
	{
		fprintf(fp,"%s\t%s\t%s\t%d\t%d\t%d\t%d\n",
			ples->LES_Number,ples->LES_Name,ples->LES_Type,
			ples->LES_Time,ples->LES_Credit,ples->StuCount,ples->MaxStuCount);
		ples=ples->next;
	}
	fclose(fp);
}
