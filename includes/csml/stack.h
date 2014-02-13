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

#ifndef CSML_STACK_H
#define CSML_STACK_H

#include <stdbool.h>    /* c99 bool */
#include <stdlib.h>     /* malloc, free */
#include "memory.h"

#define stack(type_name) stack_##type_name##_t

#define impl_stack(type_name, T)\
\
struct item_stack_##type_name##_t {\
    T                                   item;\
    struct item_stack_##type_name##_t   *next;\
} item_stack_##type_name##_t;\
\
typedef struct stack(type_name) {\
    T               *(*top)(struct stack(type_name) *self);\
    void            (*pop)(struct stack(type_name) *self);\
    bool            (*push)(struct stack(type_name) *self, T item);\
    bool            (*is_empty)(struct stack(type_name) *self);\
    unsigned int    (*len)(struct stack(type_name) *self);\
    bool            (*free)(struct stack(type_name) *self);\
    \
    struct item_stack_##type_name##_t   *top_item;\
    int                                 size;\
} stack(type_name);\
\
void            stack_##type_name##_t_initialize(struct stack(type_name) *self, bool type);\
bool            stack_##type_name##_t_delete_heap(struct stack(type_name) *self);\
bool            stack_##type_name##_t_delete_stacked(struct stack(type_name) *self);\
void            stack_##type_name##_t_delete_in(struct stack(type_name) *self);\
\
T               *stack_##type_name##_t_top(struct stack(type_name) *self);\
void            stack_##type_name##_t_pop(struct stack(type_name) *self);\
bool            stack_##type_name##_t_push(struct stack(type_name) *self, T item);\
bool            stack_##type_name##_t_is_empty(struct stack(type_name) *self);\
unsigned int    stack_##type_name##_t_len(struct stack(type_name) *self);\
\
stack(type_name) *new_stack_##type_name##_t() {\
    stack_##type_name##_t *self = malloc(sizeof(stack(type_name)));\
    if (self) {\
        stack_##type_name##_t_initialize(self, true);\
    }\
    return self;\
}\
\
stack(type_name) stacked_stack_##type_name##_t() {\
    stack_##type_name##_t self;\
    stack_##type_name##_t_initialize(&self, false);\
    return self;\
}\
\
void stack_##type_name##_t_initialize(struct stack(type_name) *self, bool type) {\
    self->size = 0;\
    self->top_item = 0;\
    self->len = stack_##type_name##_t_len;\
    self->push = stack_##type_name##_t_push;\
    self->top = stack_##type_name##_t_top;\
    self->is_empty = stack_##type_name##_t_is_empty;\
    self->pop = stack_##type_name##_t_pop;\
    if (type) {\
        self->free = stack_##type_name##_t_delete_heap;\
    } else {\
        self->free = stack_##type_name##_t_delete_stacked;\
    }\
}\
\
void stack_##type_name##_t_delete_in(struct stack(type_name) *self) {\
    struct item_stack_##type_name##_t *tmp;\
    while (self->top_item) {\
        tmp = self->top_item->next;\
        free(self->top_item);\
        self->top_item = tmp;\
    }\
}\
\
bool stack_##type_name##_t_delete_heap(struct stack(type_name) *self) {\
    stack_##type_name##_t_delete_in(self);\
    return true;\
}\
\
bool stack_##type_name##_t_delete_stacked(struct stack(type_name) *self) {\
    stack_##type_name##_t_delete_in(self);\
    return false;\
}\
\
bool stack_##type_name##_t_push(struct stack(type_name) *self, T item) {\
    bool return_value = false;\
    struct item_stack_##type_name##_t *tmp = malloc(sizeof(item_stack_##type_name##_t));\
    if (tmp) {\
        tmp->item = item;\
        tmp->next = self->top_item;\
        self->top_item = tmp;\
        self->size += 1;\
        return_value = true;\
    }\
    return return_value;\
}\
\
T *stack_##type_name##_t_top(struct stack(type_name) *self) {\
    return &self->top_item->item;\
}\
\
void stack_##type_name##_t_pop(struct stack(type_name) *self) {\
    if (self->top_item) {\
        struct item_stack_##type_name##_t *tmp = self->top_item;\
        self->top_item = self->top_item->next;\
        free(tmp);\
        self->size -= 1;\
    }\
}\
\
bool stack_##type_name##_t_is_empty(struct stack(type_name) *self) {\
    return self->size == 0;\
}\
\
unsigned int stack_##type_name##_t_len(struct stack(type_name) *self) {\
    return self->size;\
}

#endif /* CSML_STACK_H */
