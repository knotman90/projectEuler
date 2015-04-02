module Main where

--fact of digit
fc :: Int-> Int
fc a 
	| a<0 || a > 9= undefined
	|otherwise		= facts !! (fromIntegral a)
		where 
			facts = [1,1,2,6,24,120,720,5040,40320,362880]

--BRUTE FORCE SOLUTION
solve:: Int
solve = sum (filter (\x-> sfc x 0==x) [10..2540160])


--sum factorial of digits
sfc :: Int -> Int -> Int
sfc 0 acc = acc
sfc n acc = sfc n' (acc+fc r)
	where
		dr = divMod n 10
		n' = fst dr
		r  = snd dr
		fc 0 =1
		fc 1 =1
		fc 2 =2
		fc 3 =6
		fc 4 =24
		fc 5 =120
		fc 6 =720
		fc 7 =5040
		fc 8 =40320
		fc 9 =362880
	


main = do
	let val = solve
	putStrLn ("The solution is: " ++ (show val))
