/*
* The MIT License (MIT)
* 
* Copyright (c) 2014 Jeremy Letang (letang.jeremy@gmail.com)
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy of
* this software and associated documentation files (the "Software"), to deal in
* the Software without restriction, including without limitation the rights to
* use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
* the Software, and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
* FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
* IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef CSML_VECTOR_H
#define CSML_VECTOR_H

#include <stdbool.h>    /* c99 bool */
#include <stdlib.h>     /* malloc, free */
#include <string.h>     /* memcpy */
#include "memory.h"

#define vector_t(type_name) vector_##type_name##_t

#define impl_vector(type_name, T)\
\
typedef struct vector_t(type_name) {\
    T               *(*front)(struct vector_t(type_name) *self);\
    T               *(*back)(struct vector_t(type_name) *self);\
    T               *(*at)(struct vector_t(type_name) *self, unsigned int index);\
    bool            (*push_back)(struct vector_t(type_name) *self, T item);\
    void            (*pop_back)(struct vector_t(type_name) *self);\
    bool            (*is_empty)(struct vector_t(type_name) *self);\
    unsigned int    (*len)(struct vector_t(type_name) *self);\
    unsigned int    (*capacity)(struct vector_t(type_name) *self);\
    bool            (*resize)(struct vector_t(type_name) *self, unsigned int new_capacity);\
    void            (*clear)(struct vector_t(type_name) *self);\
    void            (*for_each)(struct vector_t(type_name) *self, \
        void (*func)(T *item, void *data), void *data);\
    bool            (*free)(struct vector_t(type_name) *self);\
    \
    T               *stored_data;\
    unsigned int    size;\
    unsigned int    cap;\
} vector_t(type_name);\
\
bool            vector_##type_name##_t_initialize(struct vector_t(type_name) *self, \
    unsigned int capacity, bool type);\
bool            vector_##type_name##_t_delete_heap(struct vector_t(type_name) *self);\
bool            vector_##type_name##_t_delete_stacked(struct vector_t(type_name) *self);\
void            vector_##type_name##_t_delete_in(struct vector_t(type_name) *self);\
\
T               *vector_##type_name##_t_front(struct vector_t(type_name) *self);\
T               *vector_##type_name##_t_back(struct vector_t(type_name) *self);\
T               *vector_##type_name##_t_at(struct vector_t(type_name) *self, unsigned int index);\
bool            vector_##type_name##_t_push_back(struct vector_t(type_name) *self, T item);\
void            vector_##type_name##_t_pop_back(struct vector_t(type_name) *self);\
bool            vector_##type_name##_t_is_empty(struct vector_t(type_name) *self);\
unsigned int    vector_##type_name##_t_len(struct vector_t(type_name) *self);\
unsigned int    vector_##type_name##_t_capacity(struct vector_t(type_name) *self);\
bool            vector_##type_name##_t_resize(struct vector_t(type_name) *self, \
    unsigned int new_capacity);\
void            vector_##type_name##_t_clear(struct vector_t(type_name) *self);\
void            vector_##type_name##_t_for_each(struct vector_t(type_name) *self, \
    void (*func)(T *item, void *data), void *data);\
\
vector_t(type_name) *new_vector_##type_name##_t(unsigned int capacity) {\
    vector_t(type_name) *self = malloc(sizeof(vector_t(type_name)));\
    if (self) {\
        if (!vector_##type_name##_t_initialize(self, capacity, true)) {\
            free(self);\
            self = 0;\
        }\
    }\
    return self;\
}\
\
vector_t(type_name) stacked_vector_##type_name##_t(unsigned int capacity) {\
    vector_t(type_name) self;\
    vector_##type_name##_t_initialize(&self, capacity, false);\
    return self;\
}\
\
bool            vector_##type_name##_t_initialize(struct vector_t(type_name) *self, \
    unsigned int capacity, bool type) {\
    bool return_value = false;\
    self->stored_data = malloc(sizeof(T) * (capacity + 1 ));\
    if (self->stored_data) {\
        self->cap = capacity;\
        self->size = 0;\
        self->front = vector_##type_name##_t_front;\
        self->back = vector_##type_name##_t_back;\
        self->at = vector_##type_name##_t_at;\
        self->push_back = vector_##type_name##_t_push_back;\
        self->pop_back = vector_##type_name##_t_pop_back;\
        self->is_empty = vector_##type_name##_t_is_empty;\
        self->len = vector_##type_name##_t_len;\
        self->capacity = vector_##type_name##_t_capacity;\
        self->resize = vector_##type_name##_t_resize;\
        self->clear = vector_##type_name##_t_clear;\
        self->for_each = vector_##type_name##_t_for_each;\
        if (type) {\
            self->free = vector_##type_name##_t_delete_heap;\
        } else {\
            self->free = vector_##type_name##_t_delete_stacked;\
        }\
        return_value = true;\
    }\
    return return_value;\
}\
\
bool            vector_##type_name##_t_delete_heap(struct vector_t(type_name) *self) {\
    vector_##type_name##_t_delete_in(self);\
    return true;\
}\
\
bool            vector_##type_name##_t_delete_stacked(struct vector_t(type_name) *self) {\
    vector_##type_name##_t_delete_in(self);\
    return false;\
}\
\
void            vector_##type_name##_t_delete_in(struct vector_t(type_name) *self) {\
    if (self->stored_data) {\
        free(self->stored_data);\
    }\
}\
\
T               *vector_##type_name##_t_front(struct vector_t(type_name) *self) {\
    return &self->stored_data[0];\
}\
\
T               *vector_##type_name##_t_back(struct vector_t(type_name) *self) {\
    return &self->stored_data[self->size - 1];\
}\
\
T               *vector_##type_name##_t_at(struct vector_t(type_name) *self, unsigned int index) {\
    T *return_value = 0;\
    if (index < self->size) {\
        return_value = &self->stored_data[index];\
    }\
    return return_value;\
}\
\
bool            vector_##type_name##_t_push_back(struct vector_t(type_name) *self, T item) {\
    bool return_value = true;\
    if (self->size == self->cap) {\
        return_value = vector_##type_name##_t_resize(self, self->cap * 2);\
    }\
    if (return_value) {\
        self->stored_data[self->size] = item;\
        self->size += 1;\
    }\
    return return_value;\
}\
\
void            vector_##type_name##_t_pop_back(struct vector_t(type_name) *self) {\
    if (self->size > 0) {\
        self->size -= 1;\
    }\
}\
\
bool            vector_##type_name##_t_is_empty(struct vector_t(type_name) *self) {\
   return self->size == 0;\
}\
\
unsigned int    vector_##type_name##_t_len(struct vector_t(type_name) *self) {\
    return self->size;\
}\
\
unsigned int    vector_##type_name##_t_capacity(struct vector_t(type_name) *self) {\
    return self->cap;\
}\
\
bool            vector_##type_name##_t_resize(struct vector_t(type_name) *self, \
    unsigned int new_capacity) {\
    T *tmp_data =       self->stored_data;\
    bool return_value = false;\
    if (new_capacity > self->cap) {\
        self->stored_data = malloc(sizeof(T) * (new_capacity));\
        if (self->stored_data) {\
            memcpy(self->stored_data, tmp_data, sizeof(T) * self->cap);\
            self->cap = new_capacity;\
            free(tmp_data);\
            return_value = true;\
        }\
    }\
    return return_value;\
}\
\
void            vector_##type_name##_t_clear(struct vector_t(type_name) *self) {\
    self->size = 0;\
}\
\
void            vector_##type_name##_t_for_each(struct vector_t(type_name) *self, \
    void (*func)(T *item, void *data), void *data) {\
    unsigned int iter = 0;\
    while (iter <= self->size) {\
        func(&self->stored_data[iter], data);\
        iter += 1;\
    }\
}

#endif /* CSML_VECTOR_H */
