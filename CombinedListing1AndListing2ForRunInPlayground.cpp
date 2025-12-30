//Listing 1: Defines template array class
class RangeException
{
public:
 RangeException(int dim,int low, int high, int index) 
 {
  m_dim = dim;
  m_low = low;
  m_high = high;
  m_index = index;
 }
     
 int m_dim,m_low,m_high,m_index;
};
     
template <class Type,
int low, int high,int D=1> class A1D 
{
public:
     
     
 Type& operator[](const int i)
 {
  if(i<low || i>high)
  {
    throw(RangeException(D,low,high,i));
  }
     
  return element[i-low];
 }
     
     
 int begin() const {return low;}
 int end()   const {return high;}
 int dim()   const {return D;}
     
private:
 Type element[high-low+1];
};
     
template <class Type,  
 int L1,  int H1,
 int L2,  int H2,int D=2> 
 class A2D : public A1D<A1D<Type,L2,H2>,L1,H1,D>
{
     
     
};
     
template <class Type, 
 int L1,  int H1,
 int L2,  int H2,
 int L3,  int H3, int D=3> 
 class A3D : public A1D<A2D<Type,L2,H2,L3,H3>,L1,H1,D>
{
     
};
     
     
template <class Type,
 int L1,  int H1,
 int L2,  int H2,
 int L3,  int H3,
 int L4,  int H4,int D=4> 
 class A4D : public A1D<A3D<Type,L2,H2,L3,H3,L4,H4>,L1,H1,D>
{
     
     
};
     
//Listing 2: Using the array template
#include <stdio.h>
//#include "Listing1DefinesTemplateArrayClass.h"

     
int main()
{
     
 try{
  A1D<int,10,19> va1d; 
  va1d[11] = 102;
     
  A2D<int,10,19,20,29> va2d;
  va2d[11][28] = 11;
     
  A3D<int,10,19,20,29,30,39> va3d;
     
     
  int dim1 =va3d.dim();
  int low1 =va3d.begin();
  int high1= va3d.end();
  int dim2=va3d[low1].dim();
  int low2 =va3d[low1].begin();
  int high2 = va3d[low1].end();
     
  int dim3=va3d[low1][low2].dim();
     
  int low3 =va3d[low1][low2].begin();
  int high3 =va3d[low1][low2].end();
  printf("dim: %dX%dX%d\n",dim1,dim2,dim3);
     
     
  for( int i= low1; i<=high1; ++i)
   for( int j=low2; j<=high2; ++j)
    for( int k=low3; k<=high3; ++k)
    va3d[i][j][k] = (i*100+j)*100+k;
     
     
  for(int  i= low1; i<=high1; ++i)
   for( int j=low2; j<=high2; ++j)
    for( int k=low3; k<=high3; ++k)
     if(va3d[i][j][k] != (i*100+j)*100+k)
      printf("%2d%2d%2d != %d\n",i,j,k,va3d[i][j][k]);
     
  //Projection
  A1D<int, 30,39> va3d_1Dsubarr;
  va3d_1Dsubarr = va3d[10][20];
  for(int i=va3d_1Dsubarr.begin(); i<=va3d_1Dsubarr.end(); ++i)
   printf("[%d]=%d\n",i,va3d_1Dsubarr[i]);
     
     
  A3D<int,10,19,20,29,30,39> *pva3d= new A3D<int,10,19,20,29,30,39>;
     
  A3D<int,10,19,20,29,30,39>& rva3d = *pva3d;
     
  //raise range error exception
  //va3d[1][20][30] = 1;
  //va3d[10][2][31] = 2;
  va3d[10][20][3] = 3;
     
     
  puts("\nend");
  while(1);
 }
 catch(RangeException RE)
 {
  char buf[128];
  sprintf(buf,
  "The %d-D(sub)array:\n  The subscript %d is out of range: %d:%d\n",
   RE.m_dim,RE.m_index,RE.m_low,RE.m_high);
  puts(buf);
 }
     
     
}
     
//End of File

