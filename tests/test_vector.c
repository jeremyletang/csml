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
#include "csml/vector.h"
#include "csml/method_macros.h"

/* call the macros with the givens types to implement a vector for this type. */
impl_vector(int, int);

void increment_of_ten(int *item, void *data) {
    (void)(data);
    *item += 10;
}

int main() {
	/* new vector on the heap */
    vector(int) 	*heap_vector =   new(vector(int), 2);
    /* new stack on the stack */
    vector(int) 	stacked_vector = create(vector(int), 20);

    printf("Heap vector len / capacity: %d / %d\n", 
        len(heap_vector), 
        capacity(heap_vector));
    printf("Stacked vector len / capacity: %d / %d\n", 
        len(&stacked_vector), 
        capacity(&stacked_vector));

    push_back(heap_vector, 42);
    printf("Heap vector front / back: %d / %d\n", 
        *front(heap_vector), 
        *back(heap_vector));
    push_back(heap_vector, 21);
    printf("Heap vector front / back: %d / %d\n", 
        *front(heap_vector), 
        *back(heap_vector));
    printf("Heap vector len / capacity: %d / %d\n", 
        len(heap_vector), 
        capacity(heap_vector));
    push_back(heap_vector, 84);
    for_each(heap_vector, increment_of_ten, 0);
    printf("After call to for_each, item1: %d, item2: %d, item3: %d\n", 
        *at(heap_vector, 0),
        *at(heap_vector, 1),
        *at(heap_vector, 2));
    pop_back(heap_vector);
    printf("Heap vector front / back: %d / %d\n", 
        *front(heap_vector), 
        *back(heap_vector));
    printf("Heap vector len / capacity: %d / %d\n", 
        len(heap_vector), 
        capacity(heap_vector));
    printf("Heap vector at index 1: %d\n", *at(heap_vector, 1));

    /* delete the stack allocated on the heap */
    delete(heap_vector);
    /* delete the stack allocated on the stack... */
    delete(&stacked_vector);

    return 0;
}
