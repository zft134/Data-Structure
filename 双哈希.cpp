//˫��ϣ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;

typedef unsigned long long ull;

ull base = 131; // ��ϣ����Ļ���
const int N = 10010;

// �洢��ϣֵ�Ľṹ��
struct data {
    ull x, y; // ������ϣֵ��ʹ��˫��ϣ
} a[N];

char s[N]; // ������ַ���
int n, ans = 1; // �ַ���������ȥ�غ�Ľ������

ull mod1 = 19260817; // ��һ����ϣ��ģ��
ull mod2 = 19660813; // �ڶ�����ϣ��ģ��

// �����һ����ϣֵ
ull hash1(char s[]) {
    int len = strlen(s);
    ull ans = 0;
    for(int i = 0; i < len; i++) {
        ans = (ans * base) + (ull)s[i] % mod1; // ʹ��base��Ϊ������mod1��Ϊģ�����ۼ��ַ��Ĺ�ϣֵ
    }
    return ans;
}

// ����ڶ�����ϣֵ
ull hash2(char s[]) {
    int len = strlen(s);
    ull ans = 0;
    for(int i = 0; i < len; i++) {
        ans = (ans * base) + (ull)s[i] % mod2; // ʹ��base��Ϊ������mod2��Ϊģ�����ۼ��ַ��Ĺ�ϣֵ
    }
    return ans;
}

// �ȽϺ�������������
bool comp(data a, data b) {
    return a.x < b.x; // ���յ�һ����ϣֵ������������
}

int main() {
    cin >> n; // �����ַ�������
    for(int i = 1; i <= n; i++) {
        cin >> s; // �����ַ���
        a[i].x = hash1(s); // �����һ����ϣֵ
        a[i].y = hash2(s); // ����ڶ�����ϣֵ
    }

    sort(a + 1, a + n + 1, comp); // �Թ�ϣֵ��������

    for(int i = 2; i <= n; i++) {
        // �����ǰ�ַ����Ĺ�ϣֵ��ǰһ����ͬ����˵�����µ��ַ�����ȥ�ؽ��������һ
        if(a[i].x != a[i - 1].x || a[i].y != a[i - 1].y) {
            ans++;
        }
    }

    cout << ans << endl; // ���ȥ�غ�Ľ������
}

/*
�������ݣ�
5
abc
aaaa
abc
abcc
12345
������ݣ�
4 
*/

