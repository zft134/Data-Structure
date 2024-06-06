#include <iostream>
#include <vector>

using namespace std;

// ���ֲ��Һ��������ش�����λ�õ�����
int binarySearch(vector<int>& arr, int item, int l, int r) {
    while (l < r) {
        int mid = (l + r) / 2; // �����м�λ��
        if (item <= arr[mid]) {
            r = mid; // ����벿�ֲ��ң����� mid
        } else {
            l = mid + 1; // ���Ұ벿�ֲ���
        }
    }
    
    //lָ���һ����С��item���� 
    return l; // ���ز���λ��
}

// ���ֲ���������
void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // �ҵ�����λ��
        int loc = binarySearch(arr, key, 0, j);

        // �ƶ�Ԫ����Ϊ����Ԫ���ڳ��ռ�
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // ����Ԫ��
    }
}


int main() {
    vector<int> arr = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};

    cout << "����ǰ������: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    binaryInsertionSort(arr);

    cout << "����������: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

