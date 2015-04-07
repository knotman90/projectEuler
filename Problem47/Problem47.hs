module Main where

import Data.List 
pfacts' :: Int -> Int -> Int->[Int] -> [Int]
pfacts' 0 _ _ acc = acc
pfacts' n c l acc
	|mod n c == 0 = pfacts' (div n c) c l (c:acc)
	|c > (div l 2) = acc   
	|otherwise 	  = pfacts' n (c+1) l acc

pfacts :: Int -> [Int]
pfacts n = pfacts' n 2 n []

l4f :: [(Int,Int)]
l4f = filter (\x->snd x==4) $ map (\x->(x,(length.nub.pfacts) x)) [210..]


solve l@((n1,a):(n2,b):(n3,c):(n4,d):xs)
	| n1+n2+n3+n4 == n1*2 + n2 +n3 +3 = n1
	|otherwise =solve (three++xs)
		where
			three = take 3 $ tail l
	
main = do
	putStrLn "Working ..."
	putStrLn $ show(solve l4f )
