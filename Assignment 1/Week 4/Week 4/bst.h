#pragma once
/**
 *Vinh Nguyen #470821
 */

/**
 * Data type for a node in a binary search tree
 */
typedef struct bstNode {
	int data_item;
	struct bstNode *left;
	struct bstNode *right;
} *BSTNodePtr;


typedef struct bst {
	BSTNodePtr root;
} BST;


/**
 * Create a new instance of a binary search tree 
 */
BST create_bst();

/**
 *Find specific node in a binary search tree
 */
BSTNodePtr find_bst(BST *self, int n);

/**
 * Insert a new node into a binary search tree and return a new tree 
 */
void insert_bst(BST *self, int n);

/**
 * Remove a value from a binary search tree
 * @param self tree
 * @param n value to remove
 */
void delete_bst(BST *self, int n);

/**
 * Print a binary search tree using pre-order format
 */
void print_pre_order_bst(BST *tree);

/**
 * Print a binary search tree using in-order format
 */
void print_in_order_bst(BST *tree);

/**
 * Print a binary search tree using post-order format
 */
void print_post_order_bst(BST *tree);

/**
 * Calculate the height of a binary search tree and return height of tree
 */
int bst_height(BST *self);
