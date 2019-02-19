f :: (a -> Bool) -> [a] -> [Int]
f p xs = faux 0 p xs
  where
    faux i p [] = []
    faux i p (x:xs) | p x = [i] ++ faux (i+1) p xs | otherwise = faux (i+1) p xs

f1 :: (a -> Bool) -> [a] -> [Int]
-- f1 p xs =
--  map (\x -> snd x) (filter (\x -> p (fst x)) (zip xs [0..]))
f1 p = map fst . filter (p . snd) . zip [0..]

-- altro modo [x | x <- map fst . filter (p . snd) . zip [0..]]

-- funzioni da sapere

-- map, filter, zipwith, foldr, foldl, concat, zip, uncurry, curry, fst,
-- snd, length, take, drop, all, any, reverse, ++, takeWhile, head, tail

-- foldr :: Foldable t => (a -> b -> b) -> b -> t a -> b
-- reduce mettendo il reducer a destra nell'operazione
-- foldl stessa cosa ma a sinistra

-- Definire una funzione che, applicata a una lista xs, ritorna la sotto-lista
-- contenente tutti e soli gli elementi di xs in posizione pari,
-- nello stesso ordine in cui compaiono in xs e assumendo che il primo elemento
-- della lista si trovi in posizione 0. È vietato fare uso di funzioni
-- della libreria standard ad eccezione di mod e quelle che hanno un nome simbolico, come +, ., ecc.

s1 :: [a] -> [a]

s1 [] = []
s1 [x] = [x]
s1 (x:y:xs) = [x] ++ s1(xs)

s2 :: [a] -> [a]

s2 = map snd . filter (even . fst) . zip [0..]

perfetto :: Int -> Bool

perfetto x = (somma . divisori) x == (x * 2)
  where
    somma [] = 0
    somma (x:xs) = x + somma xs
    divisori 0 = []
    divisori x = divisori1 1 x
    divisori1 y x | y <= x && mod x y == 0 = [y] ++ divisori1 (y+1) x | y <= x && mod x y /= 0 = divisori1 (y+1) x | otherwise = []


inversioni :: [Int] -> Int

inversioni [] = 0
inversioni [a] = 0
inversioni (x:y:xs) = (if y > x then 1 else 0) + inversioni (y:xs)

inv :: [Int] -> Int

inv xs = (length . filter (\x -> snd x > fst x) . zip xs . tail) xs

data Tree a = Empty | Node a [Tree a]

-- deve tornare la lista di tutti gli elementi
elements :: Tree a -> [a]

elements Empty = []
elements (Node e t) = e : concat (map elements t)

normalize :: Tree a -> Tree a

normalize Empty = Empty
normalize (Node e t) = Node e ((map normalize . filter (\x -> isNode x)) t)
  where
    isNode (Node e t) = True
    isNode _ = False
