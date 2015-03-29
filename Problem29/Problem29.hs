
import Data.List

buildList :: Integer -> Integer -> Int
buildList a b = let l = [a^b | a<-[2..a], b<-[2..b]] 
				in length (remDup l)
	     	where remDup  = (map  head . group . sort)
