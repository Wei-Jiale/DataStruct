//����һ���޷������ͣ�����˳���ӡ����ÿһλ��
//�ݹ�ʵ����1.�������� 2.ÿ�εݹ����Խ��Խ�ӽ��������������
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
	printf("������һ����;\n");
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
			printf("����������������룡\n");
		}
	}
	return 0;
}