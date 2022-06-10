#ifndef __$__QUICK_SORT_H
#define __$__QUICK_SORT_H 12345
typedef struct __lbub_
{
int lb,ub;
}LBUB;
void quickSort(void *,int,int,int (*)(void*,void*));
int findPartitionPoint(void *,int,int,int,int (*)(void*,void*));
#endif