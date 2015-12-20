#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  string line;
  while (getline(cin, line))
    {
      char * line_in_char = new char [line.length() + 1];
      strcpy(line_in_char, line.c_str());
      vector<string> vals;
      char * aVal = strtok(line_in_char, " ");
      while (aVal != NULL)
	{
	  vals.push_back(string(aVal));
	  aVal = strtok(NULL, " ");
	}
      for (size_t i = 0; i < vals.size(); ++i)
	{
	  cout << vals[i] << endl;
	  //printf("%s\n", vals[i]);
	}
    }
  return 0;
}
