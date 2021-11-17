#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
	char* retval = (char*)malloc(sizeof(char) * 100);
	for(int i = 0 ; i < 4 ; i++){
		if(!strcmp(kvs->db->str[i], key)){
			strcpy(retval, kvs->db->str[i]);
			strcat(retval, ", ");
			strcat(retval, kvs->db->value[i]);
			return retval;
		}
	}
	free(retval);
	return NULL;
}
