#include <stddef.h>


typedef struct _Node {
    int data;
    struct _Node* left;
    struct _Node* right;  
} Node;

typedef int (*comparer)(int, int);
typedef void (*callback)(FILE*, Node*);


Node* create_node (int data);
Node* insert_node (Node* root, comparer compare, int data);
void dispose (Node* root);
void traverse (FILE* stream, Node* root, callback cb);
int compare (int left, int right);
void display (Node* nd);
void display_tree(Node* nd);
