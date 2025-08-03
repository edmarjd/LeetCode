# Nome: EDMAR JACINTO DOMINGOS FRANCISCO

# 1569. Number of Ways to Reorder Array to Get Same BST


Given an array that represents a permutation of integers from to . We are going to construct a binary search tree (BST) by inserting the elements of in order into an initially empty BST. Find the number of different ways to reorder so that the constructed BST is identical to that formed from the original array .

For example, given , we will have 2 as the root, 1 as a left child, and 3 as a right child. The array also yields the same BST but yields a different BST.nums = [2,1,3][2,3,1][3,2,1]
Return the number of ways to reorder such that the BST formed is identical to the original BST formed from .numsnums

Since the answer may be very large, return it modulo .109 + 7.

Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.


Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST: 
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]


Input: nums = [1,2,3]
Output: 0
Explanation: There are no other orderings of nums that will yield the same BST.
