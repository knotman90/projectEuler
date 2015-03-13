module Problem3 (problem) where


testInt = 600851475143

problem = last $ problem3 testInt 3 [] 

problem3 :: Integer -> Integer -> [Integer] -> [Integer]
problem3 n a acc
	 |product acc == n =  acc 
	 |n `mod` a==0 = a:problem3 (div n a) (a) acc
	 |otherwise    =problem3 n (a+1) acc