#include"Double.h"

void Test(){
	//�������������ͷ���
	ListNode* list = ListCreat();

	//˫�������β��
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPushBack(list, 5);
	ListPrint(list);

	//˫�������βɾ
	ListPopBack(list);
	ListPrint(list);

	//˫�������ͷ��
	ListPushFront(list, 0);
	ListPrint(list);

	//˫�������ͷɾ
	ListPopFront(list);
	ListPrint(list);

	//˫������Ĳ���
	ListNode* ret = ListFind(list, 2);
	printf("%p\n", ret);

	//˫��������pos֮ǰ����
	ListInsert(ret, 2);
	ListPrint(list);

	//˫������ɾ��posλ�õĽ��
	ListErase(ret);
	ListPrint(list);

	//˫�����������
	ListDestory(list);
}

int main(){
	Test();
	return 0;
}