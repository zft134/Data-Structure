#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

// 希尔排序函数
void shellSort(vector<int>& arr) {
    int n = arr.size();

    // 初始化间隔序列，通常使用 n/2 开始，每次减半
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 从 gap 开始，对每个元素进行间隔插入排序,即对右半边的数字与前面对应的数字进行插入排序 
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // 保存当前元素
            int j;

            // 在已经排好序的子序列中找到合适的位置插入当前元素
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; // 元素后移
            }
            arr[j] = temp; // 插入当前元素
        }
    }
}

int main() {
    vector<int> arr = {12, 34, 54, 2, 3,3,7,23};

    cout << "排序前的数组: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    // 调用希尔排序函数
    shellSort(arr);

    cout << "排序后的数组: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

