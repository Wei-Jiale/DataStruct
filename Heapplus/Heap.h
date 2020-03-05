#pragma once
#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef int HpDataType;
typedef struct Heap{
	HpDataType* _a;//数组
	size_t _size;//数组大小
	size_t _capacity;//数组容量
}Heap;


//向下调整
void AdjustDown(HpDataType* a, size_t n, int root);

//建堆:把一个无序的数组变为满足堆的性质
void HeapCreate(Heap* hp, HpDataType* _a, size_t n);

//向上调整
void AdjustUp(HpDataType* a, int child);

//入堆
void HeapPush(Heap* hp, HpDataType x);

//出堆
void HeapPop(Heap* hp);

//获取堆顶元素
HpDataType HeapTop(Heap* hp);

//判断堆是否为空
int HeapEmpty(Heap* hp);

//打印堆
void HeapPrint(Heap* hp);

//堆销毁
void HeapDestory(Heap* hp);
