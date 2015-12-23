//uva 12541 Birthdates

#include <cstdio>
#include <cassert>
#include <cstring>
struct person
{
  char m_name[16];
  int m_d, m_m, m_y;
  bool youngerThan(person &p) const
  {
    if (m_y > p.m_y) return true;
    else if (m_y == p.m_y)
      {
    	if (m_m > p.m_m) return true;
    	else if (m_m == p.m_m)
    	  return m_d > p.m_d;
      }
    return false;
    //return (m_y > p.m_y || m_m > p.m_m || m_d > p.m_d); WRONG REASONING
  }
};

int main()
{
  int n;
  //string name; DOES NOT WORK
  char name[16];
  int d, m, y;
  assert(scanf("%d", &n) == 1);
  person youngest, oldest;
  bool debug = false;
  for (int i = 0; i < n; ++i)
    {
      assert(scanf("%s", name) == 1);
      assert(scanf("%d", &d) == 1);
      assert(scanf("%d", &m) == 1);
      assert(scanf("%d", &y) == 1);
      //struct person cur {name, d, m, y}; THIS DOES NOT WORK 
      person cur;
      strcpy(cur.m_name, name); //NEED TO DO A STRCPY
      cur.m_d = d;
      cur.m_m = m;
      cur.m_y = y;
      if (i == 0) 
	{
	  youngest = cur;
	  oldest = cur;
	}
      else
	{
	  if (cur.youngerThan(youngest))
	    {
	      youngest = cur;
	    } 
	  if (oldest.youngerThan(cur))
	    {
	      oldest = cur;
	    } 
	}
    }
  printf("%s\n", youngest.m_name);
  printf("%s\n", oldest.m_name);
  return 0;
}
