//堆排序
//堆排序的时间复杂度：O(nlogn)
/*
堆排序思想：
数组构造完全二叉树：

用数组构造完全二叉树是极简单的，只要知道在完全二叉树中，非叶子结点 i 的左孩子是 2i ，右孩子是2i + 1 （当然，前提是2i和2i+1都不能大于n，即总结点数）

而除根节点外，每个结点的父节点为 i / 2 。完全二叉树的根就是堆的堆顶。大顶堆：是指每个非叶子结点都比孩子大。

排序过程：

 为方便理解，假设堆（数组）大小为 n + 1 （位置 0 的数据为空，有效数据下标从 1 到 n ）  

 首先找到完全二叉树中最后的一个非叶子结点（可根据结点数量（数组长度）算出：n / 2 ）

步骤1：比较这个非叶子结点自身的数据与孩子的数据，如果某个孩子的数值最大，则将自身与这个孩子交换
交换完毕后，轮到前一个非叶子结点进行步骤1（整个过程从下往上，直至整个堆变成大顶堆）
步骤2：当堆变成大顶堆后，将堆顶（下标为 1）与最后一个叶子结点（下标为 n）进行交换（也就是说最后一个结点变成了最大值，完成一次排序，该结点往后视作不算入这个完全二叉树中的排序中）
此时，整个堆已经不是大顶堆了，需要再重复步骤1，将堆变成大顶堆，只不过这一次是从下标1~n-1开始，变成大顶堆后，继续重复步骤2；接着又再重复步骤1，从下标1~n-2 开始将堆变成大顶堆 ....
当重复步骤1时的下标是从1~1时，即完成整个堆的排序
*/


#include"stdio.h"
 
void swap(int arr[],int a,int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp; 
}
 
void HeapAdjust(int arr[],int index,int len){
	int dex = index;
	int lchild = dex*2;
	int rchild = dex*2 + 1;
	
	if(lchild<len && arr[dex]<arr[lchild]){
		dex = lchild;
	} 
	if(rchild<len && arr[dex]<arr[rchild]){
		dex = rchild;
	} 
	if(dex!=index){
		swap(arr,dex,index);
		HeapAdjust(arr,dex,len);  //完成一次排序，就要检验是否破坏了被交换后的孩子树的大顶堆模式（再次进行【步骤1】：保证堆是大顶堆） 
	}
}
 
void HeapSort(int arr[],int len){
	
	for(int i = len / 2;i>0;i--){
		HeapAdjust(arr,i,len);
	}
	//以上的操作就是【步骤1】：形成了一次大顶堆，此时堆顶是最大的元素 
	
	//接下来就是【步骤2】：逐个排出最大数到数组尾部，完成排序 
	for(int i = len;i>0;i--){
		swap(arr,1,i);
		HeapAdjust(arr,1,i);  
	} 
}
void print(int arr[],int len){
	for(int i = 1;i<=len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
 
int main(){
	int arr[11] = {0,40,100,90,20,80,70,60,30,50,10};  //第一个数据非有效数据，实际数组长度应为10
	int len = (sizeof(arr)/sizeof(int))-1;
	HeapSort(arr,len);
	print(arr,len);
	return 0;
}