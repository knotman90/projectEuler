module Problem22 where
import Text.Regex(splitRegex,mkRegex)
import Data.List
import Data.Char

--word weight
wW :: String -> Integer
wW  = foldl' (\acc x -> (acc + (w x))) 0
        where
        w  x = (toInteger (ord x)) - 97 +1
    
sumItUp :: [String] -> (Integer,Integer)
sumItUp  = foldl' f (0,1)
        where f (acc,p) x = (acc + (wW x)*p, p+1)

main::IO()
main = do
rawstr <-  readFile "names.txt"
let splitted = splitRegex (mkRegex ",") (( (filter (/='"')) . (map toLower)) rawstr)
let sorted = sort (splitted)
putStrLn ((show . fst . sumItUp) sorted) 

