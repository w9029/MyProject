#include"STU_struct.h"
#include"LES_struct.h"

void LES_Interface()
{
	int flag=1;
	while(flag!=5)
	{
		system("clear");
		printf("*******课程管理系统*******\n");
		printf("*                        *\n");
		printf("*     1.新增课程         *\n");
		printf("*                        *\n");
		printf("*     2.删除课程         *\n");
		printf("*                        *\n");
		printf("*     3.查看课程信息     *\n");
		printf("*                        *\n");
		printf("*     4.修改课程信息     *\n");
		printf("*                        *\n");
		printf("*     5.退出系统         *\n");
		printf("*                        *\n");
		printf("**************************\n");
		printf("请输入您的选择:");
		
		scanf("%d",&flag);
		
		switch(flag)
		{
			case 1:
				printf("Insert\n");
				break;
			case 2:
				printf("Delete\n");
				break;
			case 3:
				printf("Search\n");
				break;
			case 4:
				printf("Change\n");
				break;
			case 5:
				printf("exit\n");
				break;
			default:
				printf("input error, please try again\n");
				break;
		}
	}
}


void LES_Insert()
{
	
}

void LES_Delete()
{

}

void LES_Search()
{

}
void LES_Change()
{

}
