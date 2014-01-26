// The MIT License (MIT)
// 
// Copyright (c) 2014 Jeremy Letang (letang.jeremy@gmail.com)
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef CSML_MAP_H
#define CSML_MAP_H

#include <stdbool.h>    // c99 bool
#include <stdlib.h>     // malloc, free
#include <string.h>     // memcpy
#include "csml_pair.h"

#define impl_map(key_type, Key_type, value_type, T)\
\
impl_pair(inner_map_##key_type, Key_type, inner_map_##value_type, T);\
\
struct item_map_##key_type##_##value_type##_t {\
    Pair(inner_map_##key_type, inner_map_##value_type) 	item;\
    struct item_stack_##type_name##_t   				*next;\
} item_map_##key_type##_##value_type##_t;\
\
typedef struct map_##key_type##_##value_type##_t {\
	T               *(*at)(struct map_##key_type##_##value_type##_t *self, Key_type key);\
	bool            (*insert)(struct map_##key_type##_##value_type##_t *self, Key_type key, T value);\
    bool		    (*remove)(struct map_##key_type##_##value_type##_t *self, Key_type key);\
	bool            (*is_empty)(struct map_##key_type##_##value_type##_t *self);\
    unsigned int    (*len)(struct map_##key_type##_##value_type##_t *self);\
    \
	struct item_map_##key_type##_##value_type##_t 		*first_item;\
    int             									size;\
} map_##key_type##_##value_type##_t;\
\
void            map_##key_type##_##value_type##_t_initialize(struct map_##key_type##_##value_type##_t *self, bool type);\
bool            map_##key_type##_##value_type##_t_delete_heap(struct map_##key_type##_##value_type##_t *self);\
bool            map_##key_type##_##value_type##_t_delete_stacked(struct map_##key_type##_##value_type##_t *self);\
void            map_##key_type##_##value_type##_t_delete_in(struct map_##key_type##_##value_type##_t *self);\
\
T            	*map_##key_type##_##value_type##_t_at(struct map_##key_type##_##value_type##_t *self, Key_type key);\
bool            map_##key_type##_##value_type##_t_insert(struct map_##key_type##_##value_type##_t *self, Key_type key);\
bool            map_##key_type##_##value_type##_t_remove(struct map_##key_type##_##value_type##_t *self, Key_type key);\
bool            map_##key_type##_##value_type##_t_is_empty(struct map_##key_type##_##value_type##_t *self);\
unsigned int    map_##key_type##_##value_type##_t_len(struct map_##key_type##_##value_type##_t *self);\


#define Map(key_type, value_type) pair_##key_type##_##value_type##_t

#endif // CSML_MAP_H