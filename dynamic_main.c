#include "kvs.h"
#include <dlfcn.h>

int main()
{
	void* handle;
	char* error;
	
	handle = dlopen("./libkvs.so", RTLD_LAZY);
	if(!handle){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	kvs_t* (*open)();
	open = dlsym(handle, "open");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	kvs_t* kvs = open();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	int (*put)(kvs_t*, const char*, const char*);
	char* (*get)(kvs_t*, const char*);

	put = dlsym(handle, "put");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	get = dlsym(handle, "get");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
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

	if(dlclose(handle) < 0){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	return 1;
}
