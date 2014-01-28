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

#include <stdio.h>
#include "csml.h"
#include "csml_method_macro.h"

impl_flist(int, int);

int main() {
    forward_list(int) 	*heap_list =   new(forward_list(int));
    forward_list(int) 	stacked_list = create(forward_list(int));

    push_front(heap_list, 42);
    push_front(heap_list, 84);
    push_front(heap_list, 21);
    push_front(heap_list, 12);
    push_front(heap_list, 128);
    push_front(heap_list, 1024);
    printf("Heap list front: %d\n", *front(heap_list));
    /* heap_list->pop_front(heap_list);
    printf("Heap list front: %d\n", *heap_list->front(heap_list)); */
    flist_iterator(int) *it = begin(heap_list);
    for (;!equals(it, end(heap_list)); it = next(it)) {
        printf("list item: %d\n", *get(it));
    }


    delete(heap_list);
    delete(&stacked_list);
    return 0;
}
