#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
	char key[100];
	char* value;
	char* string[8];
	struct node* next;
};
typedef struct node node_t;


struct kvs{
	struct node* db; // database
	int items; // number of data 
	FILE* fp;
};
typedef struct kvs kvs_t; 

int main()
{
	kvs_t* kvs = (kvs_t*)malloc(sizeof(kvs_t));
	kvs[0]->items = 4;
	kvs[1]->items = 5;
	
	printf("%d %d \n", kvs[0]->items, kvs[1]->items);
	// char* key[4];
	// key[0] = "stawd";
	// key[1] = "stirng";
	// key[2] = "abc";
	// key[3] = "abcd";
	// for(int i = 0; i < 4; i++){
		
	// }
	
	// char key[100]; 
	// key[0] = 'a';
	// key[1] = 'b';
	// key[2] = 'c';

	// printf("%s\n", key);
}
