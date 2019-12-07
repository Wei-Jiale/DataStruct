#include"slist.h"

Test(){
	//初始化
	SListNode* pList = NULL;

	//尾插
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPrint(pList);

	//头插
	SListPushFront(&pList, 0);
	SListPrint(pList);

	//尾删
	SListPopBack(&pList);
	SListPrint(pList);

	//头删
	SListPopFront(&pList);
	SListPrint(pList);

	//查找
	SListNode* ret = SListFind(pList, 3);

	//在pos位置后做插入
	SListInsertAfter(ret, 6);
	SListPrint(pList);

	//在pos位置后做删除
	SListEraseAfter(ret);
	SListPrint(pList);

	SListDestory(pList);
	SListPrint(pList);
}

int main(){
	Test();
	return 0;
}