module Main where

import Data.List

solve::Integer 
solve = solve' 100 100

solve' :: Integer -> Integer -> Integer
solve' a b = let l = [a^b | a<-[2..a], b<-[2..b]] 
				in maximum $ map (sumDigits 0) l

sumDigits ::Integer -> Integer -> Integer
sumDigits acc 0 = acc
sumDigits acc n = sumDigits  (acc+r) d
	where 
		dr = divMod n 10
		d = fst dr
		r = snd dr

main = do
	putStrLn ("The solution is: "++ (show solve))
