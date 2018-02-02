# Miscellaneous

Some random pieces of code that I might/would need for some particular task.

continued_fractions is a couple of functions that use Euclid's algorithm to display an improper fraction as a continued one. For a fun output, I suggest using it on some relatively big successive Fibonacci numbers (or, in general, Lucas numbers) like 121393 and 75025.

fact.hs is a very small set of functions for dealing with multiplicative properties of natural numbers only in terms of the lists of their prime factors. This is mainly as an illustration of how a lot of GCD and divisibility problems can easily be thought about as problems (like a|n, b|n, gcd(a,b)=1 ==> ab|n) of substrings, string concatenation and so on. The operation (dot) is simply inserting (in order) the factors of b into a. GCD is close to the problem of finding the largest common substring. From this it is easier to see why LCM should be ab/GCD. I plan to insert some functions dealing with the lattice structure. Might implement a list data structure so that I won't have an OverlappingInstances problem. I did not use newtype wrapper mainly for simplicity and aesthetic reasons, it being just a toy library.
