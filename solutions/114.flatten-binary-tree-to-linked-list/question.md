Given a binary tree, flatten it to a linked list in-place.

For example,
Given


         1
        / \
       2   5
      / \   \
     3   4   6


&nbsp;

The flattened tree should look like:


   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6


click to show hints.

Hints:

If you notice carefully in the flattened tree, each node&#39;s right child points to the next node of a pre-order traversal.
