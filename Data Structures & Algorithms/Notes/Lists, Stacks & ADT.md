# Abstract data types
A set of data and operations(methods) that can be performed on the data.
- Examples: List, Stack, Queue, Tree, Graph.
- Content and behavior of the methods are defined, implementation is hidden.

# Arrays
- A collection of items stored at contiguous memory locations.
- Can be accessed using an index.
- Can contain duplicates.

# Stack
- A contiguous collection of items where the last item added is the first one to be removed (LIFO).

- Operations: push (add), pop (remove). 
- Can be implemented using arrays (fixed size) or linked lists (dynamic size).
- Stack overflow: when trying to push an item onto a full stack.


## Array implementation
- Fixed size, need to define max size of stack.

- An integer to keep track of Top of stack, initialized to -1 when stack is empty. When pushing, increment top and add item at top index. When popping, return item at top index and decrement top.

## Linked list implementation
- equally simple and
straightforward. In fact, a simple singly linked list is
sufficient to implement a stack — it only requires that the
head node or element can be removed, or popped, and a node
can only be inserted by becoming the new head node

# Queue
- Non-contiguous collection of items where the first item added is the first one to be removed (FIFO), implemented linked lists: sequence of nodes where each node contains data and a reference to the next node. 

- Operations: enqueue (add), dequeue (remove).



