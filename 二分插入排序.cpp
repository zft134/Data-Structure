#include <iostream>
#include <vector>

using namespace std;

// 二分查找函数，返回待插入位置的索引
int binarySearch(vector<int>& arr, int item, int l, int r) {
    while (l < r) {
        int mid = (l + r) / 2; // 计算中间位置
        if (item <= arr[mid]) {
            r = mid; // 在左半部分查找，包括 mid
        } else {
            l = mid + 1; // 在右半部分查找
        }
    }
    
    //l指向第一个不小于item的数 
    return l; // 返回插入位置
}

// 二分插入排序函数
void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // 找到插入位置
        int loc = binarySearch(arr, key, 0, j);

        // 移动元素以为插入元素腾出空间
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // 插入元素
    }
}


int main() {
    vector<int> arr = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};

    cout << "排序前的数组: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    binaryInsertionSort(arr);

    cout << "排序后的数组: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

