#include "kvs.h"

int main()
{
	kvs_t* kvs = open();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	// KVS created.  
	char key[100]; 
	char* value = (char*) malloc (sizeof(char)* 300);
	char* rvalue;

	strcpy(key, "Jane");
	strcpy(value, "Seoul");

	if(put(kvs, key, value) < 0){
		printf("Failed to put data\n");
		exit(-1);
	}

	for(int i = 0 ; i < 4 ; i++){
		if(!(rvalue = get(kvs, kvs->db->str[i]))){
			printf("Failed to get data\n");
			exit(-1);
		}
		printf("get : %s\n", rvalue);
		free(rvalue);
	}

	return 1;
}
