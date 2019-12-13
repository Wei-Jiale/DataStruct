#include"Double.h"

void Test(){
	//创建返回链表的头结点
	ListNode* list = ListCreat();

	//双向链表的尾插
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPushBack(list, 5);
	ListPrint(list);

	//双向链表的尾删
	ListPopBack(list);
	ListPrint(list);

	//双向链表的头插
	ListPushFront(list, 0);
	ListPrint(list);

	//双向链表的头删
	ListPopFront(list);
	ListPrint(list);

	//双向链表的查找
	ListNode* ret = ListFind(list, 2);
	printf("%p\n", ret);

	//双向链表在pos之前插入
	ListInsert(ret, 2);
	ListPrint(list);

	//双向链表删除pos位置的结点
	ListErase(ret);
	ListPrint(list);

	//双向链表的销毁
	ListDestory(list);
}

int main(){
	Test();
	return 0;
}