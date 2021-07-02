#include <ostream>
#include <iostream>

class Point {
    public:
        Point( float x = 0.0 ) : _x( x ) {}

        float x() const { return _x; }
        void x( float xval ) { _x = xval; }
    protected:
        float _x;
};

class Point2d : public Point {
    public:
        Point2d( float x = 0.0, float y = 0.0 )
            : Point( x ), _y( y ) {}

        float y() const { return _y; }
        void y( float yval ) { _y = yval; }

    protected:
        float _y;
};

class Point3d : public Point2d {
    public:
        Point3d( float x = 0.0, float y = 0.0, float z = 0.0 )
            :  Point2d( x, y ), _z( z ) {}

        float z() const { return _z; }
        void z( float zval ) { _z = zval; }

    protected:
        float _z;
};

inline std::ostream& operator<<( std::ostream &os, const Point3d& pt )
{
   os << "( " << pt.x() << ", " << pt.y() << ", " << pt.z() << " )"; 
};

int main(const int argc, const char* argv[]) {


    return 0;
}
