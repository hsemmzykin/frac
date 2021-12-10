#include "frac.h"

#include <stdexcept>

frac::frac()
{}

frac::frac(const frac &o)
{}

frac::~frac()
{}

std::ostream & operator<<(std::ostream &o, const frac &f)
{
  f.WriteNum(o);
  o << '/';
  f.WriteDen(o);
  
  return o;
}

std::istream & operator>>(std::istream &i,       frac &f)
{
  f.ReadNum(i);
  if( i.get() != '/' )
  {
    throw std::runtime_error("frac - can not read fraction sign");
  }
  f.ReadDen(i);
  
  return i;
}

