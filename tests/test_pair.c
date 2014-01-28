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

#include <stdio.h>
#include "csml.h"
#include "csml_method_macro.h"

// call the macros with the givens types to implement a stack for this type.
impl_pair(int, int, char, char);

int main() {
	// new stack on the heap
    pair(int, char) 	*heap_pair =   new(pair(int, char), 10, 'a');
    // new stack on the stack
    pair(int, char) 	stacked_pair = stacked(pair(int, char), 20, 'b');

    printf("Heap pair = first_item: %d / second_item: %c \n", 
        heap_pair->first,
        heap_pair->second);
    printf("Stacked pair = first_item: %d / second_item: %c \n", 
        stacked_pair.first,
        stacked_pair.second);

    printf("Now swap them: \n");
    swap(heap_pair, &stacked_pair);
    printf("Heap pair = first_item: %d / second_item: %c \n", 
        heap_pair->first,
        heap_pair->second);
    printf("Stacked pair = first_item: %d / second_item: %c \n", 
        stacked_pair.first,
        stacked_pair.second);

    // delete the pair allocated on the heap
    delete(heap_pair);
    // delete the pair allocated on the stack...
    delete(&stacked_pair);

    return 0;
}
