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
#include <csml.h>

#define impl_map(key_type, Key_T, value_type, T)\
\
impl_pair(inner_map_##key_type, Key_T, inner_map_##value_type, T);\
\
struct item_map_##key_type##_##value_type##_t {\
    Pair(inner_map_##key_type, inner_map_##value_type)  item;\
    struct item_map_##key_type##_##value_type##_t       *next;\
} item_map_##key_type##_##value_type##_t;\
\
typedef struct map_##key_type##_##value_type##_t {\
    T               *(*at)(struct map_##key_type##_##value_type##_t *self, Key_T key);\
    bool            (*insert)(struct map_##key_type##_##value_type##_t *self, Key_T key, T value);\
    bool            (*remove)(struct map_##key_type##_##value_type##_t *self, Key_T key);\
    bool            (*is_empty)(struct map_##key_type##_##value_type##_t *self);\
    unsigned int    (*len)(struct map_##key_type##_##value_type##_t *self);\
    bool            (*free)(struct map_##key_type##_##value_type##_t *self);\
    void            (*clear)(struct map_##key_type##_##value_type##_t *self);\
    \
    struct item_map_##key_type##_##value_type##_t       *first_item;\
    int                                                 size;\
    bool (*cmp_key_func)(Key_T k1, Key_T k2);\
} map_##key_type##_##value_type##_t;\
\
void            map_##key_type##_##value_type##_t_initialize(struct map_##key_type##_##value_type##_t *self, bool type);\
bool            map_##key_type##_##value_type##_t_delete_heap(struct map_##key_type##_##value_type##_t *self);\
bool            map_##key_type##_##value_type##_t_delete_stacked(struct map_##key_type##_##value_type##_t *self);\
void            map_##key_type##_##value_type##_t_delete_in(struct map_##key_type##_##value_type##_t *self);\
\
T               *map_##key_type##_##value_type##_t_at(struct map_##key_type##_##value_type##_t *self, Key_T key);\
bool            map_##key_type##_##value_type##_t_insert(struct map_##key_type##_##value_type##_t *self, Key_T key, T value);\
bool            map_##key_type##_##value_type##_t_remove(struct map_##key_type##_##value_type##_t *self, Key_T key);\
bool            map_##key_type##_##value_type##_t_is_empty(struct map_##key_type##_##value_type##_t *self);\
unsigned int    map_##key_type##_##value_type##_t_len(struct map_##key_type##_##value_type##_t *self);\
void            map_##key_type##_##value_type##_t_clear(struct map_##key_type##_##value_type##_t *self);\
\
map_##key_type##_##value_type##_t *new_map_##key_type##_##value_type##_t(bool (*cmp_func)(Key_T k1, Key_T k2)) {\
    map_##key_type##_##value_type##_t *self = malloc(sizeof(map_##key_type##_##value_type##_t));\
    if (self) {\
        map_##key_type##_##value_type##_t_initialize(self, true);\
        self->cmp_key_func = cmp_func;\
    }\
    return self;\
}\
\
map_##key_type##_##value_type##_t stacked_map_##key_type##_##value_type##_t(bool (*cmp_func)(Key_T k1, Key_T k2)) {\
    map_##key_type##_##value_type##_t self;\
    map_##key_type##_##value_type##_t_initialize(&self, false);\
    self.cmp_key_func = cmp_func;\
    return self;\
}\
\
void map_##key_type##_##value_type##_t_initialize(struct map_##key_type##_##value_type##_t *self, bool type) {\
    self->size = 0;\
    self->first_item = 0;\
    self->at = map_##key_type##_##value_type##_t_at;\
    self->insert = map_##key_type##_##value_type##_t_insert;\
    self->remove = map_##key_type##_##value_type##_t_remove;\
    self->len = map_##key_type##_##value_type##_t_len;\
    self->is_empty = map_##key_type##_##value_type##_t_is_empty;\
    if (type) {\
        self->free = map_##key_type##_##value_type##_t_delete_heap;\
    } else {\
        self->free = map_##key_type##_##value_type##_t_delete_stacked;\
    }\
}\
\
bool            map_##key_type##_##value_type##_t_delete_heap(struct map_##key_type##_##value_type##_t *self) {\
    map_##key_type##_##value_type##_t_delete_in(self);\
    return true;\
}\
\
bool            map_##key_type##_##value_type##_t_delete_stacked(struct map_##key_type##_##value_type##_t *self) {\
    map_##key_type##_##value_type##_t_delete_in(self);\
    return false;\
}\
\
void            map_##key_type##_##value_type##_t_delete_in(struct map_##key_type##_##value_type##_t *self) {\
    struct item_map_##key_type##_##value_type##_t *tmp;\
    while (self->first_item) {\
        tmp = self->first_item->next;\
        free(self->first_item);\
        self->first_item = tmp;\
    }\
}\
\
T               *map_##key_type##_##value_type##_t_at(struct map_##key_type##_##value_type##_t *self, Key_T key) {\
    T *return_value = 0;\
    struct item_map_##key_type##_##value_type##_t *tmp = self->first_item;\
    while (tmp && !return_value) {\
        if (self->cmp_key_func(tmp->item.first, key)) {\
            return_value = &tmp->item.second;\
        } else {\
            tmp = tmp->next;\
        }\
    }\
    return return_value;\
}\
bool            map_##key_type##_##value_type##_t_insert(struct map_##key_type##_##value_type##_t *self, Key_T key, T value) {\
    bool found_key = false;\
    struct item_map_##key_type##_##value_type##_t *tmp = self->first_item;\
    while (tmp && !found_key) {\
        if (self->cmp_key_func(tmp->item.first, key)) {\
            found_key = true;\
        } else {\
            tmp = tmp->next;\
        }\
    }\
    if (!found_key) {\
        tmp = malloc(sizeof(item_map_##key_type##_##value_type##_t));\
        if (!tmp) {\
            return 0;\
        }\
        tmp->next = self->first_item;\
        tmp->item = stacked(Pair(inner_map_##key_type, inner_map_##value_type), key, value);\
        self->first_item = tmp;\
        self->size += 1;\
    }\
    return !found_key ? true : false;\
}\
\
bool            map_##key_type##_##value_type##_t_remove(struct map_##key_type##_##value_type##_t *self, Key_T key) {\
    bool found_key = false;\
    struct item_map_##key_type##_##value_type##_t *first = self->first_item;\
    if (self->size == 0) {\
        found_key = false;\
    } else if (self->cmp_key_func(self->first_item->item.first, key)) {\
        self->first_item = self->first_item->next;\
        free(first);\
        found_key = true;\
    } else {\
        struct item_map_##key_type##_##value_type##_t *second = self->first_item->next;\
        while (second && !found_key) {\
            if (self->cmp_key_func(second->item.first, key)) {\
                found_key = true;\
            } else {\
                first = second;\
                second = first->next;\
            }\
        }\
        if (found_key) {\
            first->next = second->next;\
            free(second);\
        }\
    }\
    return found_key;\
}\
\
bool            map_##key_type##_##value_type##_t_is_empty(struct map_##key_type##_##value_type##_t *self) {\
    return self->size == 0;\
}\
\
unsigned int    map_##key_type##_##value_type##_t_len(struct map_##key_type##_##value_type##_t *self) {\
    return self->size;\
}\
\
void            map_##key_type##_##value_type##_t_clear(struct map_##key_type##_##value_type##_t *self) {\
    map_##key_type##_##value_type##_t_delete_in(self);\
    self->first_item = 0;\
}\

#define Map(key_type, value_type) map_##key_type##_##value_type##_t

#endif // CSML_MAP_H

