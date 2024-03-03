//KMP�㷨ģ�� 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int nex[100];  // �洢ģʽ����Next���飬��󳤶�Ϊ100

// ����ģʽ����Next����
void GetNext(char sub[], int nex[], int lenSub) {
    nex[0] = -1;  // ��ʼ����һ��Ԫ��Ϊ-1����ʾ��ͷ��ʼƥ��
    nex[1] = 0;   // ��ʼ���ڶ���Ԫ��Ϊ0����ʾ��һ���ַ�ƥ��ʧ��ʱ���˵�ģʽ������ʼλ��

    int j = 0;    // ��ǰ�±꣬���ڱ���ģʽ��
    int k = -1;   // ǰһ���k����ǰһ����˵��±�

    // �ӵ�����Ԫ�ؿ�ʼ���� Next ����
    while (j + 1 < lenSub) {//j+1<lenSub�Ƿ�ֹjԽ�磬��Ϊ������j++ 
        if (k == -1 || sub[j] == sub[k]) {
            j++;
            nex[j] = k + 1;  // ��ǰλ��ƥ��ɹ�ʱ����k+1
            k++;
        } else {
            k = nex[k];  // ��ǰλ��ƥ��ʧ��ʱ�����˵�ǰһ���Nextֵ
        }
    }
}


// KMP�㷨ʵ��
int KMP(char str[], char sub[]) {
	//�����������ģʽ���ĳ��� 
    int lenStr = strlen(str);
    int lenSub = strlen(sub);
    //�����������ģʽ����һ������Ϊ0���޷�ƥ�� 
    if (lenStr == 0 || lenSub == 0) {
        return -1;
    }
    //����GetNext�������nex���� 
    GetNext(sub, nex, lenSub);
    
    int i = 0;//�����ĵ�ǰ�±� 
    int j = 0;//ģʽ���ĵ�ǰ�±� 

    // ������ģʽ������ƥ��
    while (i < lenStr && j < lenSub) {
        if (j == -1 || str[i] == sub[j]) {//���j==-1˵���Ѿ���ͷ��ʼƥ�䣬������ƥ��ɹ� 
            i++;
            j++;
        } else {//ƥ��ʧ������˵���һ��nex[j] 
            j = nex[j];
        }
    }

    // �ж��Ƿ�ƥ��ɹ�
    if (j >= lenSub) {
        return i - j;  // ƥ��ɹ��������������е���ʼλ��
    }
    //���ûƥ��ɹ��򷵻�-1 
    return -1;
}

int main() {
    char str[100];//���� 
    char sub[100];//ģʽ��
	 
    // ��������
    cout << "Enter the main string: ";
    cin >> str;
    getchar();  // ��ȡ���з�

    // ����ģʽ��
    cout << "Enter the pattern string: ";
    cin >> sub;
    getchar();  // ��ȡ���з�

    int ans = KMP(str, sub);//����KMP�㷨 

    // ���ƥ����
    if (ans == -1) {
        cout << "ʧ��" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
/*
��������1��
abeababeabf
abeabf
������1��
5
��������2��
ahsga
mnja
�������2��
ʧ��
*/

