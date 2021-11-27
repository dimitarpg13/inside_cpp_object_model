#include <ostream>
#include <iostream>
#include <assert.h>

template <class T, int dim>
class Point
{
    public:
        Point();
        Point( T coords[ dim ] ) {
           for ( int index = 0; index < dim; index++ )
               _coords[ index ] = coords[ index ];
        }

        T& operator[] ( int index ) {
          assert ( index < dim && index >= 0 );
          return _coords[ index ]; 
        }

        T operator[] ( int index ) const {
          assert ( index < dim && index >= 0 );
          return _coords[ index ];
        }

    private:
        T _coords[ dim ];

};

template <class T, int dim>
inline std::ostream& operator<<( std::ostream &os, const Point<T, dim>& pt )
{
    os << "( ";
    for ( int ix = 0; ix < dim-1; ix++ )
        os << pt[ ix ] << ", ";
    os << pt[ dim-1 ];
    os << " )";
};

int main(const int argc, const char* argv[]) {


    return 0;
}
