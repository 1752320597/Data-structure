//二叉树——计算叶子数量

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
//二叉树结点
typedef struct BINARYNODE{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;
 
// 计算叶子结点
int CaculateLeftNum(BinaryNode* root,int num){
	
	if(root==NULL){
		return 0;
	}
	
	if(root->lchild==NULL && root->rchild==NULL){
		num++;
	}
 
	//左子树叶子结点数目
	int left = CaculateLeftNum(root->lchild,num);
	//右子树叶子结点数目
	int right = CaculateLeftNum(root->rchild,num);
	
	return left + right + num;
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
	
	int num = 0;
	int sum = CaculateLeftNum(&node1,num);
	printf("叶子的数目：%d\n",sum);
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
计算叶子结点
int CaculateLeftNum(BinaryNode* root){
	
	if(root==NULL){
		return 0;
	}
	int num = 0;
	if(root->lchild==NULL && root->rchild==NULL){
		num = 1;
	}
 
	//左子树叶子结点数目
	int left = CaculateLeftNum(root->lchild);
	//右子树叶子结点数目
	int right = CaculateLeftNum(root->rchild);
	
	return left + right + num;
}
*/