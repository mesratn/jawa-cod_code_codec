#include  <iostream>
#include  "Dialogue.hpp"

int main(int ac, char *av[])
{
  if (ac != 2)
  {
    std::cerr << "need an argument" << std::endl;
    return (-1);
  }
  Dialogue test(av[1]);

  if (!test.parse())
    return (-1);
  while (!test.empty())
  {
    std::cout << test.front().index << " - " << test.front().talker << ": " << test.front().quote << std::endl;
    test.pop();
  }
  return (0);
}
