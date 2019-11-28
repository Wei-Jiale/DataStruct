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

//1.有效的括号
bool StackEmpty(Stack*s){
	return s->top == 0;
}
bool isValid(char* s){
	Stack stack;
	StackInit(&stack);
	//遍历字符
	char*p = s;
	while (*p)
	{
		char ch = *p;
		switch (ch){
		case'(':
		case'[':
		case'{':
			StackPush(&stack, ch);
			break;
		case')':
		case']':
		case'}':{
					//判断栈是不是为空
					if (StackEmpty(&stack)){
						return false;
					}
					//取出栈顶元素
					char left = StackTop(&stack);
					//开始匹配
					if ((left == '('&&ch == ')')
						|| (left == '['&&ch == ']')
						|| (left == '{'&&ch == '}')){
						//匹配出栈
						StackPop(&stack);
					}
					//左右不是一种括号
					else{
						return false;
					}
		}
		default:
			break;
		}
		p++;
	}
	if (StackEmpty(&stack)){
		//左括号多
		return true;
	}
	else{
		return false;
	}
}