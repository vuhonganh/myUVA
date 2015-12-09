//uva 467 Synching Signals

#include <cstdio>
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int periode;
  string line;
  vector<int> periodes;
  while (getline(cin, line))
    {
      if (!periodes.empty()) periodes.clear();
      cout << "printing the line: " << line << endl;

      //NEED TO USE STRINGSTREAM HERE
      while (sscanf(line.c_str(), "%d%[^\n]", &periode))
	{
	  periodes.push_back(periode);
	}
      for (size_t i = 0; i < periodes.size(); ++i)
	{
	  cout << periodes[i] << " "; 
	}
      cout << endl;
    }
}
