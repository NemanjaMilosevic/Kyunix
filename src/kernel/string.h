#ifndef STRING_H
#define STRING_H

#include "stddef.h"
//shell's helper functions 
void *rawmemchar(const void *s, int c_in);

char *strtok(char *s, const char *delim);
size_t strspn(const char *s, const char *accept);
char *strpbrk (const char *s, const char *accept);

char *strncpy(char *dest, const char *src, size_t n);
int strcmp(const char *p1, const char *p2);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest,const char *src);
void *memset(void *s, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
size_t strlen(const char *s);
size_t strcspn(const char *s, const char *reject);
char *strchr(const char *s, int c);

#endif /* STRING_H */
