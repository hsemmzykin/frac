#include "frac_int.h"

#include <stdexcept>
#include <typeinfo>
#include <string>

frac_int::frac_int()
  : num(0), den(1)
{}

frac_int::frac_int(int num, int den)
  : num(num), den(den)
{}

frac_int::frac_int(const frac_int &o)
  : num(o.num), den(o.den)
{}

frac_int::~frac_int()
{}

void frac_int::ReadNum(std::istream &i)
{
  if( !(i >> num) )
  {
    throw std::runtime_error("frac - can not read numerator");
  }
}

void frac_int::WriteNum(std::ostream &o) const 
{
  o << num ;
}

void frac_int::ReadDen(std::istream &i)
{
  if( !(i >> den) )
  {
    throw std::runtime_error("frac - can not read denomenator");
  }
}

void frac_int::WriteDen(std::ostream &o) const 
{
  o << den ;
}

frac& frac_int::operator+(const frac & r) const 
{
  try 
  {
    const frac_int &ri = dynamic_cast<const frac_int&>(r);
    
    if( den == ri.den )
    {
      return *(new frac_int( num + ri.num, den));
    }
    
    return *(new frac_int( num*ri.den + ri.num*den, den*ri.den ));
  }
  catch(std::bad_cast)
  {
    throw std::invalid_argument(
      std::string("frac_int::operator+() - invalid argument. Type is ")
      +
      std::string( typeid(r).name() )
      );
  }
}

frac& frac_int::operator-(const frac & r) const 
{
  try 
  {
    const frac_int &ri = dynamic_cast<const frac_int&>(r);
    
    if( den == ri.den )
    {
      return *(new frac_int( num - ri.num, den));
    }
    
    return *(new frac_int( num*ri.den - ri.num*den, den*ri.den ));
  }
  catch(std::bad_cast)
  {
    throw std::invalid_argument(
      std::string("frac_int::operator+() - invalid argument. Type is ")
      +
      std::string( typeid(r).name() )
      );
  }
}

