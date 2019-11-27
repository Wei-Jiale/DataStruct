#pragma once
#include<stdio.h>
#include<stdbool.h>

typedef struct{
	char array[100];
	int top;
}Stack;

//初始化
void StackInit(Stack *s){
	s->top = 0;
}

//压栈（实际是尾插）
void StackPush(Stack*s, char v){
	s->array[s->top++] = v;
}

//出栈
void StackPop(Stack*s){
	s->top--;
}

//查看栈顶元素
int StackTop(Stack*s){
	return s->array[s->top - 1];
}

//查看元素个数
int StackSize(Stack *s){
	return s->top;
}

//判断栈是否为空
bool StackEmpty(Stack *s){
	return s->top == 0;//栈为空返回 true
}

