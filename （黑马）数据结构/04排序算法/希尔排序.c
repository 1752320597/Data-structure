//希尔排序
//希尔排序的时间复杂度：O(n^{\tfrac{3}{2}})
/*
希尔排序核心思想：
希尔排序是插入排序的改进版本（插入排序类）

核心思想：原本插入排序是对一整个数组的数据进行逐个比较的，而希尔排序是将整个数组划分为若干部分，然后分别进行插入排序，形成基本有序的序列（小的基本在前面，大的基本在后面），最后对整个数组再用一次插入排序。

例如：

以下是对数组进行间隔增量increment为2的分组，然后分别进行插入排序，最后再进行一次插入排序

下标： 

             0    2    4    6       一次插入排序

                1    3    5          二次插入排序

             0 1 2 3 4 5 6       最后一次整体插入排序

*/

void Shell(int arr[],int length){
	int i,j;
	int increment = 2;
	for(i=0;i<length;i+=increment){
		if(arr[i+increment]<arr[i]){
		int temp = arr[i+increment];
		for(j=i;j>=0&&temp<arr[j+2];j-=increment){
		    	arr[j+increment]=arr[j];
		}
		arr[j+increment]= temp;
	}
  }
  for(i=1;i<length;i+=increment){
		if(arr[i+increment]<arr[i]){
		int temp = arr[i+increment];
		for(j=i;j>=0&&temp<arr[j+2];j-=increment){
		    	arr[j+increment]=arr[j];
		}
		arr[j+increment]= temp;
	}
  }
  for(i=1;i<length;i++){
		if(arr[i]<arr[i-1]){
		int temp = arr[i];
		for(j=i-1;j>=0&&temp<arr[j];j--){
		    	arr[j+1]=arr[j];
		}
		arr[j+1]= temp;
	}
  }
}



/*
稍微弄得简洁点：（把两次的插入排序整个在一块
*/
void Shell(int arr[],int length){
	int i,j;
	int increment = 2;
	for(int n=0;n<increment;n++){
		for(i=0;i<length;i+=increment){
			if(arr[i+increment]<arr[i]){
			int temp = arr[i+increment];
			for(j=i;j>=0&&temp<arr[j+2];j-=increment){
			    	arr[j+increment]=arr[j];
		    }
		arr[j+increment]= temp;
        	}
        }
	}
    for(i=1;i<length;i++){
		if(arr[i]<arr[i-1]){
		int temp = arr[i];
		for(j=i-1;j>=0&&temp<arr[j];j--){
		    	arr[j+1]=arr[j];
		}
		arr[j+1]= temp;
	}
  }
}


/*
问题是，对组数进行希尔排序，选取多大的间隔增量才是合适的呢？

前人已经总结出来了： 间隔增量：increment  =  length / 3  + 1 

（顺便把最后一次的整体插入排序都整合进去）
*/

#include"stdio.h"
 
void swap1(int a[],int i,int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void swap2(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void print(int a[],int length){
	for(int i=0;i<length;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
}
 
void Shell(int arr[],int length){
	int i,j,n;
	int increment = length;
	
	do{
		increment = increment/3 + 1;
		
		for(n = 0;n<increment;n++){
		  for(i = n+increment;i<length;i+=increment){
			  if(arr[i]<arr[i-increment]){
				int temp = arr[i];
				for(j=i-increment;j>=0&&temp<arr[j];j-=increment){
				    	arr[j+increment]=arr[j];
		           }
				arr[j+increment]= temp;
			  }
		  }
		}
	}while(increment>1);
}
 
int main(){
	int a[14] = {4,1,9,5,7,2,6,8,3,10,13,12,11,0};
	Shell(a,14);
	print(a,14);
	return 0;
}