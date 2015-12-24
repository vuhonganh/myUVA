//uva 1062 Containers : world final 2007
//type: greedy + stack

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main()
{
  string line;
  int caseNb = 1;
  vector<char> charAtTops;
  while (getline(cin, line))
    {
      if (line == "end") break;
      charAtTops.clear();
      charAtTops.push_back(line[0]);
      for (size_t i = 1; i < line.length(); ++i)
	{
	  char c = line[i];
	  bool createNew = true;
	  for (size_t j = 0; j < charAtTops.size(); ++j)
	    {
	      if (c <= charAtTops[j]) 
		{
		  charAtTops[j] = c;
		  createNew = false;
		  break;
		}
	    }
	  if (createNew) charAtTops.push_back(c);
	}
      printf("Case %d: %zd\n", caseNb++, charAtTops.size());
    }
  
  return 0;
}
