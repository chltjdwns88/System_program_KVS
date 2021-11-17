#include "kvs.h"

int close(kvs_t* kvs)
{
	fclose(kvs->fp);
	return 0;
}
