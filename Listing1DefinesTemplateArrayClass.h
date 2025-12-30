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
     
// End of File