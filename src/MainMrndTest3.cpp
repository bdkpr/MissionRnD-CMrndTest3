#include <stdio.h>
#include "FunctionHeadersMrndTest3.h"
#include <stdlib.h>"
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};

void printArray(int *arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void printDLL(struct node_dll *root){
	while (root != NULL){
		printf("%d ", root->data);
		root = root->next;
	}
	printf("\n");
}

void printBST(struct node * root){
	if (root != NULL){
		printBST(root->left);
		printf("%d ", root->data);
		printBST(root->right);
	}
}

struct enode *newENode_spec(char *str)
{
	struct enode *temp = (struct enode *)malloc(sizeof(struct enode));
	int i = 0;
	while (str[i] != '\0'){
		temp->data[i] = str[i];
		i++;
	}
	temp->data[i] = '\0';
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct enode * constructEBinaryTree_spec(char strs[][6], int len){
	struct enode *root = NULL;
	struct enode *nodes[2005];
	for (int i = 0; i < len; i++){
		nodes[i] = newENode_spec(strs[i]);
	}
	int mid = (len / 2);
	for (int i = 0; i < mid; i++){
		struct enode *curnode = nodes[i];
		struct enode *leftnode = nodes[(i * 2) + 1];
		struct enode *rightnode = nodes[(i * 2) + 2];
		if (curnode->data[0] != 'X'){
			if (leftnode->data[0] != 'X'){
				curnode->left = leftnode;
			}
			if (rightnode->data[0] != 'X'){
				curnode->right = rightnode;
			}
		}
	}
	root = nodes[0];
	return root;
}
void test_Problem3_spec(char strs[][6], int len, int ans){
	struct enode *root = constructEBinaryTree_spec(strs, len);
	int actual = solve_tree(root);
	//Assert::AreEqual(ans, actual, L"Failed sample 0 for NULL case in P1", 1, 2);
}
int main(){
	//Test here
	char strs[][6] = { "+", "5", "*", "X", "X", "a", "3" };
	int len = 7;
	int ans = -1;
	test_Problem3_spec(strs, len, ans);
}