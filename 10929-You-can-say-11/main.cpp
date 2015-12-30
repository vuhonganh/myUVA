#include <iostream>
#include <string>

using namespace std;

int main()
{
  string line;
  while (getline(cin, line))
    {
      if (line == "0") break;
      
      bool minus = false;
      int sum = 0;
      int length = (int) line.length();
      for (size_t i = 0; i < line.length(); ++i)
	{
	  int digit = (line[length - i - 1] - '0');
	  sum += (minus) ? 0 - digit : digit;
	  minus = !minus;
	}
      if (sum < 0) sum = 0 - sum;
      if ((sum % 11) == 0) cout << line << " is a multiple of 11." << endl;
      else cout << line << " is not a multiple of 11." << endl;
    }
  
  return 0;
}
  
