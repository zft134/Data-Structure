#include<iostream>

using namespace std;

//ѡ��������
void selectionSort(int arr[],int n)
{
	int min_idx;
	
	//��������
	for(int i=0;i<n-1;i++)
	{//�ҵ�δ���򲿷��е���СԪ��
		min_idx=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min_idx]){
				min_idx=j;//������Сֵ������ 
			}
		} 
	
		if(min_idx!=i){//������СԪ�����i��Ԫ�� 
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
	cout<<"����ǰ������:"<<endl;
	printArray(arr,n);
	cout<<"����������:"<<endl;
	selectionSort(arr,n);
	printArray (arr,n);
	return 0;
 } 
