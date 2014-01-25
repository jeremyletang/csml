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

// call the macros with the givens types to implement a stack for this type.
impl_vector(int, int);

int main() {
	// new stack on the heap
    Vector(int) 	*heap_vector =   new(Vector(int), 10);
    // new stack on the stack
    // Vector(int) 	stacked_stack = stacked(Stack(int));

 //    // use heap stack
 //    printf("Heap Stack size: %d\n", heap_stack->len(heap_stack));
 //    heap_stack->push(heap_stack, 21);
 //    heap_stack->push(heap_stack, 42);
 //    heap_stack->push(heap_stack, 84);
 //    printf("Heap Stack size after a push: %d\n", heap_stack->len(heap_stack));
 //    heap_stack->pop(heap_stack);
 //    printf("Heap Stack size after a pop: %d\n", heap_stack->len(heap_stack));
 //    printf("Heap Stack top value after a push: %d\n", *heap_stack->top(heap_stack));

 //    // use stacked stack
 //    printf("Stacked Stack size: %d\n", stacked_stack.len(&stacked_stack));
 //    stacked_stack.push(&stacked_stack, 21);
 //    printf("Stacked Stack size after a push: %d\n", stacked_stack.len(&stacked_stack));
 //    printf("Stacked Stack top value after a push: %d\n", *stacked_stack.top(&stacked_stack));

 //    // delete the stack allocated on the heap
 //    delete(heap_stack);
 //    // delete the stack allocated on the stack...
 //    delete(&stacked_stack);

    return 0;
}
