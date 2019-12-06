#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
	int data; 
	struct node* left, *right; 
};  
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*) 
						malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return(node); 
} 
int height(struct node* node) 
{ 
	if (node==NULL) 
		return 0; 
	else
	{ 
		int lheight = height(node->left); 
		int rheight = height(node->right); 
		if (lheight > rheight) 
			return(lheight+1); 
		else return(rheight+1); 
	} 
} 
void printGivenLevel(struct node* root, int level) 
{ 
	if (root == NULL) 
		return; 	
	if (level == 1) 
	printf("%d ", root->data);	
	else if (level > 1) 
	{ 
		printGivenLevel(root->left, level-1); 
		printGivenLevel(root->right, level-1); 
	} 
}
void printLevelOrder(struct node* root) 
{ 
	int h = height(root); 
	int i; 
	for (i=1; i<=h; i++)
	printGivenLevel(root, i); 
}
int main() 
{ 
	struct node *root = newNode(1); 
	root->left	 = newNode(2); 
	root->right	 = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(7); 
	root->right->left = newNode(6); 
	printf("Level Order traversal of binary tree is \n"); 
	printLevelOrder(root); 
	return 0; 
}
