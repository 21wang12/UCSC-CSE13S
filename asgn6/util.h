#ifndef __UTIL_H__
#define __UTIL_H__

#include "node.h"
#include "code.h"
#include "defines.h"

void post_order_traverse(Node *root,Code *c,Code table[static ALPHABET]);

void write_tree(int outfile, Node *root);

void help_encode(void);

void help_decode(void);
#endif
