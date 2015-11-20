#include <set>
#include <cstdio>
#include <iostream>

using namespace std;

struct table
{
  int id;
  int cap;
  bool operator<(const table &a) const
  {
    return cap > a.cap;
  }
};

int main()
{
  set<int> mySet;
  set<int>::iterator it;
  mySet.insert(1);
  mySet.insert(9);
  mySet.insert(5);
  mySet.insert(7);
  mySet.insert(3);
  for (it = mySet.begin(); it != mySet.end(); ++it)
    cout << *it << " ";
  cout << endl;

  multiset<table> S;
  table cur1 {1, 9};
  table cur2 {3, 5};
  table cur3 {2, 7};
  table cur4 {4, 10};
  S.insert(cur1);
  S.insert(cur2);
  S.insert(cur3);
  S.insert(cur4);
  
  multiset<table>::iterator itS;
  for (itS = S.begin(); itS != S.end(); ++itS)
    cout << (*itS).id << "-" << (*itS).cap << ", ";
  cout << endl;
    
  return 0;
}
