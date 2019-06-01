#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "binary_tree.h"


void fskipchars(FILE* input);
void fprint_node(FILE* output, Node* root);


int main(int argc, char** argv) {
	if (argc < 3) 
	{
		perror("Недостаточно аргументов командной строки ");
		return 0;
	}

	char* file_name_in = argv[1];
	FILE* input = fopen(file_name_in, "r");
	  	if (!input) 
  	{ 
  		perror(file_name_in);
		return 0;
	}

	char* file_name_out = argv[2];
	FILE* output = fopen(file_name_out, "w");
	if (!output) 
  	{ 
  		perror(file_name_out);
		return 0;
	}

	int num = 0;
	void* root = NULL;
	comparer int_comp = compare;
    callback fout = fprint_node;

    while (fscanf(input, "%d", &num) != EOF)
 	{
 		//fskipchars(input);
		root = insert_node(root, int_comp, num);
    }

 	display_tree(root);
    traverse(output, root, fout);
	fclose(input);
	dispose(root);
	fclose(output);

  	return 0;
}


void fskipchars(FILE* input) {
    char c;   
    while((c = fgetc(input)) != EOF)
        if(!ispunct(c) && !isspace(c)) break;
    if(c != EOF) ungetc(c, input);
} 


void fprint_node(FILE* output, Node* nd) {
	if(nd != NULL)
        fprintf(output, "%d ", nd->data);
}