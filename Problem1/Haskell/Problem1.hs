module Problem1 where

problem1 :: [Integer] -> Integer
problem1 = foldr (sumIf) 0
           where sumIf x acc = 
                    if((x `mod` 3 ==0) || (x `mod` 5 == 0) ) 
                       then acc+x
                    else        
                      acc

problem1' :: [Integer] -> Integer
problem1' = sum . filter (\x -> x `mod` 3==0 || x `mod` 5 ==0)
