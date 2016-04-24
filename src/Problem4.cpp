/*

Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.

Example 1:
Input : 
   20        25
  /  \      /  \
 5    30   10   35
Output :
Bst 1 :
     20
   /   \
  5     30
   \   /  \
   10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,Any 1 of those correct ways would be fine .
Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs 
(Both r1 and r2 shouldnt be NULL at the time of Input)

Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.

You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard 
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void traverse(struct node*, struct node*);
void insert_node(struct node *, struct node *);

void merge_two_bst(struct node *root1, struct node *root2){
	if (root1 == NULL || root2 == NULL){
		return;
	}
	traverse(root1, root2);
}
void traverse(struct node *r1, struct node *r2){		//post order traversal.
	if (r2 == NULL){
		return;
	}
	traverse(r1, r2->left);
	traverse(r1, r2->right);
	insert_node(r1, r2);
}
void insert_node(struct node *r1, struct node *ins){
	if (r1 == NULL){
		return;
	}
	struct node *p;
	p = r1;
	for (; r1 != NULL;){
		p = r1;
		if (r1->data <= ins->data){
			r1 = r1->right;
		}
		else if (r1->data>ins->data){
			r1 = r1->left;
		}
	}
	if (p->data <= ins->data){
		p->right = ins;
		p = p->right;
	}
	else if(p->data>ins->data){
		p->left = ins;
		p = p->left;
	}
	p->left = p->right = NULL;
}