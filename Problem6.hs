module Problem6 where

n = 100
problem6 = squareSum - sumSquare
--sum of the first n number = (n^2+n)/2 -> simply becomes squareSum
squareSum = 1/4*(n^4+2*n^3+n^2)
--first create a list with squares of the first n numbers the sum them up
sumSquare = sum $ map (^2) [1..n]