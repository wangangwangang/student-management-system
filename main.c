#include <stdio.h>
#include "menu.h"
#include "stu.h"
#include "tea.h"


//主函数
void main()
{
	
	DRStu();					//载入学生信息
	DRTea();					//载入老师信息
	
	menu_login();																

}
