#include <ostream>
#include <iostream>

class Point3d 
{
    public:
        Point3d ( float x = 0.0, float y = 0.0, float z = 0.0 ) :
            _x( x ), _y( y ), _z( z ) {}

        float x() const { return _x; }
        float y() const { return _y; }
        float z() const { return _z; }

        void x( float xval ) { _x = xval; }
        void y( float yval ) { _y = yval; }
        void z( float zval ) { _z = zval; }

    private:
        float _x;
        float _y;
        float _z;
};

inline std::ostream& operator<<( std::ostream &os, const Point3d& pt )
{
   os << "( " << pt.x() << ", " << pt.y() << ", " << pt.z() << " )"; 
};

int main(const int argc, const char* argv[]) {


    return 0;
}
