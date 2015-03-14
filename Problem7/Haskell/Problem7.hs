module Problem7 where

limit=10001
--params : last prime, position of the last prime (the nth), current
problem7 :: Integer -> Integer -> Integer -> Integer
problem7 p 10001 _ =  p
problem7 p k c     
    |isPrime c = problem7 c (k+1) (c+2)
    |otherwise = problem7 p k (c+2)
                 
isPrime :: Integer -> Bool
isPrime n = 0 ==  length (dropWhile (\v -> (n`mod`v) /=0) [2..(floor $ sqrt(fromInteger n))])


