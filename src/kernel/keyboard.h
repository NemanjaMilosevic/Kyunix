#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "process.h"
#include "stdint.h"
#include "vnode.h"
char input_buffer[256];
char lastC;
uint32_t kbd_init(void);
void addQueue(ps_t *pid);
static int kbd_read(vnode_t *n, void *buf, size_t count);
int kbd_get_vnode(vnode_t *out);

#endif /* KEYBOARD_H */
