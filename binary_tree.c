#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "binary_tree.h"


Node* create_node (int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(!new_node)
    {
        perror("Out of memory!!! (create_node)\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


Node* insert_node (Node* root, comparer compare, int data) {
	if(root == NULL)
	{
	    root = create_node(data);
	}
	else
	{
	    int is_left  = 0;
	    int r        = 0;
	    Node* cursor = root;
	    Node* prev   = NULL;

	    while(cursor)
	    {
	        r = compare(data,cursor->data);
	        prev = cursor;
	        if(r < 0)
	        {
	            is_left = 1;
	            cursor = cursor->left;
	        }
	        else if(r > 0)
	        {
	            is_left = 0;
	            cursor = cursor->right;
	        }
	    }

	    if(is_left)
	        prev->left = create_node(data);
	    else
	        prev->right = create_node(data);
	}
	return root;
}




void dispose (Node* root) {
    if(root != NULL)
    {
        dispose(root->left);
        dispose(root->right);
        free(root);
    }
}


void traverse (FILE* stream, Node* root, callback cb) {
	if (!root) return;
	Node* tmp = root;

	traverse(stream, tmp->left, cb);
	cb(stream, tmp);
	traverse(stream, tmp->right, cb);
}


int compare (int left, int right) {
    if (left >= right)
        return 1;
    else if (left < right)
   		return -1;
   	return 0;
}


void display (Node* nd) {
    if(nd != NULL)
        printf("%d ", nd->data);
}


/*void display_tree(Node* nd) {
    if (nd == NULL)
        return;
    printf("%d",nd->data);
    if(nd->left != NULL)
        printf("(L:%d)", nd->left->data);
    if(nd->right != NULL)
        printf("(R:%d)", nd->right->data);
    printf("\n");
 
    display_tree(nd->left);
    display_tree(nd->right);
}*/


void display_tree(Node* root) {
	Stack *st = cteate_stack();
	while (st->size != 0 || root != NULL) {
		if (root != NULL) {

			printf("%d",root->data);
			if(root->left)
				printf("(L:%d)", root->left->data);
			if(root->right)
				printf("(R:%d)", root->right->data);
			printf("\n");

			if (root->right) {
				push(st, root->right);
			}
			root = root->left;
		}
		else {
			root = pop(st);
		}
	}
	free_stack(&st);
}

