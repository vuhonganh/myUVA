#include <cstdio>
#include <cstring>
int multi2(int a)
{
  return 2 * a;
}

void testAr1D()
{
  printf("\nTest ar1D with length is a defined variable in scope\n");
  int nDeclared = 5;
  int ar1[nDeclared];
  for (int i = 0; i < nDeclared; ++i)
    {
      ar1[i] = i;
    }
  for (int i = 0; i < nDeclared; ++i)
    {
      printf("%d ", ar1[i]);
      if (i == nDeclared - 1) printf("\n");
    }

  printf("\nTest ar1D with length is a computed variable\n");
  int nComputed = multi2(nDeclared);
  int ar2[nComputed];
  for (int i = 0; i < nComputed; ++i)
    {
      ar2[i] = i;
    }
  for (int i = 0; i < nComputed; ++i)
    {
      printf("%d ", ar2[i]);
      if (i == nComputed - 1) printf("\n");
    }
  printf("\nTest ar1D with length is a scanned variable get from scanf()\n");
  printf("enter some positive integer: ");
  int nScanned;
  scanf("%d", &nScanned);
  int ar3[nScanned];
  for (int i = 0; i < nScanned; ++i)
    {
      ar3[i] = i;
    }
  for (int i = 0; i < nScanned; ++i)
    {
      printf("%d ", ar3[i]);
      if (i == nScanned - 1) printf("\n");
    }
}

void testAr2D()
{
  printf("\nTest ar2D with lengths are a scanned variables get from scanf()\n");
  
  int nbScanned1;
  printf("enter one positive integer for the height: ");
  scanf("%d", &nbScanned1);
  
  int nbScanned2;
  printf("enter one positive integer for the width: ");
  scanf("%d", &nbScanned2);
  
  int ar2D[nbScanned1][nbScanned2];
  for (int i = 0; i < nbScanned1; ++i)
    {
      for (int j = 0; j < nbScanned2; ++j)
	{
	  ar2D[i][j] = i + j;
	}
    }
  for (int i = 0; i < nbScanned1; ++i)
    {
      for (int j = 0; j < nbScanned2; ++j)
	{
	  printf("%d ", ar2D[i][j]);
	}
      printf("\n");
    }
}

void testAr2D_init()
{
  int h, w;
  printf("enter the size of height: "); scanf("%d", &h);
  printf("enter the size of width: "); scanf("%d", &w);
  printf("try to init with syntax int ar[h][w] = {1}\n");
  printf("int ar[h][w] = {1}; WILL NOT COMPILE so i turned it to a printf\n");
  int ar[h][w];
  //memset(ar, -1, sizeof(int) * h * (w));
  memset(ar, -1, sizeof(ar));
  printf("NEED memset instead, there are two ways: sizeof(whole_obj) or sizeof(type_obj * dimensions)\n");
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  printf("%d ", ar[i][j]);
	}
      printf("\n");
    }
}

int main()
{
  testAr2D_init();
  return 0;
}
