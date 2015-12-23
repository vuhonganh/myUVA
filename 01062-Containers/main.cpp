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
  while (getline(cin, line))
    {
      if (line == "end") break;
      vector<stack<char> >arrStacks;
      stack<char> firstStack;
      firstStack.push(line[0]);
      arrStacks.push_back(firstStack);
      for (size_t i = 1; i < line.length(); ++i)
	{
	  char c = line[i];
	  //for each stack in the array of stack, try if this stack can add this value or add a new stack for this
	  bool createNew = true;
	  for (size_t j = 0; j < arrStacks.size(); ++j)
	    {
	      if (c <= arrStacks[j].top())
		{
		  arrStacks[j].push(c);
		  createNew = false;
		  break;
		}
	    }
	  if (createNew) 
	    {
	      stack<char> newStack;
	      newStack.push(c);
	      arrStacks.push_back(newStack);
	    }
	}
      printf("Case %d: %zd\n", caseNb++, arrStacks.size());
    }
  
  return 0;
}
