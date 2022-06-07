#pragma once
/*
* Vinh Nguyen #470821
*/

typedef struct listNode {
	int data;
	struct listNode *next;
} *ListNodePtr;

typedef struct list {
	ListNodePtr head;
} List;

/*
Create a new instance of the list type
*/
List new_list();

/*
Traverse a list and print the data in each node to the screen
*/
void print_list(List *self);

/*
Insert a new element at the front of the list
*/
void insert_at_front(List *self, int data);

/*
Insert a new element in an ordered list
*/
void insert_in_order(List *self, int data);

/*
Delete an item from a list
*/
void delete_list(List *self, int data);

/*
 Delete all items in a list
 */
void destroy_list(List *self);

/*
 Reverse the order of elements in a list
 */
List reverse_list(List *self);

/*
 Merge two ordered lists into a single ordered list
 */

List merge(List* a, List* b);
void delete_max(List *self);

