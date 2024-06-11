#include<iostream>

using namespace std;

//选择排序函数
void selectionSort(int arr[],int n)
{
	int min_idx;
	
	//遍历数组
	for(int i=0;i<n-1;i++)
	{//找到未排序部分中的最小元素
		min_idx=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min_idx]){
				min_idx=j;//更新最小值的索引 
			}
		} 
	
		if(min_idx!=i){//交换最小元素与第i个元素 
			arr[min_idx]=arr[min_idx]^arr[i];
			arr[i]=arr[min_idx]^arr[i];
			arr[min_idx]=arr[min_idx]^arr[i];
		}	
	 } 
 } 

void printArray(int arr[],int size)
{
	for(int i=0;i<size;i++)cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int arr[]={32,56,342,2,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"排序前的数组:"<<endl;
	printArray(arr,n);
	cout<<"排序后的数组:"<<endl;
	selectionSort(arr,n);
	printArray (arr,n);
	return 0;
 } 
