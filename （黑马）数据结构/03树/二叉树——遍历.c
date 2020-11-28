//二叉树——遍历

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
 
//二叉树结点
typedef struct BINARYNODE{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;
 
void Recursion1(BinaryNode* root);
void Recursion2(BinaryNode* root);
void Recursion3(BinaryNode* root);
 
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
	
	printf("前序遍历：");
	Recursion1(&node1);
	printf("\n中序遍历：");
	Recursion2(&node1);
	printf("\n后序遍历：");
	Recursion3(&node1);
}
/***
递归遍历 ：
	前序-中序-后序	 
***/
 
//前序遍历
void Recursion1(BinaryNode* root){
	
	if(root == NULL){
		return ;
	}
	//访问根结点
	printf("%c",root->ch);
	//遍历左子树
	Recursion1(root->lchild);
	//遍历右子树
	Recursion1(root->rchild);
}
//中序遍历
void Recursion2(BinaryNode* root){
	
	if(root == NULL){
		return ;
	}
	//遍历左子树
	Recursion2(root->lchild);
	//访问根结点
	printf("%c",root->ch);	
	//遍历右子树
	Recursion2(root->rchild);
}
//后序遍历
void Recursion3(BinaryNode* root){
	
	if(root == NULL){
		return ;
	}
	//遍历左子树
	Recursion3(root->lchild);
	//遍历右子树
	Recursion3(root->rchild);
	//访问根结点
	printf("%c",root->ch);
}
 
void test01(){
	CreateBinaryTree();
}
 
int main(){
	test01();
	return 0;
}