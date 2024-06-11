#include<iostream>
#include<vector>

using namespace std;

//���������е�����Ԫ�� 
void swap(vector<int> &arr,int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
} 

// ��ָ��λ�õ�Ԫ�����µ�����ʹ������ѵ�����
void heapify(vector<int>& arr, int size, int i) {
    int largest = i;    // ���ֵ����
    int left = 2 * i + 1;    // ���ӽڵ�����
    int right = 2 * i + 2;   // ���ӽڵ�����

    // �ҳ���ǰ�ڵ㡢���ӽڵ㡢���ӽڵ��е����ֵ����
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // ������ֵ�������ǵ�ǰ�ڵ��������򽻻����ǲ��ݹ��������
    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, size, largest);
    }
}

 
 //�������� 
void heapSort(vector<int> &arr){
	int size=arr.size();
	
	for(int i=size/2-1;i>=0;i--){
		heapify(arr,size,i);
	}
	
	//�ӶѶ���ʼȡ�����ֵ�����µ����ѣ�ֱ���ѿ�
	for(int i=size-1;i>=0;i--){
		swap(arr,0,i);//���Ѷ�Ԫ�أ����ֵ���뵱ǰĩβԪ�ؽ���
		heapify(arr,i,0);//���µ����� 
	} 
}
void Print(vector<int> &arr){
	for(int num:arr)cout<<num<<" ";
	cout<<endl;
}
int main()
{
	vector<int> arr={3,5,7,2,6};
	
	cout<<"����ǰ������:"<<endl;
	Print(arr);
	
	heapSort(arr);
	
	cout<<"����������:"<<endl;
	Print(arr);
	
	return 0;
}
