#pragma once
#include<stdio.h>
#include<stdbool.h>

typedef struct{
	char array[100];
	int top;
}Stack;

//��ʼ��
void StackInit(Stack *s){
	s->top = 0;
}

//ѹջ��ʵ����β�壩
void StackPush(Stack*s, char v){
	s->array[s->top++] = v;
}

//��ջ
void StackPop(Stack*s){
	s->top--;
}

//�鿴ջ��Ԫ��
int StackTop(Stack*s){
	return s->array[s->top - 1];
}

//�鿴Ԫ�ظ���
int StackSize(Stack *s){
	return s->top;
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(Stack *s){
	return s->top == 0;//ջΪ�շ��� true
}

