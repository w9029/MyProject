#ifndef _STU_struct_
#define _STU_struct_
char pathstu[30];
char pathles[30];
char logfile[30];
typedef struct stu
{
	char STU_Number[20];	//必须是由数字组成的字符串
	char STU_Name[20];
	int LesCount;
	char Lessons[30][10];
	int Credit;
	struct stu *next;
}STU;

#endif
