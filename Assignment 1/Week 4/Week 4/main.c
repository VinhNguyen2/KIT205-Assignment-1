#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "bst.h"


void prompt_data(BST *tree) {
	int quit = false;
	int data;

	while (!quit) {
		printf("Enter some data: ");
		scanf("%d", &data);

		if (data == 0) {
			quit = true;
		}
		else {
			insert_bst(tree, data);
		}
	}
}

int main() {
	BST tree = create_bst();

	//data test = { 7, 9, 8, 2, 1, 4, 3, 6};


	prompt_data(&tree);

	print_pre_order_bst(&tree);
	printf("\n");
	print_in_order_bst(&tree);
	printf("\n");
	print_post_order_bst(&tree);
	printf("\n");

	printf("height: %d", bst_height(&tree));

	return 0;
}