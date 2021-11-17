#include "kvs.h"


kvs_t* open()
{
	kvs_t* kvs = (kvs_t*)malloc(sizeof(kvs_t));
	kvs->db= (node_t*)malloc(sizeof(node_t)); 
	
	kvs->fp = fopen("student.dat", "r");

	return kvs;
}
