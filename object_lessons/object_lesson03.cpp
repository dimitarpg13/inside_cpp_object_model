#include <ostream>
#include <iostream>

template <class T>
class Point3d 
{
    public:
        Point3d ( T x = 0.0, T y = 0.0, T z = 0.0 ) :
            _x( x ), _y( y ), _z( z ) {}

        T x() const { return _x; }
        T y() const { return _y; }
        T z() const { return _z; }

        void x( T xval ) { _x = xval; }
        void y( T yval ) { _y = yval; }
        void z( T zval ) { _z = zval; }

    private:
        T _x;
        T _y;
        T _z;
};

template <class T>
inline std::ostream& operator<<( std::ostream &os, const Point3d<T>& pt )
{
   os << "( " << pt.x() << ", " << pt.y() << ", " << pt.z() << " )"; 
};

int main(const int argc, const char* argv[]) {


    return 0;
}
