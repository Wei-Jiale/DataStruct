#include"Heap.h"

int main()
{
	int a[10] = { 27, 15, 19, 34, 65, 37, 25, 49, 28, 18 };
	Heap hp;

	HeapCreate(&hp, a, 10);
	HeapPrint(&hp);

	HeapPush(&hp, 0);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	if(!HeapEmpty(&hp)){
		printf("%d ", HeapTop(&hp));
	}

	return 0;
}