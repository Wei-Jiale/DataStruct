#include"stack.h"

//ջ�ĳ�ʼ��
void StackInit(Stack* ps){
	ps->array = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//��ջ
void StackPush(Stack* ps, STDataType data){
	assert(ps);
	//ջ�������
	if (ps->top == ps->capacity){
		size_t newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		ps->array = (STDataType*)realloc(ps->array, newcapacity*sizeof(STDataType));
		ps->capacity = newcapacity;
	}
	ps->array[ps->top] = data;
	ps->top++;
}

//��ջ
void StackPop(Stack* ps){
	assert(ps&&ps->top > 0);
	ps->top--;
}

//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps){
	assert(ps);
	return ps->array[ps->top - 1];
}

//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps){
	assert(ps);
	return ps->top;
}

//���ջ�Ƿ�Ϊ�գ�Ϊ�շ��ط���������Ϊ�շ���0��
int StackEmpty(Stack* ps){
	assert(ps);
	return ps->top == 0 ? 1 : 0;
}

//����ջ
void StackDestroy(Stack* ps){
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->top = 0;
}



//���ŵ�ƥ��
bool isValid(char * s){
	//����ͳ�ʼ��
	Stack st;
	StackInit(&st);
	//����ջ�ĺ���ȳ�

	//�����ַ���
	while (*s){
		//ǰ������ջ
		if (*s == '{' || *s == '(' || *s == '['){
			StackPush(&st, *s);
		}
		else if (*s == '}'){
			if (StackEmpty(&st)){
				return false;
			}
			char top = StackTop(&st);
			//��ջ����ȡ����һ��
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
			//��ջ����ȡ����һ��
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
			//��ջ����ȡ����һ��
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