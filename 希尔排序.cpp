#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

// ϣ��������
void shellSort(vector<int>& arr) {
    int n = arr.size();

    // ��ʼ��������У�ͨ��ʹ�� n/2 ��ʼ��ÿ�μ���
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // �� gap ��ʼ����ÿ��Ԫ�ؽ��м����������,�����Ұ�ߵ�������ǰ���Ӧ�����ֽ��в������� 
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // ���浱ǰԪ��
            int j;

            // ���Ѿ��ź�������������ҵ����ʵ�λ�ò��뵱ǰԪ��
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; // Ԫ�غ���
            }
            arr[j] = temp; // ���뵱ǰԪ��
        }
    }
}

int main() {
    vector<int> arr = {12, 34, 54, 2, 3,3,7,23};

    cout << "����ǰ������: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    // ����ϣ��������
    shellSort(arr);

    cout << "����������: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

