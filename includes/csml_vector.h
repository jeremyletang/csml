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

#ifndef CSML_VECTOR_H
#define CSML_VECTOR_H

#include <stdio.h>

#define impl_vector(type_name, T)\
\
typedef struct vector_##type_name##_t {\
    T               *(*front)(struct vector_##type_name##_t *self);\
    T               *(*back)(struct vector_##type_name##_t *self);\
    T               *(*at)(struct vector_##type_name##_t *self);\
    bool            (*push_back)(struct vector_##type_name##_t *self, T item);\
    void            (*pop_back)(struct vector_##type_name##_t *self);\
    bool            (*is_empty)(struct vector_##type_name##_t *self);\
    unsigned int    (*len)(struct vector_##type_name##_t *self);\
    unsigned int    (*capacity)(struct vector_##type_name##_t *self);\
    void            (*resize)(struct vector_##type_name##_t *self);\
    void            (*clear)(struct vector_##type_name##_t *self);\
    bool            (*free)(struct vector_##type_name##_t *self);\
    T               *stored_data;\
    int             size;\
    int             cap;\
} vector_##type_name##_t;\
\
void            vector_##type_name##_t_initialize(struct vector_##type_name##_t *self, bool type);\
bool            vector_##type_name##_t_delete_heap(struct vector_##type_name##_t *self);\
bool            vector_##type_name##_t_delete_stacked(struct vector_##type_name##_t *self);\
void            vector_##type_name##_t_delete_in(struct vector_##type_name##_t *self);\
\
T               *vector_##type_name##_t_front(struct vector_##type_name##_t *self);\
T               *vector_##type_name##_t_back(struct vector_##type_name##_t *self);\
T               *vector_##type_name##_t_at(struct vector_##type_name##_t *self);\
void            vector_##type_name##_t_push_back(struct vector_##type_name##_t *self, T item);\
void            vector_##type_name##_t_pop_back(struct vector_##type_name##_t *self);\
bool            vector_##type_name##_t_is_empty(struct vector_##type_name##_t *self);\
unsigned int    vector_##type_name##_t_len(struct vector_##type_name##_t *self);\
unsigned int    vector_##type_name##_t_capacity(struct vector_##type_name##_t *self);\
void            vector_##type_name##_t_resize(struct vector_##type_name##_t *self);\
void            vector_##type_name##_t_clear(struct vector_##type_name##_t *self);\
\
vector_##type_name##_t *new_vector_##type_name##_t(unsigned int capacity) {\
    vector_##type_name##_t *self = malloc(sizeof(vector_##type_name##_t));\
    if (self) {\
        self->stored_data = malloc(sizeof(T) * (capacity+ 1 ));\
        if (self->stored_data) {\
            self->cap = capacity;\
            self->size = 0;\
            \
        } else {\
            free(self);\
            self = 0;\
        }\
    }\
    return self;\
}

#define Vector(type_name) vector_##type_name##_t

#endif // CSML_VECTOR_H
