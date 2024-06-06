#include<iostream>
#include<vector>

using namespace std;

//直接插入排序函数，升序排序 
void insertionSort(vector<int>& arr){
	int n=arr.size();//先获取数组的长度 
	//从第二个元素开始，下标为1，逐个元素进行插入
	for(int i=1;i<n;i++){
		int key=arr[i];//当前要插入的元素
		int j=i-1;
		
		//在已排序部分中从后向前扫描，找到合适的位置插入 
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];//将比key大的元素向后移动 
			j--;
		} 
		//此时说明后面的数都比key大，即跳出循环的位置是正确的位置 
		arr[j+1]=key;//将key插入到正确的位置 
	} 
} 
int main()
{
	vector<int> arr={6,5,4,3,1};
	
	cout << "排序前的数组: ";
	for(int num:arr){
		cout<<num<<" ";
	}
	cout<<endl;
	
	//调用插入排序函数
	insertionSort(arr);
	
	//打印排序后的数组
	cout<<"排序后的数组：";
	for(int num:arr){
		cout<<num<<" ";
	} 
	cout<<endl;
	
	return 0;
}
