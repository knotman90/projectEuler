{-
This is actually very similar to problem #16. 
Naive fact may be computed by product [1..100], then usiong the digitize function developed in Problem16 we compute the sum using the built in sum function


-}
--function from problem16
digitize x
	| x `div` 10 == 0 = [x]
	| otherwise = digitize (x `div` 10) ++ [x `mod` 10]

problem16 :: Integer
problem16 = sum ( digitize (product [1..100]))
