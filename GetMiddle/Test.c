//三数取中法选基准值
#include<stdio.h>

int GetMiddle(int *array, int begin, int end){
	int mid = (begin + end) >> 1;
	//三数判断
	if (array[begin] < array[mid]){
		if (array[mid] < array[end]){ //begin<mid<end
			return mid;
		}
		else if (array[begin] < array[end]){ //begin<end<mid
			return end;
		}
		else{
			return begin;
		}
	}
	else{
		// begin>mid
		if (array[end] < array[mid]){ //end<mid<begin
			return mid;
		}
		else if (array[begin]>array[end]){ //mid<end<begin
			return end;
		}
		else{
			return begin;
		}
	}
}