//选择排序（中等、不稳定）
//时间复杂度 O(n²)
/*选择排序核心思想：
从数组的第一个元素开始，依次和后面的值进行比较，当有更小的值的时候，
那就使用这个更小的值和后面的值进行比较，直到得到最小的值。
然后把这个最小值放到第一个位置，那么这个元素就是有序的，然后从第二个元素开始比较，、
以此类推，最后得到有序的数组，
从先往后，先指定位置的排序。
*/

void sort_select_up(int* a,int len)//传入数组和数组长度
{
	int i = 0;
	int j = 0;
	int k = 0;
	int temp;
	for(i=0;i<len-1;i++)//外循环控制轮数，当数组有n个元素的时候，就进行n-1轮循环排序
	{
		k = i; //定义索引值k，记录比较所得数组中最小值的下标索引
		for(j=i+1;j<len;j++)/*内循控制每一轮元素和元素之间的比较，从第k个元素开始，依次和后面的值进行比较，当有更小的值的时候，那就使用这个更小的值和后面的值进行比较，直到得到最小的值。*/
		{
			if(a[k]>a[j])
			{
				k = j;	
			}			
		}
		if(i!=k) //最后将这个最小的值放到起始k的位置上。
		{
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;	
		}	
	}
}