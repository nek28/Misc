# Miscellaneous

Some random pieces of code that I would need for some particular task.

continued_fractions is a couple of functions that use Euclid's algorithm to display an improper fraction as a continued one. For a fun output, I suggest using it on some relatively big successive Fibonacci numbers (or, in general, Lucas numbers) like 121393 and 75025.

fact.hs is a small library for dealing with multiplicative properties of natural numbers only in terms of the lists of their prime factors. This is mainly as an illustration of how a lot of GCD and divisibility problems can easily be thought about as problems of substrings, string concatenation and so on. The operation (dot) is simply inserting (in order) the factors of b into a. GCD is close to the problem of finding the largest common substring. From this it is easy to see why LCM should be ab/GCD. I plan to insert some functions dealing with the lattice structure. 
