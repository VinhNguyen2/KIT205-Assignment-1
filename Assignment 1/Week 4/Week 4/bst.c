#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
/**
 *Vinh Nguyen #470821
 */

/**
 * Create a new instance of a binary search tree
 */
BST create_bst() {
	BST tree;
	tree.root = NULL;
	return tree;
}

/**
 * Find specific node in a binary search tree
 */
BSTNodePtr find_bst_node(BSTNodePtr self, int n) {

	if (self == NULL || n == self->data_item) {
		return self;
	}

	if (n < self->data_item) {
		return find_bst_node(self->left, n);
	}
	return find_bst_node(self->right, n);
}

/**
 * Locate specific node in a binary search tree
 */
BSTNodePtr find_bst(BST *self, int n) {
	return find_bst_node(self->root, n);
}

/**
 * Insert a new node into a binary search tree and retur a new tree 
 */
BSTNodePtr insert_bst_node(BSTNodePtr self, int n) {
	/* check if found correct the location, then insert */
	if (self == NULL) { 
		self = malloc(sizeof *self);
		self->data_item = n;
		self->left = self->right = NULL;

	}
	else if (n < self->data_item) {
		self->left = insert_bst_node(self->left, n);
	}
	else if (n > self->data_item) {
		self->right = insert_bst_node(self->right, n);
	}

	return self;
}

/**
 * Insert a value in a binary search tree
 */
void insert_bst(BST *self, int n) {
	self->root = insert_bst_node(self->root, n);
}

/**
 * Find the minimum node in a given branch
 */
BSTNodePtr min_node(BSTNodePtr self) {
	BSTNodePtr current = self;
	// while there is a left branch
	while (current->left != NULL) {
		// move down the branch
		current = current->left;
	}
	return current;
}

/**
 * Remove a node from a binary search tree and return modified tree
 */
BSTNodePtr delete_bst_node(BSTNodePtr self, int n) {
	if (self != NULL) {
		if (self->data_item == n) {
			if (self->left != NULL && self->right != NULL) {
				BSTNodePtr successor = min_node(self->right);
				self->data_item = successor->data_item;
				self->right = delete_bst_node(self->right, self->data_item);

			}
			else {
				BSTNodePtr to_free = self;
				self = self->left ? self->left : self->right;
				free(to_free);
			}
		}
		else if (n < self->data_item) {
			self->left = delete_bst_node(self->left, n);
		}
		else {
			self->right = delete_bst_node(self->right, n);
		}
	}
	return self;
}

/**
 * Remove a value from a binary search tree
 */
void delete_bst(BST *self, int n) {
	self->root = delete_bst_node(self->root, n);
}


/**
* print a binary search tree using pre-order format
*/
void print_pre_order_bst_node(BSTNodePtr self) {
	if (self != NULL) {
		printf("(");
		printf("%d", self->data_item);
		print_pre_order_bst_node(self ->left);
		print_pre_order_bst_node(self->right);
		printf(")");
	}else {
		printf("_");
	}
}

void print_pre_order_bst(BST *self) {
	print_pre_order_bst_node(self->root);
}

/**
* print a binary search tree using post-order format
*/
void print_post_order_bst_node(BSTNodePtr self) {
	if (self != NULL){
		printf("(");
		print_post_order_bst_node(self->left);
		print_post_order_bst_node(self->right);
		printf("%d", self->data_item);
		printf(")");
	}else{
		printf("_");
	}
}

void print_post_order_bst(BST *self) {
	print_post_order_bst_node(self->root);
}

/**
* print a binary search tree using in-order format
*/
void print_order_bst_node(BSTNodePtr self) {
	if (self != NULL) {
		printf("(");
		print_order_bst_node(self->left);
		printf("%d", self->data_item);
		print_order_bst_node(self->right);
		printf(")");
	}
	else {
		printf("_");
	}
}

void print_in_order_bst(BST *self) {
	print_order_bst_node(self->root);
}


/**
 * Calculate the height of a binary search tree node
 */
int bst_node_height(BSTNodePtr self) {

	if (self == NULL) {
		return 0;
	}

	int left_height = bst_node_height(self->left);
	int right_height = bst_node_height(self->right);

	return 1 + (left_height > right_height ? left_height : right_height);
}

/**
 * Calculate the height of a binary search tree and return height of tree
 */
int bst_height(BST *self) {
	return bst_node_height(self->root);
}