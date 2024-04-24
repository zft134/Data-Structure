// �����������Լ��ݹ����

#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h> 
using namespace std;

// ����������ڵ�ṹ��
typedef struct BTNode{
    char show;              // �ڵ������
    struct BTNode* left;    // ���ӽڵ�ָ��
    struct BTNode* right;   // �Һ��ӽڵ�ָ��
} BTNode;

// ����������ṹ��
typedef struct{
    BTNode* root;   // ���ڵ�ָ��
    int count;      // �ڵ����
} BinaryTree;

// ��ʽ���нڵ�ṹ��
typedef struct qnode{
    BTNode* data;           // ����ָ��
    struct qnode* next;     // ��һ���ڵ�ָ��
} qnode, *lqueue;

// ��ʽ���нṹ��
typedef struct linkqueue{
    lqueue front, rear;     // ����ͷβָ��
} linkqueue;

// ��ʼ������
linkqueue* initqueue(){
    linkqueue* q = (linkqueue*)malloc(sizeof(linkqueue));
    q->front = q->rear = (lqueue)malloc(sizeof(qnode));
    if(q->front == NULL){
        cout << "����ʧ��" << endl; 
    } else{
        q->front->next = NULL;
    }
    return q;
}

// ���
void enqueue(linkqueue* q, BTNode* x){
    lqueue s = (lqueue)malloc(sizeof(qnode));
    s->data = x;
    s->next = NULL;
    q->rear->next = s;
    q->rear = s;
}

// ����
BTNode* dequeue(linkqueue* q){
    BTNode* x;
    if(q->front->next == NULL){
        cout << "��" << endl;
    } else{
        lqueue p = q->front->next;
        x = p->data;
        q->front->next = p->next;
        if(q->rear == p) q->rear = q->front;
        free(p);
        return x;   
    }
}

// �ж϶ӿպ���
int empty(linkqueue* q){
    if(q->front->next == NULL){
        return 0;
    } else{
        return 1;
    }
} 

// �����ڵ�
BTNode* createBTNode(char show){
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    memset(node, 0, sizeof(BTNode));
    node->show = show;
    return node;
}

// ��ʼ�������ڵ�
void initBTreeRoot(BinaryTree* tree, BTNode* node){
    tree->count = 1;
    tree->root = node;
}

// ������
BinaryTree* createBTree(BTNode* root){
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if(root){ // �ǿ���
        initBTreeRoot(tree, root);
    } else{   // ����
        tree->root = NULL;
        tree->count = 0;
    }
    return tree;
}

// ����ڵ�
// �����в���newNode�ڵ㣬�ýڵ��˫�׽ڵ�Ϊparent
// flag==1��ýڵ�Ϊ���ӣ�flag==0��ýڵ�Ϊ�Һ��� 
void insertBTNode(BinaryTree* tree, BTNode* parent, BTNode* newNode, int flag){
    if(flag == 1){
        parent->left = newNode;
    } else{
        parent->right = newNode;
    }
    tree->count++;
}

// ����һ���ڵ�
void visitBTNode(BTNode* node){
    if(node){
        cout << node->show << " ";
    }
}

// ������ȱ���
// �Ӹ��ڵ㿪ʼ��������������
void levelOrderBTree(BinaryTree* tree){
    linkqueue* que = initqueue();
    enqueue(que, tree->root); // �����ڵ����
    
    while(empty(que) == 1){
        BTNode* node = dequeue(que);
        visitBTNode(node);
        if(node->left != NULL){
            enqueue(que, node->left);
        }
        if(node->right != NULL){
            enqueue(que, node->right);
        }
    } 
}

// �������
// �����ҵ�˳�����������
void perOrder(BTNode* node){
    if(node){
        visitBTNode(node);
        perOrder(node->left);
        perOrder(node->right);
    }
}

// �������������
void perOrderBTree(BinaryTree* tree){
    if(tree->root){
        perOrder(tree->root);
    }
}

// �������
// ����ҵ�˳�����������
void inOrder(BTNode* node){
    if(node){
        inOrder(node->left);
        visitBTNode(node);
        inOrder(node->right);
    }
}

// �������������
void inOrderBTree(BinaryTree* tree){
    if(tree->root){
        inOrder(tree->root);
    }
}

// �������
// ���Ҹ���˳�����������
void postOrder(BTNode* node){
    if(node){
        postOrder(node->left);
        postOrder(node->right);
        visitBTNode(node);
    }
}

// �������������
void postOrderBTree(BinaryTree* tree){
    if(tree->root){
        postOrder(tree->root);
    }
}

// ��ʼ��һ�þ������
// ��������ʼ��һ�þ���Ķ����������ظ��ڵ�ָ��
BinaryTree* initBTree(){
    // ��ʼ���ڵ�
    BTNode* a = createBTNode('A');
    BTNode* b = createBTNode('B');
    BTNode* c = createBTNode('C');
    BTNode* d = createBTNode('D');
    BTNode* e = createBTNode('E');
    BTNode* f = createBTNode('F');
    BTNode* g = createBTNode('G');
    BTNode* h = createBTNode('H');
    BTNode* i = createBTNode('I');
    
    // ��ʼ������
    BinaryTree* tree = createBTree(a);
    
    // ����
    insertBTNode(tree, a, b, 1);
    insertBTNode(tree, a, e, 0);
    insertBTNode(tree, b, c, 0);
    insertBTNode(tree, c, d, 1);
    insertBTNode(tree, e, f, 0);
    insertBTNode(tree, f, g, 1);
    insertBTNode(tree, g, h, 1);
    insertBTNode(tree, g, i, 0);
    
    return tree;    // ���������ڵ�
} 

int main(){
    BinaryTree* tree = initBTree();
    
    cout << "��α���\n"; 
    levelOrderBTree(tree);
    
    cout << "\nǰ�����\n";
    perOrderBTree(tree);
    
    cout << "\n�������\n";
    inOrderBTree(tree);
    
    cout << "\n�������\n";
    postOrderBTree(tree);
    
    return 0;
}
/*
�����
��α���
A B E C F D G H I
ǰ�����
A B C D E F G H I
�������
B D C A E H G I F
�������
D C B H I G F E A
*/ 
