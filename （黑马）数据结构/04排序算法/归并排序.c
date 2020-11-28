//归并排序（快、稳定、占用空间大）
//时间复杂度：O(nlogn)
/*归并排序核心思想：
先将一个无序数组进行不断分解，最终分解成单个元素为一组的有序形式，使用递归
将这个单个元素不断进行两两组合成一个一个的有序数组，将这些合成好的有序数组放到临时数组中进行保存，使用递归
最后将临时数组的值依次赋给原数组
先分后合，使用递归不断分解，最后不断合成
*/
//合并函数
void Merge(int *sourceArr, int *tempArr, int left, int right, int mid)//传入原数组、临时数组、起始左端索引、结束右端索引、和中间值
{
	int i_left = left;//左半部分起点
	int i_right = mid;//左半部分终点
	int j_left = mid + 1;//右半部分起点
	int j_right = right;//右半部分终点
	int length = 0; //表示辅助空间元素
	while (i_left <= i_right && j_left <= j_right)//当左端起点小于等于左端终点，右端起点小于右端终点，即左右两端都还没有为空的情况下
	{
		if (sourceArr[i_left] < sourceArr[j_left])//左右从起始点依次进行比较，将值较小的放到零时数组中存储，然后一段索引值和临时数组索引值分别加一
		{
			tempArr[length] = sourceArr[i_left];
			i_left++;
			length++;
		}

		else                                      //左右从起始点依次进行比较，将值较小的放到零时数组中存储，然后一段索引值和临时数组索引值分别加一
		{
			tempArr[length] = sourceArr[j_left];
			j_left++;
			length++;
		}
	}
	while (i_left <= i_right)//当右端为空的情况下，将左端剩余的值依次放到零时数组中
	{
		tempArr[length] = sourceArr[i_left];
		i_left++;
		length++;
	}

	while (j_left <= j_right)//当左端为空的情况下，将端右剩余的值依次放到零时数组中
	{
		tempArr[length] = sourceArr[j_left];
		j_left++;
		length++;
	}
	for (int i = 0; i < length; i++)//从（函数传进来的）起始点开始，依次将临时数组中的值赋值给原数组
		sourceArr[left + i] = tempArr[i];//覆盖要从传进来的起始端开始
}

//内部使用递归
void MergeSort(int *sourceArr, int *tempArr, int left, int right)//传入原数组、临时数组、起始左端索引、结束右端索引
{
	if (left >= right)//当左边索引大于右端索引时结束
	{
		return;
	}
	int mid = (left+ right) / 2//将数组从中间分成左和右两部分
	MergeSort(sourceArr, tempArr, left, mid);//左端进行再分，数组无序的情况下才会传进去进行分割，返回的都是有序的数组，即最底层都是单个数据为一个数组为止 
	MergeSort(sourceArr, tempArr, mid + 1, right);//右端进行再分割
	Merge(sourceArr, tempArr, left , right, mid);//合并函数 

}