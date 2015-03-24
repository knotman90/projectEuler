module Main where


limit = 10^999
fib :: Integer -> Integer -> Integer -> Integer
fib a b t 
	| b >= (limit) = t
	| otherwise = fib b (a+b) (t+1)

main = do
	let str = "The number is " ++ (show (fib  1 1 2)) 
	putStrLn str
