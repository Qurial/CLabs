#include <stdio.h>
#include <stdlib.h>

struct node {
	int item;
	struct node* left;
	struct node* right;
};

void PrintTree(struct node* root)
{
	if (root == NULL) return;
	PrintTree(root->left);
	printf("%d ", root->item);
	PrintTree(root->right);
}

struct node* createNode(value)
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode->item = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

struct node* insertLeft(struct node* root, int value)
{
	root->left = createNode(value);
	return root->left;
}

struct node* insertRight(struct node* root, int value)
{
	root->right = createNode(value);
	return root->right;
}

/*struct node* addBalanced(struct node* root, int value)
{
	if (root == NULL)
	{
		root = createNode(value);
		return root;
	}
	
	else if (root->item != NULL && value > root->item)
	{
		addBalanced(root->right, value);
	}
	else if (root->item != NULL && value < root->item)
	{
		addBalanced(root->left, value);
	}
}*/
struct node* insert(struct node* node, int value) {
	// Return a new node if the tree is empty
	if (node == NULL) return createNode(value);

	// Traverse to the right place and insert the node
	if (value < node->item)
		node->left = insert(node->left, value);
	else if (value > node->item)
		node->right = insert(node->right, value);

	return node;
}

void balanceTree(struct node* root, struct node* balancedRoot)
{
	//balancedRoot = createNode(root->item);
	if (root == NULL) return;
	balanceTree(root->left, balancedRoot);
	insert(balancedRoot, root->item);
	balanceTree(root->right, balancedRoot);
}

int main() {
	struct node* root = createNode(1);
	insertLeft(root, 2);
	insertRight(root, 3);
	insertLeft(root->left, 4);
	insertRight(root->left, 5);
	insertLeft(root->right, 6);

	printf("\Not balanced tree:\n");
	PrintTree(root);

	struct node* BalancedRoot = createNode(root->item);
	balanceTree(root, BalancedRoot);

	printf("\nBalanced tree:\n");
	PrintTree(BalancedRoot);
}