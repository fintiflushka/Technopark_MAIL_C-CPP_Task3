#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "stack.h"


Stack* cteate_stack() {
	Stack* tmp = (Stack*)malloc(sizeof(Stack));
	if (!tmp) return NULL;
	tmp->limit = STACK_INIT_SIZE;
	tmp->size = 0;
	tmp->data = (void**)malloc(tmp->limit * sizeof(void*));
	if (!tmp->data) return NULL;
	return tmp;
}


void free_stack(Stack** s) {
	free((*s)->data);
	free(*s);
	*s = NULL;
}


void push(Stack* s, void *item) {
	if (s->size >= s->limit) {
		s->limit *= 2;
		s->data = (void**)realloc(s->data, s->limit * sizeof(void*));
		if (!s->data) return;
	}
	s->data[s->size++] = item;
}


void* pop(Stack* s){
	if (!s->size) {
		exit(1);
	}
	s->size--;
	return s->data[s->size];
}


void* peek(Stack *s) {
	return s->data[s->size-1];
}