module Main where
{-
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?

Solution is:296962999629
-}

isPrime a =  foldl (\acc x->acc && not ((mod a x)==0)) True [2..(div a 2)]

--upperbound 6669
fS [] acc = acc
fS (x:xs) acc
	| x > 3339 = acc
	| a `elem` xs  && b `elem` xs = fS (filter (not . (`elem` tr)) xs) ([(x,a,b)]:acc)
	|otherwise = fS (filter (not . (`elem` tr)) xs) acc
	where 
		a = x+3330
		b = a+3330
		tr=x:a:b:[]			


--few outputs so can be checked by hand for brevity
main = do
	let primes = filter (isPrime) [1001,1003..9997]
	let val = fS primes []
	putStrLn (show val)
