#include<iostream>
#include<vector>

using namespace std;

//交换数组中的两个元素 
void swap(vector<int> &arr,int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
} 

// 将指定位置的元素向下调整，使其满足堆的性质
void heapify(vector<int>& arr, int size, int i) {
    int largest = i;    // 最大值索引
    int left = 2 * i + 1;    // 左子节点索引
    int right = 2 * i + 2;   // 右子节点索引

    // 找出当前节点、左子节点、右子节点中的最大值索引
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大值索引不是当前节点索引，则交换它们并递归调整子树
    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, size, largest);
    }
}

 
 //堆排序函数 
void heapSort(vector<int> &arr){
	int size=arr.size();
	
	for(int i=size/2-1;i>=0;i--){
		heapify(arr,size,i);
	}
	
	//从堆顶开始取出最大值并重新调整堆，直到堆空
	for(int i=size-1;i>=0;i--){
		swap(arr,0,i);//将堆顶元素（最大值）与当前末尾元素交换
		heapify(arr,i,0);//重新调整堆 
	} 
}
void Print(vector<int> &arr){
	for(int num:arr)cout<<num<<" ";
	cout<<endl;
}
int main()
{
	vector<int> arr={3,5,7,2,6};
	
	cout<<"排序前的数组:"<<endl;
	Print(arr);
	
	heapSort(arr);
	
	cout<<"排序后的数组:"<<endl;
	Print(arr);
	
	return 0;
}
