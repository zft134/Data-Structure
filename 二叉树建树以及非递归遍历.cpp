// 二叉树建树以及非递归遍历

#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>‘
#include<stack> 
using namespace std;

// 定义二叉树节点结构体
typedef struct BTNode{
    char show;              // 节点的数据
    struct BTNode* left;    // 左孩子节点指针
    struct BTNode* right;   // 右孩子节点指针
} BTNode;

// 定义二叉树结构体
typedef struct{
    BTNode* root;   // 根节点指针
    int count;      // 节点个数
} BinaryTree;

// 链式队列节点结构体
typedef struct qnode{
    BTNode* data;           // 数据指针
    struct qnode* next;     // 下一个节点指针
} qnode, *lqueue;

// 链式队列结构体
typedef struct linkqueue{
    lqueue front, rear;     // 队列头尾指针
} linkqueue;

// 初始化队列
linkqueue* initqueue(){
    linkqueue* q = new linkqueue;
    q->front = q->rear = new qnode;
    if(q->front == NULL){
        cout << "分配失败" << endl; 
    } else{
        q->front->next = NULL;
    }
    return q;
}

// 入队
void enqueue(linkqueue* q, BTNode* x){
    lqueue s = new qnode;
    s->data = x;
    s->next = NULL;
    q->rear->next = s;
    q->rear = s;
}

// 出队
BTNode* dequeue(linkqueue* q){ // 出队操作，接受一个指向队列的指针参数
    BTNode* x; // 声明一个指向二叉树节点的指针变量x
    if(q->front->next == NULL){ // 如果队列的头节点的下一个节点为空，即队列为空
        cout << "空" << endl; // 输出"空"表示队列为空
    } else{
        lqueue p = q->front->next; // 声明一个指向队列的节点的指针变量p，并将其指向队列的第一个节点
        x = p->data; // 获取节点p的数据，并赋值给变量x
        q->front->next = p->next; // 将队列的头节点指向p的下一个节点，即删除节点p
        if(q->rear == p) q->rear = q->front; // 如果节点p恰好是队尾节点，则将队尾指针rear指向队列的头部节点front
        free(p); // 释放节点p的内存空间
        return x; // 返回被取出的节点的数据
    }
}

// 判断队空函数
int empty(linkqueue* q){
    if(q->front->next == NULL){
        return 0;
    } else{
        return 1;
    }
} 

// 创建节点
BTNode* createBTNode(char show){
    BTNode* node = new BTNode;
    memset(node, 0, sizeof(BTNode));
    node->show = show;
    return node;
}

// 初始化树根节点
void initBTreeRoot(BinaryTree* tree, BTNode* node){
    tree->count = 1;
    tree->root = node;
}

// 创建树
BinaryTree* createBTree(BTNode* root){
    BinaryTree* tree = new BinaryTree;
    if(root){ // 非空树
        initBTreeRoot(tree, root);
    } else{   // 空树
        tree->root = NULL;
        tree->count = 0;
    }
    return tree;
}

// 插入节点
// 在树中插入newNode节点，该节点的双亲节点为parent
// flag==1则该节点为左孩子，flag==0则该节点为右孩子 
void insertBTNode(BinaryTree* tree, BTNode* parent, BTNode* newNode, int flag){
    if(flag == 1){
        parent->left = newNode;
    } else{
        parent->right = newNode;
    }
    tree->count++;
}

// 访问一个节点
void visitBTNode(BTNode* node){
    if(node){
        cout << node->show << " ";
    }
}

// 广度优先遍历
// 从根节点开始，逐层遍历二叉树
void levelOrderBTree(BinaryTree* tree){
    linkqueue* que = initqueue();
    enqueue(que, tree->root); // 树根节点入队
    
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

// 先序遍历
// 根左右的顺序遍历二叉树
void perOrderBTree(BinaryTree* tree){
	BTNode* node;
	if(tree->root){//根节点存在 
		stack<BTNode*> st;
		st.push(tree->root);//根节点入栈 
		
		while(!st.empty()){//栈非空 
			node=st.top();//取出栈顶元素 
			st.pop();
			visitBTNode(node);//访问栈顶元素 
			
			//先右汉字入栈，之后左孩子入栈 
			if(node->right)st.push(node->right);
			
			if(node->left)st.push(node->left);
		}
	}
}

// 中序遍历
// 左根右的顺序遍历二叉树
void inOrderBTree(BinaryTree *tree){
	if(tree->root){
		BTNode* node=tree->root;
		stack<BTNode*> st;
		
		while(!st.empty()||node){//栈非空或者节点存在 
			if(node){//如果左孩子存在则一直向左走，并将做孩子都入栈 
				st.push(node);
				node=node->left;
			}else{//否则就取栈顶节点访问并接下来访问右孩子 
				node=st.top();
				st.pop();
				visitBTNode(node);
				node=node->right;
			}
		}
	}
}

// 后序遍历
// 左右根的顺序遍历二叉树
//基于双栈实现 
void postOrderBTree(BinaryTree* tree){
	if(tree->root){
		BTNode* node=tree->root;
		stack<BTNode*> st1;
		stack<BTNode*> st2;
		st1.push(node);//根节点先入栈
		
		while(!st1.empty()){
			node=st1.top();
			st1.pop();//栈1栈顶弹出，压入栈2 
			st2.push(node);
			//左右孩子分别先入栈1 
			if(node->left)st1.push(node->left);
			if(node->right)st1.push(node->right);	
		}
		
		while(!st2.empty()){//访问栈2 
				node=st2.top();
				st2.pop();
				visitBTNode(node);
			} 
	} 
}


// 初始化一棵具体的树
// 创建并初始化一棵具体的二叉树，返回根节点指针
BinaryTree* initBTree(){
    // 初始化节点
    BTNode* a = createBTNode('A');
    BTNode* b = createBTNode('B');
    BTNode* c = createBTNode('C');
    BTNode* d = createBTNode('D');
    BTNode* e = createBTNode('E');
    BTNode* f = createBTNode('F');
    BTNode* g = createBTNode('G');
    BTNode* h = createBTNode('H');
    BTNode* i = createBTNode('I');
    
    // 初始化树根
    BinaryTree* tree = createBTree(a);
    
    // 插入
    insertBTNode(tree, a, b, 1);
    insertBTNode(tree, a, e, 0);
    insertBTNode(tree, b, c, 0);
    insertBTNode(tree, c, d, 1);
    insertBTNode(tree, e, f, 0);
    insertBTNode(tree, f, g, 1);
    insertBTNode(tree, g, h, 1);
    insertBTNode(tree, g, i, 0);
    
    return tree;    // 返回树根节点
} 

int main(){
    BinaryTree* tree = initBTree();
    
    cout << "层次遍历\n"; 
    levelOrderBTree(tree);
    
    cout << "\n前序遍历\n";
    perOrderBTree(tree);
    
    cout << "\n中序遍历\n";
    inOrderBTree(tree);
    
    cout << "\n后序遍历\n";
    postOrderBTree(tree);
    
    return 0;
}
/*
输出：
层次遍历
A B E C F D G H I
前序遍历
A B C D E F G H I
中序遍历
B D C A E H G I F
后序遍历
D C B H I G F E A
*/ 
