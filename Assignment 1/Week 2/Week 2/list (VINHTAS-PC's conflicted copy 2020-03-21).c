#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/**
Create a new instance of the list type
and return an empty list
*/
List new_list() {
	List temp;
	temp.head = NULL;
	return temp;
}

/*
Traverse a list and print the data in each node to the screen
*/
void print_list(List *self) {
	ListNodePtr current = self->head;

	while (current != NULL) {
		printf("%d", current->data);
		current = current->next;

		if (current != NULL) {
			printf("_");
		}
	}
	printf("\n");
}

/*
Insert a new element at the front of the list
*/
void insert_at_front(List *self, int data) {
	ListNodePtr new_node = malloc(sizeof *new_node);

	new_node->data = data;
	new_node->next = self->head;
	
	self->head = new_node;
}

/*
Insert a new element in an ordered list
*/

void insert_in_order(List *self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	ListNodePtr new_node = malloc(sizeof *new_node);
	new_node->data;
	new_node->next = NULL;

	while (current !=NULL && current->data < data){
		prev = current;
		current = current->next;
	}

	if (current == self->head) { // inserting at the front
		new_node->next = current;
		self->head = new_node;
	}
	else{
		new_node->next = current;
		prev->next = new_node;
	}
}

/*
Delete an item from a list
*/
void delete_list(List *self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

while(current!= NULL) {

		if (current->data == data) {
			if (prev == NULL) {
				self->head = current->next;
				free(current);
				current = self->head;
			}
			else {
		 		prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

/*
Delete all items in the list
*/
void destroy_list(List *self) {
	ListNodePtr current = self->head;
	 
	/*treversse entire list*/
	while (current !=NULL){
		ListNodePtr to_free = current;
		current = current->next;
		free(to_free);
	}
	self->head = NULL;
}

/**
 * Reverse the order of elements in a li st
 * and return reversed list
 */
List reverse_list(List *self) {
	List reverse = new_list();
	ListNodePtr current = self->head;

	while (current != NULL) {
		insert_at_front(&reverse, current->data);
		current = current->next;
	}

	return reverse;
}

/**
 * Merge two ordered lists into a single ordered list
 * This fuctions was acknowledge from 
 * "geekforgeeks.org/merge-two-sorted-linked-list/"
 */

List merge(List* list_a, List* list_b) {
	List merged = new_list(); // the node hold the list result 
	ListNodePtr tail = NULL; // tail points to the last result node
	ListNodePtr curr_a = list_a->head; 
	ListNodePtr curr_b = list_b->head;

	// result of the merged list is list_b if list_a is an empty
	if (curr_a == NULL) { 
		merged.head = curr_b; 
		return merged;
	}

	// result of the merged list is list_a if list_b is an empty
	if (curr_b == NULL) { 
		merged.head = curr_a;
		return merged;
	}

	// if list_a and list_b are not empty let start with first node
	if (curr_a->data <= curr_b->data) { 
		merged.head = curr_a;
		tail = curr_a;
		curr_a = curr_a->next;
	}
	else {
		merged.head = curr_b;
		tail = curr_b;
		curr_b = curr_b->next;
	}

	while (curr_a != NULL && curr_b != NULL) {
		if (curr_a->data <= curr_b->data) {
			tail->next = curr_a;
			tail = curr_a;
			curr_a = curr_a->next;
		}
		else {
			tail->next = curr_b;
			tail = curr_b;
			curr_b = curr_b->next;
		}
	}

	if (curr_a == NULL) {
		tail->next = curr_b;
	}
	else {
		tail->next = curr_a;
	}
	return merged;
}

