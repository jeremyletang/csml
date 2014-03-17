csml
====

Like C++ STL but with macros and C

# Example
```C
/* import csml stuff */
#include "csml/csml.h"
/* include functions shortcuts macros */
#include "csml/method_macros.h"
/* call the macros with the givens types to implement a stack for this type */
impl_flist(int, int);

int main() {
	/* new forward list on the heap */
    flist_t(int) 	*list = new(flist_t(int));

    /* push some elements in the list */
    push_front(list, 42);
    push_front(list, 84);
    push_front(list, 21);
	
	/* iterate over the list */
	flist_iterator(int) *it = begin(list);
	for (;!equals(it, end(list)); inc(it)) {
    	printf("List item: %d\n", *get(it));
	}

    // delete the list
    delete(list);
}
```
