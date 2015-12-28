#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  string line;
  std::vector<char> arrChar;
  while (getline(cin, line))
    {
      if (line == "#") break;
      arrChar.assign(line.length(), 'a');
      for (size_t i = 0; i < line.length(); ++i)
	{
	  arrChar[i] = line[i];
	}
      next_permutation(arrChar.begin(), arrChar.end());
      string nextOne = string(arrChar.begin(), arrChar.end());
      if (nextOne > line) cout << nextOne << endl;
      else printf("No Successor\n");
    }

  return 0;
}
