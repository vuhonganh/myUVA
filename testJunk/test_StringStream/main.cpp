#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
  string line = "1 2 3 I";

  stringstream buffer;
  buffer.str(line);
  int val, val2, val3; char status;
  buffer >> val >> val2 >> val3 >> status;
  cout << val << endl;
  cout << val2 << endl;
  cout << val3 << endl;
  cout << status << endl;

  string line2 = "4 5 6 O";
  buffer.str(line2);
  buffer >> val >> val2 >> val3 >> status;
  cout << val << endl;
  cout << val2 << endl;
  cout << val3 << endl;
  cout << status << endl;

  string line3 = "1 A 0:50 N";
  buffer.str(line3);
  int teamNb, hour, minute;
  char probLetter;
  buffer >> teamNb >> probLetter;
  // buffer >> hour >> minute >> status;
  buffer >> hour;
  char twodot;
  buffer >> twodot;
  buffer >> minute;
  buffer >> status;
  cout << teamNb << endl;
  cout << probLetter << endl;
  cout << hour << endl;
  cout << twodot << endl;
  cout << minute << endl; 
  cout << status << endl;

  return 0;
}
