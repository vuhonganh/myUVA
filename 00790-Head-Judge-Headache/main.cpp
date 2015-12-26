//uva 790 head judge headache
//type: non trivial implementation

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define TRACE(x) if (debug) cout << #x << " = " << x << endl

struct team
{
  int m_teamNb;
  int m_nbProbSol;
  int m_time;
  map <char, vector<int> > m_ProbSubm; //the first element of the vector is -1 if unsolved, if it's solved, this changes to the time it's solved, other elements contains the unsuccessful submission time
  bool operator< (const team &o) const
  {
    if (m_nbProbSol > o.m_nbProbSol)
      {
	return true;
      }
    else if (m_nbProbSol == o.m_nbProbSol)
      {
	if (m_time < o.m_time)
	  {
	    return true;
	  }
	else if (m_time == o.m_time)
	  {
	    return m_teamNb < o.m_teamNb;
	  }
      }

    return false;
  }

  void readInput(int teamNb, char probLetter, int hour, int minute, char status)
  {
    m_teamNb = teamNb;
    if (m_nbProbSol == -1) m_nbProbSol = 0; //if this is the first time this team shows off
    int curTime = hour * 60 + minute;
    
    //if it's the first time read this problem for this team
    if (m_ProbSubm[probLetter].size() == 0)
      {
	if (status == 'Y') //if it's correct
	  {
	    m_ProbSubm[probLetter].push_back(curTime);
	  }
	else //submission failed
	  {
	    m_ProbSubm[probLetter].push_back(-1); //first element is -1
	    m_ProbSubm[probLetter].push_back(curTime); //second element is the submission time of this faillure
	  }
      }
    else //contain already other information
      {
	if (status == 'Y')
	  {
	    //change if this submission is sooner or unsolved before
	    if (m_ProbSubm[probLetter][0] == -1 || m_ProbSubm[probLetter][0] > curTime)
	      m_ProbSubm[probLetter][0] = curTime;
	  }
	else //this is a unsuccessful submission, add it to the list if it's not duplicated ---- NOTE: IT COUNTS DUPLICATION so i commented the block of code below
	  {
	    // bool duplicate = false;
	    // for (size_t i = 1; i < m_ProbSubm[probLetter].size(); ++i)
	    //   {
	    // 	if (curTime == m_ProbSubm[probLetter][i])
	    // 	  {
	    // 	    duplicate = true;
	    // 	    break;
	    // 	  }
	    //   }
	    // if (!duplicate) m_ProbSubm[probLetter].push_back(curTime);
	    m_ProbSubm[probLetter].push_back(curTime); //THE SOLUTION COUNTS DUPLICATION
	  }
      }
  }
  
  void finalProcess()
  {
    map<char, vector<int> >::iterator it;
    for (it = m_ProbSubm.begin(); it != m_ProbSubm.end(); ++it)
      {
	vector<int> curV = it->second;
	if ( curV[0] != -1)
	  {
	    for (size_t i = 1; i < curV.size(); ++i)
	      {
		if (curV[0] >= curV[i]) //IF IT HAPPENS AT THE SAME TIME, COUNTS IT AS HAPPENS BEFORE ALSO (that's why we use ">=" instead of ">" )
		  m_time += 20;
	      }
	    m_time += curV[0];
	    m_nbProbSol++;
	  }
      }
  }
  
  void process(int teamNb, char probLetter, int hour, int minute, char status) //DO NOT NEED THIS ONE ANYMORE
  {
    m_teamNb = teamNb;
    if (m_nbProbSol == -1) m_nbProbSol = 0; //if this is the first time this team shows off
    int curTime = hour * 60 + minute;

    //if it's the first time read this problem for this team
    if (m_ProbSubm[probLetter].size() == 0)
      {
	if (status == 'Y') //if it's correct
	  {
	    m_ProbSubm[probLetter].push_back(curTime);
	    m_time += m_ProbSubm[probLetter][0];
	    m_nbProbSol++;
	  }
	else
	  {
	    m_ProbSubm[probLetter].push_back(-1); //first element is -1
	    m_ProbSubm[probLetter].push_back(curTime); //second element is the submission time of this faillure
	  }
      }
    else //contains already submission about this problem for this team
      {
	if (m_ProbSubm[probLetter][0] != -1) //already solved
	  {
	    if (status == 'N')
	      {
		if (curTime < m_ProbSubm[probLetter][0])
		  {
		    bool duplicate = false;
		    for (size_t i = 1; i < m_ProbSubm[probLetter].size(); ++i)
		      {
			if (curTime == m_ProbSubm[probLetter][i])
			  {
			    duplicate = true;
			    break;
			  }
		      }
		    if (!duplicate) m_time += 20;
		  } 
	      }
	    else //already solved and solved again - check which one is the sooner
	      {
		if (curTime < m_ProbSubm[probLetter][0])
		  {
		    m_time += curTime - m_ProbSubm[probLetter][0];
		    m_ProbSubm[probLetter][0] = curTime;
		  }
	      }
	  }
	else //unsolved
	  {
	    if (status == 'N')
	      {
		m_ProbSubm[probLetter].push_back(curTime);
	      }
	    else //solved for this time
	      {
		m_ProbSubm[probLetter][0] = curTime;
		m_time += m_ProbSubm[probLetter][0];
		m_nbProbSol++;
		for (size_t i = 1; i < m_ProbSubm[probLetter].size(); ++i)
		  {
		    if (m_ProbSubm[probLetter][i] < m_ProbSubm[probLetter][0])
		      {
			m_time += 20;
		      }
		  }
	      }
	  }
      }
  }
  
};

int main()
{
  string line;
  stringstream buffer;
  int teamNb, hour, minute;
  char probLetter, twodot, status;

  vector <team> teams;

  bool debug = false;

  getline(cin, line); //to read the number of cases
  int nbCase;
  buffer.str(line);
  buffer >> nbCase; 

  TRACE(nbCase);
 
  getline(cin, line); //this line is a blank line
  TRACE(line);

  while (nbCase--)
    {
      team a{0, -1, 0, map<char, vector<int> >()};
      teams.assign(26, a);
      stringstream ssToAvoidCoreDump; // if i do not use -> core dump
      int teamNbMax = 1;
      while (getline(cin, line))
	{
	  if (line.length() == 0) break; //done one case
	  ssToAvoidCoreDump.str(line);
	  ssToAvoidCoreDump >> teamNb >> probLetter >> hour >> twodot >> minute >> status;
	  TRACE(teamNb); TRACE(probLetter);
	  //cout << teamNb << probLetter << hour << twodot << minute << status;
	  //teams[teamNb].process(teamNb, probLetter, hour, minute, status);
	  teams[teamNb].readInput(teamNb, probLetter, hour, minute, status);
	  teamNbMax = max(teamNb, teamNbMax);
	}
      for (int i = 1; i <= teamNbMax; ++i)
	{
	  if (teams[i].m_nbProbSol == -1) 
	    {
	      teams[i].m_nbProbSol = 0;
	      teams[i].m_teamNb = i;
	    }
	  else //passed to readInput
	    {
	      teams[i].finalProcess();
	    }
	}
      
      sort(teams.begin(), teams.end());

      printf("RANK TEAM PRO/SOLVED TIME\n");
      int rank = 1;
      for (size_t i = 0; i < teams.size(); ++i)
	{
	  if (teams[i].m_nbProbSol == -1) break;
	  if (i > 0)
	    {
	      if (teams[i].m_nbProbSol != teams[i - 1].m_nbProbSol || teams[i].m_time != teams[i - 1].m_time) //rank does not change if equal
		{
		  rank = i + 1;
		}
	    }
	  if (teams[i].m_nbProbSol > 0)
	    printf("%4d %4d %4d%11d\n", rank, teams[i].m_teamNb, teams[i].m_nbProbSol, teams[i].m_time);
	  else
	    printf("%4d %4d\n", rank, teams[i].m_teamNb);
	} 
      if (nbCase) printf("\n");
    }
  
  return 0;
}
