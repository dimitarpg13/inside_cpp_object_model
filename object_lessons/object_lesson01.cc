#include <cstdio>
#include <stdlib.h>

typedef struct point3d
{
    float x;
    float y;
    float z;
} Point3d;

void Point3d_print( const Point3d *pd )
{
   printf(" ( %g, %g, %g )", pd->x, pd->y, pd->z );
}

#define Point3d_print( pd ) \
    printf("( %g, %g, %g )", pd->x, pd->y, pd->z );

#define X( p, xval ) (p.x) = (xval);
#define Y( p, yval ) (p.y) = (yval);
#define Z( p, zval ) (p.z) = (zval);

Point3d * get_a_point(void) 
{
   Point3d * p = (Point3d *) malloc(sizeof(Point3d));
   p->x = 1.0f;
   p->y = 2.0f;
   p->z = 3.0f;
   return p;
}

void free_point(Point3d * p)
{
   free(p);
}

void my_foo() 
{
   Point3d *pd = get_a_point();
   /* print the point directly */
   printf(" ( %g, %g, %g )", pd->x, pd->y, pd->z );
   free_point(pd);
}

int main(const int argc, const char* argv[]) 
{
    my_foo();
    return 0;
}
