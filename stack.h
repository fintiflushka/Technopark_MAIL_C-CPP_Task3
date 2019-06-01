#include <stddef.h>


#define STACK_INIT_SIZE 30


typedef struct Stack {
	size_t size;
	size_t limit;
	void **data;
} Stack;


Stack* cteate_stack();
void free_stack(Stack** s);
void push(Stack* s, void *item);
void* pop(Stack* s);
void* peek(Stack *s);