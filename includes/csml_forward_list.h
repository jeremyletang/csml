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

#ifndef CSML_FORWARD_LIST_H
#define CSML_FORWARD_LIST_H

#define forward_list(type_name) forward_list_##type_name##_t
#define flist_iterator(type_name) forward_list_iterator_##type_name##_t

#define impl_flist(type_name, T)\
\
typedef struct flist_iterator(type_name) {\
    T                                   item;\
    struct flist_iterator(type_name)    *next;\
}flist_iterator(type_name);\
\
typedef struct forward_list(type_name) {\
    T                           *(*front)(struct forward_list(type_name) *self);\
    void                        (*push_front)(struct forward_list(type_name) *self, T new_item);\
    void                        (*pop_front)(struct forward_list(type_name) *self);\
    struct flist_iterator(type_name)    *(*begin)(struct forward_list(type_name) *self);\
    struct flist_iterator(type_name)    *(*end)(struct forward_list(type_name) *self);\
    bool                        (*is_empty)(struct forward_list(type_name) *self);\
    struct flist_iterator(type_name)    *(*insert_after)(struct forward_list(type_name) *self, struct flist_iterator(type_name) *it, T new_item);\
    struct flist_iterator(type_name)    *(*erase_after)(struct forward_list(type_name) *self, struct flist_iterator(type_name) *it);\
    struct flist_iterator(type_name)    *(*erase_in)(struct forward_list(type_name) *self, struct flist_iterator(type_name) *begin, \
        struct flist_iterator(type_name) *end);\
    void                        (*remove)(struct forward_list(type_name) *self, T rm_item);\
    void                        (*remove_if)(struct forward_list(type_name) *self, bool (*predicate)(T *item));\
    bool                        (*free)(struct forward_list(type_name) *self);\
    unsigned int                (*len)(struct forward_list(type_name) *self);\
    \
    struct flist_iterator(type_name)    *first;\
    struct flist_iterator(type_name)    *last;\
    unsigned int                        size;\
} forward_list(type_name);\
\
void            forward_list_##type_name##_t_initialize(struct forward_list(type_name) *self, bool type);\
bool            forward_list_##type_name##_t_delete_heap(struct forward_list(type_name) *self);\
bool            forward_list_##type_name##_t_delete_stacked(struct forward_list(type_name) *self);\
void            forward_list_##type_name##_t_delete_in(struct forward_list(type_name) *self);\
\
T                           *forward_list_##type_name##_t_front(struct forward_list(type_name) *self);\
void                        forward_list_##type_name##_t_push_front(struct forward_list(type_name) *self, T new_item);\
void                        forward_list_##type_name##_t_pop_front(struct forward_list(type_name) *self);\
struct flist_iterator(type_name)    *forward_list_##type_name##_t_begin(struct forward_list(type_name) *self);\
struct flist_iterator(type_name)    *forward_list_##type_name##_t_end(struct forward_list(type_name) *self);\
bool                        forward_list_##type_name##_t_is_empty(struct forward_list(type_name) *self);\
struct flist_iterator(type_name)    *forward_list_##type_name##_t_insert_after(struct forward_list(type_name) *self, \
    struct flist_iterator(type_name) *it, T new_item);\
struct flist_iterator(type_name)    *forward_list_##type_name##_t_erase_after(struct forward_list(type_name) *self, \
    struct flist_iterator(type_name) *it);\
struct flist_iterator(type_name)    *forward_list_##type_name##_t_erase_in(struct forward_list(type_name) *self, \
    struct flist_iterator(type_name) *it1, flist_iterator(type_name) *it2);\
void                        forward_list_##type_name##_t_remove(struct forward_list(type_name) *self, T rm_item);\
void                        forward_list_##type_name##_t_remove_if(struct forward_list(type_name) *self, bool (*predicate)(T *item));\
unsigned int                forward_list_##type_name##_t_len(struct forward_list(type_name) *self);\
\
forward_list(type_name) *new_forward_list_##type_name##_t() {\
    forward_list(type_name) *self = malloc(sizeof(forward_list(type_name)));\
    if (self) {\
        forward_list_##type_name##_t_initialize(self, true);\
    }\
    return self;\
}\
\
forward_list(type_name) stacked_forward_list_##type_name##_t() {\
    forward_list(type_name) self;\
    forward_list_##type_name##_t_initialize(&self, false);\
    return self;\
}\
\
void forward_list_##type_name##_t_initialize(struct forward_list(type_name) *self, bool type) {\
    self->size = 0;\
    self->first = 0;\
    self->last = 0;\
    self->front = forward_list_##type_name##_t_front;\
    self->push_front = forward_list_##type_name##_t_push_front;\
    self->pop_front = forward_list_##type_name##_t_pop_front;\
    self->begin = forward_list_##type_name##_t_begin;\
    self->end = forward_list_##type_name##_t_end;\
    self->is_empty = forward_list_##type_name##_t_is_empty;\
    self->insert_after = forward_list_##type_name##_t_insert_after;\
    self->erase_after = forward_list_##type_name##_t_erase_after;\
    self->erase_in = forward_list_##type_name##_t_erase_in;\
    self->remove = forward_list_##type_name##_t_remove;\
    self->remove_if = forward_list_##type_name##_t_remove_if;\
    self->len = forward_list_##type_name##_t_len;\
    if (type) {\
        self->free = forward_list_##type_name##_t_delete_heap;\
    } else {\
        self->free = forward_list_##type_name##_t_delete_stacked;\
    }\
}\
\
bool            forward_list_##type_name##_t_delete_heap(struct forward_list(type_name) *self) {\
    forward_list_##type_name##_t_delete_in(self);\
    return true;\
}\
\
bool            forward_list_##type_name##_t_delete_stacked(struct forward_list(type_name) *self) {\
    forward_list_##type_name##_t_delete_in(self);\
    return false;\
}\
\
void            forward_list_##type_name##_t_delete_in(struct forward_list(type_name) *self) {\
    flist_iterator(type_name) *tmp;\
    while(self->first) {\
        tmp = self->first->next;\
        free(self->first);\
        self->first = tmp;\
    }\
}\
\
T                           *forward_list_##type_name##_t_front(struct forward_list(type_name) *self) {\
    T *return_value = 0;\
    if (self->first) {\
        return_value = &self->first->item;\
    }\
    return return_value;\
}\
\
void                        forward_list_##type_name##_t_push_front(struct forward_list(type_name) *self, T new_item) {\
    flist_iterator(type_name) *tmp = malloc(sizeof(flist_iterator(type_name)));\
    if (tmp) {\
        tmp->item = new_item;\
        tmp->next = self->first;\
        if (!self->first) {\
            self->last = tmp;\
            tmp->next = 0;\
        }\
        self->first = tmp;\
        self->size += 1;\
    }\
}\
\
void                        forward_list_##type_name##_t_pop_front(struct forward_list(type_name) *self) {\
    flist_iterator(type_name) *tmp = self->first;\
    if (self->first) {\
        self->first = self->first->next;\
        free(tmp);\
    }\
}\
\
struct flist_iterator(type_name)    *forward_list_##type_name##_t_begin(struct forward_list(type_name) *self) {\
    return self->first;\
}\
\
struct flist_iterator(type_name)    *forward_list_##type_name##_t_end(struct forward_list(type_name) *self) {\
    return 0;\
}\
\
bool                        forward_list_##type_name##_t_is_empty(struct forward_list(type_name) *self) {\
    return self->size == 0;\
}\
\
struct flist_iterator(type_name)    *forward_list_##type_name##_t_insert_after(struct forward_list(type_name) *self, \
    struct flist_iterator(type_name) *it, T new_item) {\
    \
}\
\
struct flist_iterator(type_name)    *forward_list_##type_name##_t_erase_after(struct forward_list(type_name) *self, \
    struct flist_iterator(type_name) *it) {\
    \
}\
\
struct flist_iterator(type_name)    *forward_list_##type_name##_t_erase_in(struct forward_list(type_name) *self, \
    struct flist_iterator(type_name) *it1, flist_iterator(type_name) *it2) {\
    \
}\
\
void                        forward_list_##type_name##_t_remove(struct forward_list(type_name) *self, T rm_item) {\
    \
}\
\
void                        forward_list_##type_name##_t_remove_if(struct forward_list(type_name) *self, bool (*predicate)(T *item)) {\
    \
}\
\
unsigned int                forward_list_##type_name##_t_len(struct forward_list(type_name) *self) {\
    return self->size;\
}\

#endif // CSML_FORWARD_LIST_H