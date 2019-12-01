#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//创建
typedef int SLDatetype;

typedef struct Seqlist{
	SLDatetype *array;
	size_t size;
	size_t capacity;
}	Seqlist;

//初始化
void SeqlistInit(Seqlist*ps);

//销毁
void SeqlistDestory(Seqlist*ps);

//打印
void Print(Seqlist*ps);

//扩容
void CheckCapacity(Seqlist*ps);

//头插
void PushFront(Seqlist*ps, SLDatetype x);

//尾插
void PushBack(Seqlist*ps, SLDatetype x);

//头删
void PopFront(Seqlist*ps);

//尾删
void PopBack(Seqlist*ps);

//查找
int SeqlistFind(Seqlist*ps, SLDatetype x);

//在pos位置插入
void SeqlistInsert(Seqlist*ps, size_t pos, SLDatetype x);

//在pos位置删除
void SeqlistErase(Seqlist*ps, size_t pos);