maybeHead :: [a] -> Maybe a
maybeHead []     = Nothing
maybeHead (x:xs) = Just x

f :: [a] -> Bool
f xs = case maybeHead xs of
         Nothing -> False
         Just _  -> True

