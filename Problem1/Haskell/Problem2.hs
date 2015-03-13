module Problem2 where

--Dynamic Programming approach 4^10e6 is not a big deal
limit=4000000

problem2 :: Integer
problem2 = problem2' 0 0 1 

problem2' :: Integer -> Integer -> Integer -> Integer
problem2' acc pp p 
         | acc > limit = acc
         | (odd pp) && (odd p) = problem2' (acc + succ) p succ
         | otherwise           = problem2' acc p succ             
           where succ = pp+p