#ifndef  frac_int_h
#define  frac_int_h

#include "frac.h"

class frac_int: public frac {
    int num;
    int den;
    
  public:
    frac_int();
    frac_int(int num, int den = 1);
    frac_int(const frac_int &o);
    
    //---
    virtual frac& operator+(const frac & r) const ;
    virtual frac& operator-(const frac & r) const ;
    //---
    
    ~frac_int();
    
  protected:
    virtual void ReadNum(std::istream &i) ;
    virtual void WriteNum(std::ostream &o) const ;
    
    virtual void ReadDen(std::istream &i) ;
    virtual void WriteDen(std::ostream &o) const ;
};

#endif //frac_int_h
