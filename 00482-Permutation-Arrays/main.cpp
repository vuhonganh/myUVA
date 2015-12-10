//uva 482 permutation arrays
//easy 1D array manipulation with use of string tockenizer

#include <cstdio>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;


int main()
{
  int nbCase;
  string line;
  vector<string> ar;
  vector<int> pos;
  getline(cin, line);
  stringstream ss(line);
  ss >> nbCase;

  while (nbCase--)
    {
      getline(cin, line); //this is a blank line
      if (!pos.empty()) pos.clear();
      getline(cin, line); //first line contain only integer
      stringstream ss2(line);
      int idx;
      while (ss2 >> idx)
	{
	  pos.push_back(idx - 1);
	}
      ar.assign(pos.size(), "");
      getline(cin, line);
      char * lineChar = new char[line.length()];
      strcpy(lineChar, line.c_str());
      char * cur = strtok(lineChar, " ");
      int i = 0;
      while (cur != NULL)
	{
	  ar[pos[i++]] = string(cur);
	  cur = strtok(NULL, " ");
	}
      delete [] lineChar;
      delete cur;
      for (size_t i = 0; i < ar.size(); ++i)
	{
	  cout << ar[i] << endl;
	}
      if (nbCase) printf("\n");
    }
  return 0;
}
