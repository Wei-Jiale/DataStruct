#include "SeqList.h"
int main(){
#if 0
	SeqList *p = SeqListInit();//��ʼ��,������Ч�ռ�ĵ�ַ
#endif
	SeqList seqlist;
	SeqListInit(&seqlist,10);

	SeqListDestroy(&seqlist);


} 