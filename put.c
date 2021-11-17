#include "kvs.h"

int put(kvs_t* kvs, const char* key, const char* value)
{
	int index = 0;
	
	while(!feof(kvs->fp)){
		char* retval = fgets(kvs->db->key[index], sizeof(kvs->db->key[index]), kvs->fp);
		if(retval == NULL){
			perror("fgets : ");
		}
		kvs->db->key[index][strlen(kvs->db->key[index]) - 1] = 0;
		char *ptr = strtok(kvs->db->key[index], " ");
		kvs->db->str[index] = ptr;

		printf("put : %s", kvs->db->str[index]);
		while(ptr != NULL){
			ptr = strtok(NULL, " ");
			if(ptr != NULL){
				strcpy(kvs->db->value[index], ptr);
				kvs->db->value[index][strlen(kvs->db->value[index])] = 0;
				printf(", %s\n", ptr);
			}	
		}
		index++;
	}

	printf("\n");
	return 0;
}
