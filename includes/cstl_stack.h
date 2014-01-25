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

#ifndef CSTL_STACK_H
#define CSTL_STACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define impl_stack(type_name, T)\
\
struct item_stack_##type_name##_t {\
    T                                   item;\
    struct item_stack_##type_name##_t   *next;\
}item_stack_##type_name##_t;\
\
typedef struct stack_##type_name##_t {\
    bool            (*push)(struct stack_##type_name##_t *self, T item);\
    unsigned int    (*len)(struct stack_##type_name##_t *self);\
    struct item_stack_##type_name##_t   *top;\
    int                                 size;\
} stack_##type_name##_t;\
\
bool stack_##type_name##_t_push(struct stack_##type_name##_t *self, T item);\
unsigned int stack_##type_name##_t_len(struct stack_##type_name##_t *self);\
\
stack_##type_name##_t *new_stack_##type_name##_t() {\
    stack_##type_name##_t *self = malloc(sizeof(stack_##type_name##_t));\
    printf("create\n");\
    if (self != 0) {\
        self->size = 0;\
        self->len = stack_##type_name##_t_len;\
        self->push = stack_##type_name##_t_push;\
    }\
    return self;\
}\
\
bool stack_##type_name##_t_push(struct stack_##type_name##_t *self, T item) {\
    bool return_value = false;\
    struct item_stack_##type_name##_t *tmp = malloc(sizeof(item_stack_##type_name##_t));\
    if (tmp != 0) {\
        tmp->item = item;\
        tmp->next = self->top;\
        self->top = tmp;\
        self->size += 1;\
        return_value = true;\
    }\
    return return_value;\
}\
\
\
unsigned int stack_##type_name##_t_len(struct stack_##type_name##_t *self) {\
    return self->size;\
}\
\
stack_##type_name##_t stacked_stack_##type_name##_t() {\
    stack_##type_name##_t tmp;\
    return tmp;\
}

#define Stack(type_name) stack_##type_name##_t

#endif // CSTL_STACK_H