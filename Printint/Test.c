//接收一个无符号整型，按照顺序打印它的每一位。
//递归实例（1.限制条件 2.每次递归调用越来越接近这个限制条件）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	int num = 0;
	printf("请输入一个数;\n");
	while (1)
	{
		scanf("%d", &num);
		if (num >= 0)
		{
			Print(num);
			break;
		}
		else
		{
			printf("输入错误，请重新输入！\n");
		}
	}
	return 0;
}