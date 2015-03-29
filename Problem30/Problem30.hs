
{-
The key is to find an upper bound which is given by noticing that
9^5*k is the maximim value of the sum of the digits (raised to the 5th power) that a kdigit number can have.
9^5*5 >= 99999 but 9^5*7 < 1000000. hence an upper bound is 9^5*6
-}
sumDigits :: Int->Int->Int->Int
sumDigits n s p
	|n==0 		= s
	|otherwise 	=  sumDigits (n `div` 10) (s+(n `mod` 10)^p) p 

bruteForce:: Int->[Int]->Int->[Int]
bruteForce k acc p
	|k == 2 	=	 acc
	|otherwise	= if s==k then k:rest else rest
		where 
			rest = bruteForce (k-1) acc p
			s = sumDigits k 0 p


solve = sum (filter (\n -> (sumDigits n 0 5)==n) [2..354294])
