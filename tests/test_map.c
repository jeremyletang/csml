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
#include "csml/map.h"
#include "csml/method_macros.h"

impl_pair(int, int, char, char);
impl_map(int, int, char, char);

bool cmp_key(int i, int j) {
    return i == j;
}

int main() {
    map(int, char)     *heap_map =   new(map(int, char), cmp_key);
    map(int, char)     stacked_map = create(map(int, char), cmp_key);

    insert(heap_map, 1, 'b');
    insert(heap_map, 2, 'c');
    insert(heap_map, 3, 'f');
    printf("Heap map at 2: %c\n", *at(heap_map, 2));

    delete(heap_map);
    delete(&stacked_map);

    return 0;
}
