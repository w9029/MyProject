#ifndef _LES_struct_
#define _LES_struct_
typedef struct les
{
	char LES_Number[10];
	char LES_Name[20];
	char LES_Type[10];	//课程性质
	int LES_Time;		//学时
	int LES_Credit;		//学分
	int StuCount;		//已选人数
	int MaxStuCount;	//最大人数
	struct les *next;
}LES;

#endif
