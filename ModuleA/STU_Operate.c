#include"STU_struct.h"
#include"LES_struct.h"

void STU_Interface()
{
	int flag=1;
	while(flag!=5)
	{
		system("clear");
		printf("*******学生管理系统*******\n");
		printf("*                        *\n");
		printf("*     1.添加学生信息     *\n");
		printf("*                        *\n");
		printf("*     2.删除学生信息     *\n");
		printf("*                        *\n");
		printf("*     3.修改学生信息     *\n");
		printf("*                        *\n");
		printf("*     4.查找学生信息     *\n");
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
				printf("Change\n");
				break;
			case 4:
				printf("Search\n");
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


void STU_Insert()
{
	
}

void STU_Delete()
{

}

void STU_Search()
{

}
