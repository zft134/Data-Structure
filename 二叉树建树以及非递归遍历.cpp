// �����������Լ��ǵݹ����

#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>��
#include<stack> 
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
    linkqueue* q = new linkqueue;
    q->front = q->rear = new qnode;
    if(q->front == NULL){
        cout << "����ʧ��" << endl; 
    } else{
        q->front->next = NULL;
    }
    return q;
}

// ���
void enqueue(linkqueue* q, BTNode* x){
    lqueue s = new qnode;
    s->data = x;
    s->next = NULL;
    q->rear->next = s;
    q->rear = s;
}

// ����
BTNode* dequeue(linkqueue* q){ // ���Ӳ���������һ��ָ����е�ָ�����
    BTNode* x; // ����һ��ָ��������ڵ��ָ�����x
    if(q->front->next == NULL){ // ������е�ͷ�ڵ����һ���ڵ�Ϊ�գ�������Ϊ��
        cout << "��" << endl; // ���"��"��ʾ����Ϊ��
    } else{
        lqueue p = q->front->next; // ����һ��ָ����еĽڵ��ָ�����p��������ָ����еĵ�һ���ڵ�
        x = p->data; // ��ȡ�ڵ�p�����ݣ�����ֵ������x
        q->front->next = p->next; // �����е�ͷ�ڵ�ָ��p����һ���ڵ㣬��ɾ���ڵ�p
        if(q->rear == p) q->rear = q->front; // ����ڵ�pǡ���Ƕ�β�ڵ㣬�򽫶�βָ��rearָ����е�ͷ���ڵ�front
        free(p); // �ͷŽڵ�p���ڴ�ռ�
        return x; // ���ر�ȡ���Ľڵ������
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
    BTNode* node = new BTNode;
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
    BinaryTree* tree = new BinaryTree;
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
void perOrderBTree(BinaryTree* tree){
	BTNode* node;
	if(tree->root){//���ڵ���� 
		stack<BTNode*> st;
		st.push(tree->root);//���ڵ���ջ 
		
		while(!st.empty()){//ջ�ǿ� 
			node=st.top();//ȡ��ջ��Ԫ�� 
			st.pop();
			visitBTNode(node);//����ջ��Ԫ�� 
			
			//���Һ�����ջ��֮��������ջ 
			if(node->right)st.push(node->right);
			
			if(node->left)st.push(node->left);
		}
	}
}

// �������
// ����ҵ�˳�����������
void inOrderBTree(BinaryTree *tree){
	if(tree->root){
		BTNode* node=tree->root;
		stack<BTNode*> st;
		
		while(!st.empty()||node){//ջ�ǿջ��߽ڵ���� 
			if(node){//������Ӵ�����һֱ�����ߣ����������Ӷ���ջ 
				st.push(node);
				node=node->left;
			}else{//�����ȡջ���ڵ���ʲ������������Һ��� 
				node=st.top();
				st.pop();
				visitBTNode(node);
				node=node->right;
			}
		}
	}
}

// �������
// ���Ҹ���˳�����������
//����˫ջʵ�� 
void postOrderBTree(BinaryTree* tree){
	if(tree->root){
		BTNode* node=tree->root;
		stack<BTNode*> st1;
		stack<BTNode*> st2;
		st1.push(node);//���ڵ�����ջ
		
		while(!st1.empty()){
			node=st1.top();
			st1.pop();//ջ1ջ��������ѹ��ջ2 
			st2.push(node);
			//���Һ��ӷֱ�����ջ1 
			if(node->left)st1.push(node->left);
			if(node->right)st1.push(node->right);	
		}
		
		while(!st2.empty()){//����ջ2 
				node=st2.top();
				st2.pop();
				visitBTNode(node);
			} 
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
