//二叉树——计算高度

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h" 
 
//二叉树结点
typedef struct BINARYNODE{
char ch;
struct BINARYNODE* lchild;
struct BINARYNODE* rchild;
}BinaryNode;
 
//计算树的高度
int CD(BinaryNode* root){
 
	if(root==NULL){
	return 0;
	}
	
	int depth = 0;
	
	int ld = CD(root->lchild);
	int rd = CD(root->rchild);
	depth = ld > rd ? ld + 1 : rd + 1;
	
	return depth;
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
	BinaryNode node9 = {'I',NULL,NULL};
	BinaryNode node10 = {'J',NULL,NULL};
	
	//建立结点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;
	node8.rchild = &node9; 
	node9.lchild = &node10; 
	
	//int num = 0;
	int sum = CD(&node1);
	printf("高度：%d\n",sum);
}
 
 
void test01(){
	CreateBinaryTree();
}
 
int main(){
	test01();
	return 0;
}

/*
或者
int CaculateLeftNum(BinaryNode* root){
	
	if(root==NULL){
		return 0;
	}
 
	int left = CaculateLeftNum(root->lchild);
	int right = CaculateLeftNum(root->rchild);
	
	return left>right?left+1:right+1;
}

*/