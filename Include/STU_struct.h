#ifndef _STU_struct_
#define _STU_struct_
typedef struct stu
{
	char STU_Number[20];
	char STU_Name[20];
	int LesCount;
	char Lessons[30][10];
	int Credit;
	struct stu *next;
}STU;

#endif
