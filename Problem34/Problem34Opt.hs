import qualified Data.Vector.Unboxed as V

--from a discussion and helps of  András Kovács
-- http://stackoverflow.com/questions/29413564/haskell-performance-tuning/29414801#29414801

facs :: V.Vector Int
facs =
  V.fromList [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]

--BRUTE FORCE SOLUTION
solve:: Int
solve = sum (filter (\x-> sfc x 0 == x) [10..2540160])

--sum factorial of digits
sfc :: Int -> Int -> Int
sfc 0 acc = acc
sfc n acc = sfc n' (acc + V.unsafeIndex facs r)
    where
		dr = divMod n 10
		n' = fst dr
		r  = snd dr

main = print solve
