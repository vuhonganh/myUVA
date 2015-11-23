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

void test_intSet()
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
}

void test_struct_multiset()
{
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
}

struct pairAB
{
  int A;
  int B;
  bool operator< (const pairAB &a) const
  {
    return A < a.A;
  }
};

int main()
{
  //test set with struct having equal values (to find out if set consider them as the same)
  set<pairAB> pairs;
  pairAB p1 {1, 3};
  pairAB p2 {3, 1};
  pairAB p3 {1, 3};
  pairs.insert(p1);
  pairs.insert(p2);
  pairs.insert(p3);
  set<pairAB>::iterator it;
  for (it = pairs.begin(); it != pairs.end(); ++it)
    {
      cout << (*it).A << ", " << (*it).B << endl;
    }
  return 0;
}
