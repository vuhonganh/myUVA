//uva 10901 Ferry Loading III
//type: tricky to implement

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define TRACE(x) if (debug) cout << #x << " = " << x << endl

struct car
{
  int m_arrivalTime;
  bool m_sideIsLeft;
  int m_unloadedTime;
  bool isAtLeft() const
  {
    return m_sideIsLeft;
  }

  bool isAtRight() const
  {
    return !m_sideIsLeft;
  }
  
  void printArriveTime() const
  {
    printf( m_sideIsLeft ? "%d left\n" : "%d right\n", m_arrivalTime);
  }

  void printUnloadTime() const
  {
    printf("%d\n", m_unloadedTime);
  }

  bool isLoaded() const
  {
    return (m_unloadedTime != -1);
  }
};

void printInput(const vector<car> &cars)
{
  for (size_t i = 0; i < cars.size(); ++i)
    {
      cars[i].printArriveTime();
    }
  printf("\n");
}

inline bool atSameSide(const bool &ferryAtLeft, const bool &carAtLeft)
{
  if (ferryAtLeft && carAtLeft) return true;
  if (!ferryAtLeft && !carAtLeft) return true;
  return false;
}

int main()
{
  string line;
  stringstream buffer;
  getline(cin, line);
  int nbCase;
  buffer.str(line);
  buffer >> nbCase;
  int n, t, m;
  string arrivalSide;
  int arrivalTime;
  vector<car> cars;
  car cur{0, true, -1};
  //bool debug = true;
  bool debug = false;
  while (nbCase--)
    {
      
      getline(cin, line);
      buffer.clear(); buffer.str(line);
      buffer >> n >> t >> m;
    
      cars.assign(m, cur);

      TRACE(n); TRACE(t); TRACE(m);
      for (int i = 0; i < m; ++i)
	{
	  getline(cin, line);
	  buffer.clear(); buffer.str(line);
	  buffer >> arrivalTime >> arrivalSide;
	  
	  TRACE(arrivalTime); TRACE(arrivalSide);

	  if (arrivalSide == "right") cars[i].m_sideIsLeft = false;
	  cars[i].m_arrivalTime = arrivalTime;
	}
      
      int curTime = 0;
      if (cars.size() > 0) curTime = cars[0].m_arrivalTime; //init for the current time equal to the arrival time of the first car
      int toLoad = m;
      bool ferryAtLeft = true;
      size_t startIdx = 0;
      while (toLoad > 0)
	{
	  //pick the maximum cars ALREADY THERE to go to the other side
	  int cnt = 0;
	  bool consecutive = true;
	  size_t nextStartIdx = startIdx;
	  //for (size_t i = startIdx; i < cars.size(); ++i) //TO IMPROVE : start from a min index in each case, not from 0
	  for (size_t i = 0; i < cars.size(); ++i) //TO IMPROVE : start from a min index in each case, not from 0
	    {
	      if (cars[i].m_unloadedTime == -1 && cars[i].m_arrivalTime <= curTime && atSameSide(ferryAtLeft, cars[i].isAtLeft()))
		{
		  cars[i].m_unloadedTime = curTime + t;
		  cnt++;
		  if (consecutive)
		    {
		      if (i == 0 || (i > 0 && cars[i - 1].m_unloadedTime != -1) )
			{
			  nextStartIdx = i + 1;
			}
		      else 
			{
			  consecutive = false;
			}
		    }
		} 
	      if (cnt == n || cars[i].m_arrivalTime > curTime) break;
	    }
	  startIdx = nextStartIdx;
	  if (cnt > 0) //if there are cars that we can port to other side
	    {
	      curTime += t; //go to the other side already, update time
	      toLoad -= cnt;
	      ferryAtLeft = !ferryAtLeft;
	    }
	  else //i.e. there is no car at this side at this moment
	    {
	      if (startIdx == cars.size()) break;
	      //two case:
	      //case 1 : there is no car at both sides at this moment -> wait until the next car arrive (dont know which side yet)
	      //case 2 : there is car waiting at the other side
	      //treat case 2 first as it's simpler
	      if (cars[startIdx].m_unloadedTime == -1 && cars[startIdx].m_arrivalTime <= curTime && !atSameSide(ferryAtLeft, cars[startIdx].isAtLeft()))
		{
		  if (debug) cout << "there is car waiting at the other side at time = "  << curTime << endl;
		  curTime += t; //go to the other side
		  ferryAtLeft = !ferryAtLeft;
		}
	      else //no car at both sides at this moment
		{
		  if (debug) cout << "No car at both sides at this moment time = " << curTime << endl;
		  //wait for the next car to arrive
		  size_t i = 0;
		  while (curTime >= cars[startIdx + i].m_arrivalTime)
		    {
		      i++;
		      if (i + startIdx == cars.size()) break;
		    }
		  curTime = cars[startIdx + i].m_arrivalTime;
		  //curTime = cars[startIdx].m_arrivalTime;
		}
	    }
	  //ferryAtLeft = !ferryAtLeft;
	}

      for (size_t i = 0; i < cars.size(); ++i)
	{
	  cars[i].printUnloadTime();
	}
      if (nbCase) printf("\n");
    }
  
  return 0;
}
