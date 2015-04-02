module Main where

import qualified System.Directory as D
import qualified System.Environment as E
import Data.List
import Data.Char
import System.IO.Error 

--par1 = path
ras :: String -> [String]
ras s = sort $ ws s
	where
		ws =   (words.(filter (/='"') ) . map (\x -> if x==',' then ' ' else x)) 

--word weeight		
ww :: String -> Int
ww  = foldl' (\acc x -> acc + (ord' x)) 0

--Lex position of the char (always upper case)
ord'::Char ->Int
ord' a = (ord a) - (ord 'A') +1

--total weight max value is ord' 'Z' per lenght max of the words in file
tw :: [String] -> Int
tw = foldl' f 0
	where 
		f acc x 
			| wwx `elem` tri = acc + 1
			| otherwise 	 = acc
				where wwx = ww x
		tri = map (\n -> div (n*n +n) 2) [1..50]		

main = do
	(arg1:_) <- E.getArgs
	e <- D.doesFileExist arg1
	if e==False then error "File does not exist" else do
		str<- readFile arg1
		let s = ras str
		putStrLn ("The solution is :" ++ (show (tw s)))
