{-Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
The number are assume to be in the same folder in a file named numbers
-}
sumUp :: [String] -> Integer
sumUp = foldl (process) 0
	where process acc s = (read s) + acc  

main = do
	str <- readFile "numbers"
	putStrLn (take 10 (show (sumUp (words str))))
