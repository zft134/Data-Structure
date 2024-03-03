//KMP算法模板 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int nex[100];  // 存储模式串的Next数组，最大长度为100

// 计算模式串的Next数组
void GetNext(char sub[], int nex[], int lenSub) {
    nex[0] = -1;  // 初始化第一个元素为-1，表示从头开始匹配
    nex[1] = 0;   // 初始化第二个元素为0，表示第一个字符匹配失败时回退到模式串的起始位置

    int j = 0;    // 当前下标，用于遍历模式串
    int k = -1;   // 前一项的k，即前一项回退的下标

    // 从第三个元素开始计算 Next 数组
    while (j + 1 < lenSub) {//j+1<lenSub是防止j越界，因为后续有j++ 
        if (k == -1 || sub[j] == sub[k]) {
            j++;
            nex[j] = k + 1;  // 当前位置匹配成功时进到k+1
            k++;
        } else {
            k = nex[k];  // 当前位置匹配失败时，回退到前一项的Next值
        }
    }
}


// KMP算法实现
int KMP(char str[], char sub[]) {
	//先求出主串和模式串的长度 
    int lenStr = strlen(str);
    int lenSub = strlen(sub);
    //如果主串或者模式串有一个长度为0则无法匹配 
    if (lenStr == 0 || lenSub == 0) {
        return -1;
    }
    //调用GetNext函数求解nex数组 
    GetNext(sub, nex, lenSub);
    
    int i = 0;//主串的当前下标 
    int j = 0;//模式串的当前下标 

    // 主串和模式串进行匹配
    while (i < lenStr && j < lenSub) {
        if (j == -1 || str[i] == sub[j]) {//如果j==-1说明已经从头开始匹配，或者是匹配成功 
            i++;
            j++;
        } else {//匹配失败则回退到下一个nex[j] 
            j = nex[j];
        }
    }

    // 判断是否匹配成功
    if (j >= lenSub) {
        return i - j;  // 匹配成功，返回在主串中的起始位置
    }
    //如果没匹配成功则返回-1 
    return -1;
}

int main() {
    char str[100];//主串 
    char sub[100];//模式串
	 
    // 输入主串
    cout << "Enter the main string: ";
    cin >> str;
    getchar();  // 读取换行符

    // 输入模式串
    cout << "Enter the pattern string: ";
    cin >> sub;
    getchar();  // 读取换行符

    int ans = KMP(str, sub);//调用KMP算法 

    // 输出匹配结果
    if (ans == -1) {
        cout << "失配" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
/*
输入样例1：
abeababeabf
abeabf
输出结果1：
5
输入样例2：
ahsga
mnja
输出样例2：
失配
*/

