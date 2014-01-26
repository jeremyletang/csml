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

#ifndef CSML_PAIR_H
#define CSML_PAIR_H

#include <stdbool.h>    // c99 bool
#include <stdlib.h>     // malloc, free
#include <string.h>     // memcpy

#define impl_pair(type_name1, T1, type_name2, T2)\
\
typedef struct pair_##type_name1##_##type_name2##_t {\
    T1 first_item;\
    T2 second_item;\
    void    (*swap)(struct pair_##type_name1##_##type_name2##_t *self, \
        struct pair_##type_name1##_##type_name2##_t *other);\
    bool    (*free)(struct pair_##type_name1##_##type_name2##_t *self);\
} pair_##type_name1##_##type_name2##_t;\
\
void    pair_##type_name1##_##type_name2##_t_initialize(struct pair_##type_name1##_##type_name2##_t *self, \
    T1 first, T2 second, bool type);\
bool    pair_##type_name1##_##type_name2##_t_delete_heap(struct pair_##type_name1##_##type_name2##_t *self);\
bool    pair_##type_name1##_##type_name2##_t_delete_stacked(struct pair_##type_name1##_##type_name2##_t *self);\
void    pair_##type_name1##_##type_name2##_t_swap(struct pair_##type_name1##_##type_name2##_t *self, \
    struct pair_##type_name1##_##type_name2##_t *other);\
\
pair_##type_name1##_##type_name2##_t *new_pair_##type_name1##_##type_name2##_t(T1 first, T2 second) {\
    pair_##type_name1##_##type_name2##_t *self = malloc(sizeof(pair_##type_name1##_##type_name2##_t));\
    if (self) {\
        pair_##type_name1##_##type_name2##_t_initialize(self, first, second, true);\
    }\
    return self;\
}\
\
pair_##type_name1##_##type_name2##_t stacked_pair_##type_name1##_##type_name2##_t(T1 first, T2 second) {\
    pair_##type_name1##_##type_name2##_t self;\
    pair_##type_name1##_##type_name2##_t_initialize(&self, first, second, false);\
    return self;\
}\
\
void pair_##type_name1##_##type_name2##_t_initialize(struct pair_##type_name1##_##type_name2##_t *self, \
    T1 first, T2 second, bool type) {\
    self->first_item =  first;\
    self->second_item = second;\
    self->swap =        pair_##type_name1##_##type_name2##_t_swap;\
    if (type) {\
        self->free = pair_##type_name1##_##type_name2##_t_delete_heap;\
    } else {\
        self->free = pair_##type_name1##_##type_name2##_t_delete_stacked;\
    }\
}\
\
bool    pair_##type_name1##_##type_name2##_t_delete_heap(struct pair_##type_name1##_##type_name2##_t *self) {\
    return true;\
}\
\
bool    pair_##type_name1##_##type_name2##_t_delete_stacked(struct pair_##type_name1##_##type_name2##_t *self) {\
    return false;\
}\
\
void    pair_##type_name1##_##type_name2##_t_swap(struct pair_##type_name1##_##type_name2##_t *self, \
    struct pair_##type_name1##_##type_name2##_t *other) {\
    T1 tmp_first =          self->first_item;\
    T2 tmp_secomd =         self->second_item;\
    self->first_item =      other->first_item;\
    self->second_item =     other->second_item;\
    other->first_item =     tmp_first;\
    other->second_item =    tmp_secomd;\
}

#define Pair(type_name1, type_name2) pair_##type_name1##_##type_name2##_t

#endif // CSML_PAIR_H
