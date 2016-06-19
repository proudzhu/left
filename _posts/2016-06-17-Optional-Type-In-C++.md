---
layout: post
---

### Optional Type
From wikipedia:

In programming languages (more so functional programming languages) and type theory, an             option type or maybe type is a polymorphic type that represents encapsulation of an optional value; e.g., it is used as the return type of functions which may or may not return a meaningful value when they are applied. It consists of a constructor which either is empty (named None or Nothing), or which encapsulates the original data type A (written Just A or Some A). Outside of functional programming, these are termed nullable types.

### Name and Defines

In Haskell: ``` data Maybe a = Nothing | Just a ```

In C++: ``` std::experimental::optional ``` (from c++17)

Also seen in many other languages, such as rust, swift and so on.

### Haskell Maybe

Here I use `head` for example.

```haskell
*Main> head []
*** Exception: Prelude.head: empty list
*Main> head "abcd"
'a'
```

It is not safe to apply `head` on an empty list, but we could define a new function.

```haskell
maybeHead :: [a] -> Maybe a
maybeHead []     = Nothing
maybeHead (x:xs) = Just x
```

now we could use `maybeHead` below.

```haskell
*Main> maybeHead []
Nothing
*Main> maybeHead "abcd"
Just 'a'
*Main Data.Maybe> fromJust $ maybeHead "abcd"
'a'
```

or use it in a code block

```haskell
f :: [a] -> Bool
f xs = case maybeHead xs of
         Nothing -> False
         Just _  -> True
```

load in ghci

```haskell
*Main> f []
False
*Main> f "abcd"
True
```

### C++ Optional

optional will be introduced in c++17.

```c++
#include <iostream>
#include <experimental/optional>

std::experimental::optional<int> string_to_int(std::string s)
{
  if (s.length() == 0)
    return std::experimental::nullopt;
  else
    return std::stoi(s);
}

int main(void)
{
  auto x = string_to_int("");
  auto y = string_to_int("42");

  if (!x)
    std::cout << "x input is a zero length string\n";

  std::cout << x.value_or(0) << "\n"
            << y.value_or(0) << "\n";

  return 0;
}
```

output

```bash
x input is a zero length string
0
42
```