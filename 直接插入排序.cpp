#include<iostream>
#include<vector>

using namespace std;

//ֱ�Ӳ������������������� 
void insertionSort(vector<int>& arr){
	int n=arr.size();//�Ȼ�ȡ����ĳ��� 
	//�ӵڶ���Ԫ�ؿ�ʼ���±�Ϊ1�����Ԫ�ؽ��в���
	for(int i=1;i<n;i++){
		int key=arr[i];//��ǰҪ�����Ԫ��
		int j=i-1;
		
		//�������򲿷��дӺ���ǰɨ�裬�ҵ����ʵ�λ�ò��� 
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];//����key���Ԫ������ƶ� 
			j--;
		} 
		//��ʱ˵�������������key�󣬼�����ѭ����λ������ȷ��λ�� 
		arr[j+1]=key;//��key���뵽��ȷ��λ�� 
	} 
} 
int main()
{
	vector<int> arr={6,5,4,3,1};
	
	cout << "����ǰ������: ";
	for(int num:arr){
		cout<<num<<" ";
	}
	cout<<endl;
	
	//���ò���������
	insertionSort(arr);
	
	//��ӡ����������
	cout<<"���������飺";
	for(int num:arr){
		cout<<num<<" ";
	} 
	cout<<endl;
	
	return 0;
}
