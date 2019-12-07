#include"slist.h"

Test(){
	//��ʼ��
	SListNode* pList = NULL;

	//β��
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPrint(pList);

	//ͷ��
	SListPushFront(&pList, 0);
	SListPrint(pList);

	//βɾ
	SListPopBack(&pList);
	SListPrint(pList);

	//ͷɾ
	SListPopFront(&pList);
	SListPrint(pList);

	//����
	SListNode* ret = SListFind(pList, 3);

	//��posλ�ú�������
	SListInsertAfter(ret, 6);
	SListPrint(pList);

	//��posλ�ú���ɾ��
	SListEraseAfter(ret);
	SListPrint(pList);

	SListDestory(pList);
	SListPrint(pList);
}

int main(){
	Test();
	return 0;
}