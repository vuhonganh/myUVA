//uva 10258 Contest Scoreboard
//rewrite sort function

#include <cstdio>
//#include <cassert>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define TRACE(x) if (debug) cout << #x << " = " << x << endl;

struct player
{
  int m_idx;  //index of the player
  int m_nbP;  //number of problems solved PAR DEFAULT assign this number to -1 (for PLAYERS WHO DO NOT PARTICIPATE)
  int m_time; //total time

  map<int, int> m_probIncorrect; //store a map with key = problem number -> value = time of incorrect, if this is correct, change the value to -1
  //vector<int> m_probIncorrect; //THIS WILL DO THE JOB TOO
  bool operator< (const player &o) const
  {
    if (m_nbP > o.m_nbP)
      {
	return true;
      }
    else if (m_nbP == o.m_nbP)
      {
	if (m_time < o.m_time)
	  {
	    return true;
	  }
	else if (m_time == o.m_time)
	  {
	    return m_idx < o.m_idx;
	  }
      }
    return false;
  }
  
  void process(int idx, int probNb, int time, char status) 
  {
    m_idx = idx;
    switch(status)
      {
      case 'R':
      case 'U':
      case 'E':
	if (m_nbP == -1) m_nbP = 0; //if this is the first time, change to 0
	break;
      case 'I':
	if (m_nbP == -1) m_nbP = 0; //if this is the first time, change to 0
	if (m_probIncorrect[probNb] != -1)
	  {
	    m_probIncorrect[probNb]++;
	  }
	break;
      case 'C':
	if (m_probIncorrect[probNb] != -1)//if it's the first time solve this problem
	  {
	    m_time += time + m_probIncorrect[probNb] * 20;
	    m_probIncorrect[probNb] = -1;
	    if (m_nbP == -1) m_nbP = 1;
	    else m_nbP++;
	  }
	break;
      default:
	printf("some thing wrong while reading input at the status character\n");
	break;
      }
  }
  
}; 

void printPlayer(const player &p) 
{
  printf("%d %d %d\n", p.m_idx, p.m_nbP, p.m_time);
}

void printFinalSorted(const vector<player> &allPlayers)
{
  for (size_t i = 0; i < allPlayers.size(); ++i)
    {
      if (allPlayers[i].m_nbP == -1) break;
      printPlayer(allPlayers[i]);
    }
}

int main()
{
  //player init{0, -1, 0, vector<int>(10, 0)}; //this is for if you want to use vector, BECAUSE THERE ARE ONLY 9 questions 
  player init{0, -1, 0, map<int, int>()};
  vector<player> allPlayers;
  int nbCase;
  char status;
  int idx, probNb, time;
  string line;
  stringstream ss;
  //bool debug = true;
  bool debug = false;
  getline(cin, line);
  ss.str(line);
  ss >> nbCase;
  TRACE(nbCase);
  getline(cin, line); //this line is blank
  TRACE(line);
  while (nbCase--)
    {
      allPlayers.assign(104, init);
      //DO NOT UNDERSTAND WHY REUSE ss defined above will cause CORE DUMP !!!
      // -> USE A NEW stringstream instead
      stringstream buffer;
      while (getline(cin, line))
	{
	  if (line.length() == 0) //done one case
	    {
	      break;
	    }
	  else
	    {
	      //TRACE(line);
	      //stringstream buffer(line); 
	      //ss >> idx >> probNb >> time >> status; //THIS WILL GIVE STRANGE BEHAVIOR
	      buffer.str(line);
	      buffer >> idx >> probNb >> time >> status;
	      TRACE(idx); TRACE(probNb); TRACE(time); TRACE(status);
	      allPlayers[idx].process(idx, probNb, time, status);
	    }
	}
      sort(allPlayers.begin(), allPlayers.end());
      printFinalSorted(allPlayers);
      if (nbCase) printf("\n");
	     
    }
  
  return 0;
}
