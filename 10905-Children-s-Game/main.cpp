#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(const string &x, const string &y)
{
  string t1 = x + y;
  string t2 = y + x;
  return (t1 > t2);
} 

int main()
{
  int N;
  char c;
  string line;
  vector<string> nums;
  while (scanf("%d", &N) == 1 && N != 0)
    {
      while(scanf("%c", &c) == 1 && c != '\n') {};
      nums.clear();
      if (getline(cin, line))
	{
	  char * line_in_char = new char [line.length() + 1];
	  strcpy(line_in_char, line.c_str());
	  char * aVal = strtok(line_in_char, " ");
	  while (aVal != NULL)
	    {
	      nums.push_back(string(aVal));
	      aVal = strtok(NULL, " ");
	    }
	  delete line_in_char;
	}
      sort(nums.begin(), nums.end(), compare);
      for (int i = 0; i < N; ++i)
	{
	  cout << nums[i];
	}
      cout << endl;
    }
  
}
