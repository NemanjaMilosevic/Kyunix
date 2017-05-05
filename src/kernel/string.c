#include "string.h"
#include "stdint.h"
#include "stddef.h"
static char *olds;
void *memset(void *s, int c, size_t n)
{
    uint8_t *base = (uint8_t *) s;
    uint8_t *p;
    uint8_t cb = (uint8_t) (c & 0xFF);

    for (p = base; p < base + n; ++p) {
        *p = cb;
    }

    return s;
}

void *memcpy(void *dest, const void *src, size_t n)
{
    uint8_t *to = (uint8_t *) dest;
    uint8_t *from = (uint8_t *) src;
    size_t i;

    for(i = 0; i < n; ++i) {
        *to++ = *from++;
    }

    return dest;
}

int strcmp(const char *s1, const char *s2)
{
    size_t len1 = strlen(s1), len2 = strlen(s2);

    if (len1 < len2) {
        return -1;
    }

    if (len1 > len2) {
        return 1;
    }

    for (; *s1; ++s1, ++s2) {
        if (*s1 == *s2) {
            continue;
        } else if (*s1 < *s2) {
            return -1;
        } else {
            return 1;
        }
    }

    return 0;
}
void *rawmemchar(const void *s, int c_in){
    const unsigned char *char_ptr;   
    unsigned char c;
    unsigned long int longword;
 
    c = (unsigned char) c_in;

    for (char_ptr = (const unsigned char *) s;
       ((unsigned long int) char_ptr & (sizeof (longword) - 1)) != 0;
       ++char_ptr)
    if (*char_ptr == c) return (void*) char_ptr;
    return NULL;

}
static char *olds;

char *strtok(char *s, const char *delim)
{
  char *token;

  if (s == NULL)
    s = olds;

  /* Scan leading delimiters.  */
  s += strspn (s, delim);
  if (*s == '\0')
    {
      olds = s;
      return NULL;
    }

  /* Find the end of the token.  */
  token = s;
  s = strpbrk(token, delim);
  if (s == NULL)
    /* This token finishes the string.  */
    olds = rawmemchar (token, '\0');
  else
    {
      /* Terminate the token and make OLDS point past it.  */
      *s = '\0';
      olds = s + 1;
    }
  return token;
}
size_t strspn(const char *s, const char *accept)
{
  const char *p;
  const char *a;
  size_t count = 0;

  for (p = s; *p != '\0'; ++p)
    {
      for (a = accept; *a != '\0'; ++a)
    if (*p == *a)
      break;
      if (*a == '\0')
    return count;
      else
    ++count;
    }

  return count;
}
char *strpbrk(const char *s, const char *accept)
{
  while (*s != '\0')
    {
      const char *a = accept;
      while (*a != '\0')
    if (*a++ == *s)
      return (char *) s;
      ++s;
    }

  return NULL;
}
char *strncpy(char *dest, const char *src, size_t n){
  
size_t i;
               for ( i = 0; i < n && src[i] != '\0'; i++)
                   dest[i] = src[i];
               for ( ; i < n; i++)
                   dest[i] = '\0';

               return dest;
}
int strcmp2(const char *p1, const char *p2){
  register const unsigned char *s1 = (const unsigned char *) p1;
  register const unsigned char *s2 = (const unsigned char *) p2;
  unsigned char c1, c2;

  do{
      c1 = (unsigned char) *s1++;
      c2 = (unsigned char) *s2++;
      if (c1 == '\0')
	return c1 - c2;
    }
  while (c1 == c2);

  return c1 - c2;
}
char *strcpy(char *dest, const char *src){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
char *strcat(char *dest,const char *src)
{
  char *s1 = dest;
  const char *s2 = src;
  char c;

  /* Find the end of the string.  */
  do
    c = *s1++;
  while (c != '\0');

  /* Make S1 point before the next character, so we can increment
     it while memory is read (wins on pipelined cpus).  */
  s1 -= 2;

  do
    {
      c = *s2++;
      *++s1 = c;
    }
  while (c != '\0');

  return dest;
}
int strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    for (i = 0; i < n; ++i) {
        if (*s1 == *s2) {
            continue;
        }

        if (*s1 == '\0' && *s2 != '\0') {
            return -1;
        }

        if (*s2 == '\0' && *s1 != '\0') {
            return 1;
        }

        if (*s1 < *s2) {
            return -1;
        } else {
            return 1;
        }
    }

    return 0;
}

size_t strlen(const char *s)
{
    size_t len = 0;

    for (; *s; ++s) {
        ++len;
    }

    return len;
}

size_t strcspn(const char *s, const char *reject)
{
    size_t l = 0;

    for (; *s; ++s) {
        if (strchr(reject, (int) *s) != NULL) {
            break;
        }
        ++l;
    }

    return l;
}

char *strchr(const char *s, int c)
{
    for (; *s; ++s) {
        if (*s == (char) c) {
            return (char *) s; /* ugly, but it follows the standard */
        }
    }

    return NULL;
}
