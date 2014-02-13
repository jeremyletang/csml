csml
====

Like C++ STL but with macros and C

# Example
```C
// call the macros with the givens types to implement a stack for this type.
impl_stack(int, int);

int main() {
	// new stack on the heap
    Stack(int) 	*heap_stack = new(Stack(int));
    // new stack on the stack
    Stack(int) 	stacked_stack = create(Stack(int));

    // use heap stack
    printf("Heap Stack size: %d\n", heap_stack->len(heap_stack));
    heap_stack->push(heap_stack, 10);
    printf("Heap Stack size after a push: %d\n", heap_stack->len(heap_stack));

    // use stacked stack
    printf("Stacked Stack size: %d\n", stacked_stack.len(&stacked_stack));
    stacked_stack.push(&stacked_stack, 10);
    printf("Stacked Stack size after a push: %d\n", stacked_stack.len(&stacked_stack));

    // delete the stack allocated on the heap
    delete(heap_stack);
    // delete the stack allocated on the stack...
    delete(&stacked_stack);
}
```
