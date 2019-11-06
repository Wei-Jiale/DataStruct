#include "SeqList.h"
int main(){
#if 0
	SeqList *p = SeqListInit();//初始化,返回有效空间的地址
#endif
	SeqList seqlist;
	SeqListInit(&seqlist,10);

	SeqListDestroy(&seqlist);


} 