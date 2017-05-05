#ifndef KMALLOC_H
#define KMALLOC_H

#include "stddef.h"
#include "stdint.h"

void kmalloc_init(uint32_t addr);
void *kmalloc(size_t);
void kfree(void *);

//Experimental emberssaing stuff
void *krealloc(void *ptr,size_t size);
size_t getsize(void * p);
#endif /* KMALLOC_H */
