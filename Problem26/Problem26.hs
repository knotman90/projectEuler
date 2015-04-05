module Main where

import Data.List
{-
 The length of the repetend (period of the repeating decimal) of 1/p is equal to the order of 10 modulo p. If 10 is a primitive root modulo p, the repetend length is equal to p − 1; if not, the repetend length is a factor of p − 1. This result can be deduced from Fermat's little theorem, which states that 10p−1 = 1 (mod p).
-}
--modulo, current order
order :: Integer -> Integer -> Integer
order a ord 
	| mod (10^ord) a == 1 = ord
	| ord > a 			  = 0
	| otherwise 		  = order a (ord+1) 


maxo = sortBy (\x y -> (snd x) `compare` (snd y)) $ map (\x->(x,order x 1)) [1..1000]



