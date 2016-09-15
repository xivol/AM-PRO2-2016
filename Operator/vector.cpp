#include "vector.h"
#include <cmath>

vector::vector(void):x(0.0),y(0.0) {}
vector::vector(double x, double y):x(x),y(y){}
vector::vector(const point &start, const point &finish):
    x(finish.get_x()-start.get_x()), y(finish.get_y()-start.get_y()) {}


double vector::get_x() const
{
    return x;
}
double vector::get_y() const 
{
    return y;
}

double vector::length() const 
{
    return sqrt(x*x+y*y);
}

double vector::angle(const vector &v) const 
{
    return acos((*this *v)/length()/v.length());
}

void vector::normalize() 
{
    double len = length();
    if (len != 0.0){
        x/=len;
        y/=len;
    }
}

bool operator==(const vector &v1, const vector &v2)
{
    return v1.get_x()== v2.get_x() && v1.get_y()==v2.get_y();
}
bool operator!=(const vector &v1, const vector &v2)
{
    return !(v1==v2);
}
bool operator<(const vector &v1, const vector &v2)
{
    return v1.length()<v2.length();
}
bool operator>(const vector &v1, const vector &v2)
{
    return v1.length()>v2.length();
}

vector operator+(const vector &v1, const vector &v2)
{
    return vector(v1.get_x()+v2.get_x(), v1.get_y()+v2.get_y());
}
vector operator-(const vector &v1, const vector &v2)
{
    return vector(v1.get_x()-v2.get_x(), v1.get_y()-v2.get_y());
}
vector operator*(const vector &v, double k)
{
    return vector(v.get_x()*k,v.get_y()*k);
}
vector operator/(const vector &v, double k)
{
    return vector(v.get_x()/k,v.get_y()/k);
}
double operator*(const vector &v1, const vector &v2)
{
    return v1.get_x()*v2.get_x()+v1.get_y()*v2.get_y();
}

std::ostream &operator<<(std::ostream &os, const vector &v)
{
    os<<"( "<<v.get_x()<<" , "<<v.get_y()<<" )";
    return os;
}

std::istream &operator>>(std::istream &is, vector &v)
{
    is>>v.x>>v.y;
    return is;
}