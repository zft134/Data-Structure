//双哈希 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;

typedef unsigned long long ull;

ull base = 131; // 哈希计算的基数
const int N = 10010;

// 存储哈希值的结构体
struct data {
    ull x, y; // 两个哈希值，使用双哈希
} a[N];

char s[N]; // 输入的字符串
int n, ans = 1; // 字符串数量和去重后的结果数量

ull mod1 = 19260817; // 第一个哈希的模数
ull mod2 = 19660813; // 第二个哈希的模数

// 计算第一个哈希值
ull hash1(char s[]) {
    int len = strlen(s);
    ull ans = 0;
    for(int i = 0; i < len; i++) {
        ans = (ans * base) + (ull)s[i] % mod1; // 使用base作为基数，mod1作为模数，累加字符的哈希值
    }
    return ans;
}

// 计算第二个哈希值
ull hash2(char s[]) {
    int len = strlen(s);
    ull ans = 0;
    for(int i = 0; i < len; i++) {
        ans = (ans * base) + (ull)s[i] % mod2; // 使用base作为基数，mod2作为模数，累加字符的哈希值
    }
    return ans;
}

// 比较函数，用于排序
bool comp(data a, data b) {
    return a.x < b.x; // 按照第一个哈希值进行升序排序
}

int main() {
    cin >> n; // 输入字符串数量
    for(int i = 1; i <= n; i++) {
        cin >> s; // 输入字符串
        a[i].x = hash1(s); // 计算第一个哈希值
        a[i].y = hash2(s); // 计算第二个哈希值
    }

    sort(a + 1, a + n + 1, comp); // 对哈希值进行排序

    for(int i = 2; i <= n; i++) {
        // 如果当前字符串的哈希值与前一个不同，则说明是新的字符串，去重结果数量加一
        if(a[i].x != a[i - 1].x || a[i].y != a[i - 1].y) {
            ans++;
        }
    }

    cout << ans << endl; // 输出去重后的结果数量
}

/*
输入数据：
5
abc
aaaa
abc
abcc
12345
输出数据：
4 
*/

