#include"stack.h"

//栈的初始化
void StackInit(Stack* ps){
	ps->array = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//入栈
void StackPush(Stack* ps, STDataType data){
	assert(ps);
	//栈满的情况
	if (ps->top == ps->capacity){
		size_t newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		ps->array = (STDataType*)realloc(ps->array, newcapacity*sizeof(STDataType));
		ps->capacity = newcapacity;
	}
	ps->array[ps->top] = data;
	ps->top++;
}

//出栈
void StackPop(Stack* ps){
	assert(ps&&ps->top > 0);
	ps->top--;
}

//获取栈顶元素
STDataType StackTop(Stack* ps){
	assert(ps);
	return ps->array[ps->top - 1];
}

//获取栈中有效元素个数
int StackSize(Stack* ps){
	assert(ps);
	return ps->top;
}

//检测栈是否为空（为空返回非零结果，不为空返回0）
int StackEmpty(Stack* ps){
	assert(ps);
	return ps->top == 0 ? 1 : 0;
}

//销毁栈
void StackDestroy(Stack* ps){
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->top = 0;
}



//括号的匹配
bool isValid(char * s){
	//定义和初始化
	Stack st;
	StackInit(&st);
	//利用栈的后进先出

	//遍历字符串
	while (*s){
		//前括号入栈
		if (*s == '{' || *s == '(' || *s == '['){
			StackPush(&st, *s);
		}
		else if (*s == '}'){
			if (StackEmpty(&st)){
				return false;
			}
			char top = StackTop(&st);
			//出栈才能取到下一个
			StackPop(&st);
			if (top != '{'){
				return false;
			}
		}
		else if (*s == ')'){
			if (StackEmpty(&st)){
				return false;
			}
			char top = StackTop(&st);
			//出栈才能取到下一个
			StackPop(&st);
			if (top != '('){
				return false;
			}
		}
		else if (*s == ']'){
			if (StackEmpty(&st)){
				return false;
			}
			char top = StackTop(&st);
			//出栈才能取到下一个
			StackPop(&st);
			if (top != '['){
				return false;
			}
		}
		s++;
	}

	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}