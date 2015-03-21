{-
Naive solution. It simply scan all possible 13tuple of numbers and look for maximum (product of digits)
A more efficient solution could be to consider that a zero cause 13 tuple to have 0 product!
-}
import Data.Char

numberInOneLine :: String -> String
numberInOneLine  = foldl (++) [] . words

splitNumber :: String -> [Integer] -> Integer -> Integer
splitNumber  [] _ v = v 
splitNumber cc@(c:cs) yy@(y:ys) v 
  | v < productNew = splitNumber cs tokenNew productNew 
  | otherwise = splitNumber cs tokenNew v                          
  where
    tokenNew   = (ys++ ([toInteger (digitToInt c)]))
    productNew = product tokenNew 
    productOld = product yy
              
digitize :: Integer -> [Integer]
digitize x
	| x `div` 10 == 0 = [x]
	| otherwise = digitize (x `div` 10) ++ [x `mod` 10]
	

main = do 
  putStrLn "Please Insert the filename where bigNumber is stored:"
  fileName <- getLine
  strRaw <-  readFile fileName 
  let str= numberInOneLine strRaw
  let first13= (digitize (read (take 13 str)))
  let splitted = splitNumber (drop 13 str)  first13 (product first13) 
  putStrLn $ show  (splitted)
  putStrLn $ show  (product first13)
