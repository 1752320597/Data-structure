//二叉树——拷贝与释放


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
//二叉树结点
typedef struct BINARYNODE{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;
 
//遍历二叉树(前序)
void Recursion(BinaryNode* root){
	if(root==NULL){
		return ;
	}
	printf("%c",root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);
}
 
BinaryNode* CopyBinaryTree(BinaryNode* root){
	if(root==NULL){
		return NULL;
	}
	//拷贝左子树
	BinaryNode* lchild = CopyBinaryTree(root->lchild);
	//拷贝右子树
	BinaryNode* rchild = CopyBinaryTree(root->lchild);
	//创建结点
	BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
	newnode->ch = root->ch;
	newnode->lchild = root->lchild;
	newnode->rchild = root->rchild;
	
	return newnode;
}
 
//释放二叉树内存
void FreeSpaceBinary(BinaryNode* root){
	
	if(root==NULL){
		return ;
	}
	//释放左子树
	FreeSpaceBinary(root->lchild);
	//释放右子树
	FreeSpaceBinary(root->rchild);
	//释放当前结点
	free(root);
}
 
 
void CreateBinaryTree(){
	//创建结点
	BinaryNode node1 = {'A',NULL,NULL};
	BinaryNode node2 = {'B',NULL,NULL};
	BinaryNode node3 = {'C',NULL,NULL};
	BinaryNode node4 = {'D',NULL,NULL};
	BinaryNode node5 = {'E',NULL,NULL};
	BinaryNode node6 = {'F',NULL,NULL};
	BinaryNode node7 = {'G',NULL,NULL};
	BinaryNode node8 = {'H',NULL,NULL};
	
	//建立结点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;
	
	BinaryNode* root = CopyBinaryTree(&node1);
	Recursion(root);
	printf("\n");
	FreeSpaceBinary(root); 
}
 
 
void test01(){
	CreateBinaryTree();
}
 
int main(){
	test01();
	return 0;
}