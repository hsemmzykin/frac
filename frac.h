#ifndef  frac_h
#define  frac_h

#include <ostream>
#include <istream>

class frac {
  public:
    frac();
    frac(const frac &o);
    
    friend std::ostream & operator<<(std::ostream &o, const frac &f);
    friend std::istream & operator>>(std::istream &i,       frac &f);
    
    virtual frac& operator+(const frac & r) const = 0 ;
    virtual frac& operator-(const frac & r) const = 0 ;
    
    ~frac();
    
  protected:
    virtual void ReadNum(std::istream &i) = 0 ;
    virtual void WriteNum(std::ostream &o) const = 0 ;
    
    virtual void ReadDen(std::istream &i) = 0 ;
    virtual void WriteDen(std::ostream &o) const = 0 ;
};

#endif //frac_h
