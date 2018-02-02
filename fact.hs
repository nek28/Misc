{-# LANGUAGE TypeSynonymInstances, FlexibleInstances #-}
module Fact where

import Prelude hiding (gcd, lcm, (<>))

type Factorization = [Int]

instance {-# OVERLAPPING #-} Monoid Factorization where
	mempty = [] :: Factorization
	mappend = dot
	mconcat = foldr dot []

factorize :: Int -> Factorization
factorize n
	| n `mod` 2 == 0 = 2 : factorize (n `div` 2)
	| otherwise = 

toint :: Factorization -> Int
toint = foldr (*) 1

dot :: Factorization -> Factorization -> Factorization
dot (x:xs) (y:ys)
	| y < x = y : dot (x:xs) ys
	| y > x = x : dot xs (y:ys)
	| otherwise = x : y : dot xs ys
dot a [] = a
dot [] b = b

factorize 

gcd :: Factorization -> Factorization -> Factorization
gcd (x:xs) (y:ys)
	| x == y = x : gcd xs ys
	| x > y  = gcd (x:xs) ys
	| otherwise = gcd xs (y:ys)
gcd _ _ = []

lcm :: Factorization -> Factorization -> Factorization
lcm (x:xs) (y:ys)
	| x < y = x : lcm xs (y:ys)
	| x == y = x : lcm xs ys
	| otherwise = y : lcm (x:xs) ys
lcm [] xs = xs
lcm xs [] = xs

-- <| read as 'divides'
(<|) :: Factorization -> Factorization -> Bool
[] <| b = True
(x:xs) <| (y:ys)
	| x > y = (x:xs) <| ys
	| x < y = False
	| otherwise = xs <| ys
_ <| _ = False
