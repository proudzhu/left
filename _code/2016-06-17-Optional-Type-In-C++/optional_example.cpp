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
