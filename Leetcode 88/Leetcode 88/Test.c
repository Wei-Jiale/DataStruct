//给定两个整数有序顺序表 array1和array2
//将array2合并到array1中 
//使array1成为一个有序顺序表
//初始化 array1的元素数量为m
//初始化 array2的元素数量为n
//假设 array1有足够的空间用来储存array2中的元素

void merge(int* array1, int array1size, int m, int* array2, int array2size, int n){
	int dst = m - 1;
	int src = n - 1;
	int k = m + n - 1;

	for (dst, src; dst >= 0 && src >= 0;){
		if (array1[dst]>array2[src]){
			array1[k--] = array1[dst--];
		}
		else{
			array1[k--] = array2[src--];
		}
	}

	//array2剩余元素
	if (src >= 0){
		memcpy(array1, array2, (src + 1)*sizeof(int));
	}
}

//双指针同时从后向前遍历两数组
//较大值放入array1的最后一个再k--
//如此循环