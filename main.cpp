#include <iostream>

#include "frac_int.h"

class frac_long: public frac {
    long num,den;
    
  public:
    frac_long(long num, long den=1)
      : num(num), den(den)
    {}
    
    virtual frac& operator+(const frac & r) const 
    {
	  try 
	  {
	    const frac_long &ri = dynamic_cast<const frac_long&>(r);
	    
	    if( den == ri.den )
	    {
	      return *(new frac_long( num + ri.num, den));
	    }
	    
	    return *(new frac_long( num*ri.den + ri.num*den, den*ri.den ));
	  }
	  catch(std::bad_cast)
	  {
	    throw std::invalid_argument(
	      std::string("frac_long::operator+() - invalid argument. Type is ")
	      +
	      std::string( typeid(r).name() )
	      );
	  }
    }

    virtual frac& operator-(const frac & r) const
    {
	  try 
	  {
	    const frac_long &ri = dynamic_cast<const frac_long&>(r);
	    
	    if( den == ri.den )
	    {
	      return *(new frac_long( num - ri.num, den));
	    }
	    
	    return *(new frac_long( num*ri.den - ri.num*den, den*ri.den ));
	  }
	  catch(std::bad_cast)
	  {
	    throw std::invalid_argument(
	      std::string("frac_long::operator+() - invalid argument. Type is ")
	      +
	      std::string( typeid(r).name() )
	      );
	  }
  }
 
    
  protected:
    virtual void ReadNum(std::istream &i) {} /*!!!*/ ;
    virtual void WriteNum(std::ostream &o) const {} /*!!!*/ ;
    
    virtual void ReadDen(std::istream &i) {} /*!!!*/ ;
    virtual void WriteDen(std::ostream &o) const {} /*!!!*/ ;
};


int main()
{
  frac_int f(3,4);
  
  std::cout << f << std::endl;
  
  try 
  {
    frac_long f2(2,5);
    //std::cin  >> f2 ;
    std::cout << f2 + f << std::endl;
    std::cout << f - f2 << std::endl;
  }
  catch(std::exception &e)
  {
    std::cerr << "exception: " << e.what() << std::endl;
  }
  catch(...)
  {
    std::cerr << "OMG WTH ICQ" << std::endl;
  }

  return 0;
}
