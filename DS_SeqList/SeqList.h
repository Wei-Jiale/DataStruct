#pragma once

////静态顺序表
//typedef struct SeqList{
//	int array[100];
//	int size;//顺序表中实际存储的数据个数
//}SeqList;//别名


//动态顺序表
typedef struct SeqList{
	int* array;//动态从堆上申请
	int capacity;//容量
	int size;//有效数据的个数  尾插时，可用位置的下标
}SeqList;

//初始化
void SeqListInit(SeqList *ps,int capacity);

//销毁
void SeqListDestroy(SeqList *ps);

//增删查改
//尾插
void SeqListPushBack(SeqList *ps, int v);
//头插
void SeqListPushFront(SeqList *ps, int v);
//根据pos下标插入
void SeqListInsert(SeqList *ps, int pos, int v);

//尾删
void SeqListPopBack(SeqList *ps);

//头删
void SeqListPopFront(SeqList *ps);

//根据pos下标删除
void SeqListErase(SeqList *ps, int pos);

//查找
int SeqListFind(SeqList *ps, int v);

//更新
void SeqListModify(SeqList *ps, int pos, int v);

//删除第一个遇到的v
int SeqListRemove(SeqList *ps, int v);

//删掉所有遇到的v
int SeqListRemoveAll(SeqList *ps, int v);



