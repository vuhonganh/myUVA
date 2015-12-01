//uva 10131 Is Bigger Smatter
//Longest Decreasing Sequence (after sorting the weight)

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct elephan
{
  int w;
  int iq;
  int id;
};

bool compWeightRev(const elephan &lhs, const elephan &rhs) //compare W reverse
{
  return lhs.w > rhs.w;
}

bool compIqRev(const elephan &lhs, const elephan &rhs) //compare IQ reverse
{
  return lhs.iq > rhs.iq;
}

int main()
{
  int wi, si;
  int n = 1; //nb of elephants
  vector<elephan> elephans;;
  while (scanf("%d %d", &wi, &si) == 2)
    {
      elephan cur {wi, si , n};
      elephans.push_back(cur);
      ++n;
    }
  sort(elephans.begin(), elephans.end(), compWeightRev);
  vector<int> L;
  vector<int> L_id;
  vector<int> Parrent;
  for (size_t i = 0; i < elephans.size(); ++i)
    {
      int cur_iq = elephans[i].iq;
      size_t pos = lower_bound(L.begin(), L.end(), cur_iq) - L.begin();
      if (pos == L.size())
	{
	  L.push_back(cur_iq);
	  L_id.push_back(i);
	}
      else
	{
	  L[pos] = cur_iq;
	  L_id[pos] = i;
	}
      if (pos > 0) Parrent.push_back(L_id[pos - 1]);
      else Parrent.push_back(-1);
    }
  
  vector<int> sequence;
  int idLastElem = L_id[L.size() - 1];
  sequence.push_back(elephans[idLastElem].id);
  int idxParrent = Parrent[idLastElem];
  while (idxParrent != -1)
    {
      sequence.push_back(elephans[idxParrent].id);
      idxParrent = Parrent[idxParrent];
    }
  printf("%zd\n", sequence.size());
  for (size_t i = 0; i < sequence.size(); ++i)
    {
      printf("%d\n", sequence[i]);
    }

  
  return 0;
}
