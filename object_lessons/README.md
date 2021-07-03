Layout Costs for Adding Encapsulation

An obvious question a programmer might ask while looking at the transformed Point3d implementations
under C++ concerns the layout costs for adding encapsulation. The answer is that there are no
additional layout costs for supporting the class Point3d. The three coordinate data members are
directly contained within each class object, as they are in the C struct. The member functions, 
although included in the class declaration, are not reflected in the object layout; one copy
only for each non-inline member function is generated. Each inline function has either zero or 
one definition of itself generated within each module in which it is used. The Point3d class
has no space or runtime penalty in supporting encapsulation. As you will see, the primary 
layout and access-time overheads within C++ are associated with the virtuals, that is

* the virtual function mechanism in its support of an efficient run-time binding, and
* a virtual base class in its support of a single instance of a base class occuring
multiple times within the inheritance hierarchy

There is also additional overhead under multiple inheritance in the conversion between derived
class and its second or subsequent base class. In general, however, there is no inherent reason
a program in C++ need be any larger or slower than its equivalent C program.

The C++ Object Model 

In C++ there are two flavors of class data members - static and nonstatic - and three flavors of 
class member functions - static, nonstatic and virtual. Given the following declaration of class
Point:
```cpp
class Point
{
public:
   Point ( float xval );
   virtual ~Point();


   float x() const;
   static int PointCount();

protected:
   virtual ostream&
      print ( ostream &os ) const;

   float _x;
   static int _point_count; 

};
```
how is the class Point to be represented within the machine? That is, how do we model the various 
flavors of data and function members?

A Simple Object Model

<img src="images/object_lessons_pic1.png" width="473" height="324">

In this simple model, the members themselves are not placed within the object. Only pointers
addressing the members are placed within the object. Doing this avoids problems from member's
being quite different types and requiring different amounts (and sometimes different types of)
storage. Members within an object are addressed by their slot's index. For example, ```_x```'s
index is 6 and ```_point_count```'s index is 7. The general size of a class object is the size
of a pointer multiplied by the number of members declared by the class. Although this model is 
not used in practice, this simple concept of an index or slot number is the one that has been
developed into the C++ pointer-to-member concept.

A Table-Driven Object Model

For an implementation to maintain a uniform representation for the objects of all classes, an
alternative object model might factor out all member specific information, placing it in data
member and member function pair of tables. The class object contains the pointers to the two
member tables. The member function table is a sequence of slots with each slot addressing a
member. The data member table directly holds the data. This is shown on the figure below.


Member Table Object Model

<img src="images/object_lessons_pic2.png" width="473" height="324">

Although this model is not used in practice within C++, the concept of a member function table
has been the traditional implementation supporting efficient runtime resolution of virtual 
functions. At least one implementation of the CORBA ORB has used a form of this two table model.
The Simple Object Model also relies on this two table model.

The C++ Object Model

Stroustrup's original (and still prevailing) C++ Object Model is derived from the simple object
model by optimizing for space and access time. Nonstatic data members are allocated directly
within each class object. Static data members are stoed outside the individual class object.
Static and nonstatic function members are hoisted outside the class object. Virtual functions are
supported in two steps:

1. A table of pointers to virtual functions is generated for each class (this is called the virtual 
table).

2. A single pointer to the associated virtual table is inserted within each class object (traditionally
this has been called the vptr). The setting, resetting, and not setting of the vptr is handled 
automatically through code generated within each class constructor, destructor, and copy assignment
operator. The type_info object associated with each class in support of runtime type identification (RTTI)
is also addressed within the virtual table usually within the table's first slot.

The figure below illustrates the general C++ object model for our Point class. The primary strength of 
the C++ object model is its space and running efficiency. Its primary drawback is the need to recompile
unmodified code that makes use of an object of a class for which there has been an addition, removal, 
or modification of the nonstatic class data members. The two table data mode, for example, offers more
flexibility by providing an additional level of indirection. But it does this at the cost of space
and runtime efficiency.

<img src="images/object_lessons_pic3.png" width="587" height="324">

