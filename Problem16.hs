module Problem16 where


digitize x
	| x `div` 10 == 0 = [x]
	| otherwise = digitize (x `div` 10) ++ [x `mod` 10]

problem16 :: Integer -> Integer
problem16 = sum . digitize
