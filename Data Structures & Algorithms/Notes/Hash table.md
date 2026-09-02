$O(log N)$
# HASH TABLE
A hash table is a array of fixed size. 

Stores the data at index obtained by getting intData % size_of_array. so each piece of data gets unique index.

Has operations:
- Insert()
- delete()
- Find(): $O(1)$.

To insert or delete an item, the index for the position has to be found. Use helper **function hash(key)** to map the key (string, integer, etc) into the array and returns the **hash value (index)**.

## Collision
When two keys are mapped to the same index.
When happens, the key is mapped to a different index - Collision resolution or try and find the next empry cell.

**Load Factor = No_of_items/arr_size**

The higher the LF, the more collisions and more time for insert and delete.

### Linear Probing
When a collision occurs, try successive locations until find empty position.

- Lazy deletion: Mark item as deleted, unused or active.

A disadvantage of linear probing is that it creates primary clustering where large cell blocks are occupied.

### Quadratic Probing
After collision, probing happens on every quadratic steps *i* = 1, 4, 9, 16, ....

Advantage of this is that it avoids primary clustering.

***Rehashing***: Good practice to increase the array size when its 75% full and rehash everything in the new array.

### Separate chaining.
Use a linked list to keep keys mapped to same index.

## Drawbacks of hashing
- Keys are unordered, findMin/Max are veryb expensive.


