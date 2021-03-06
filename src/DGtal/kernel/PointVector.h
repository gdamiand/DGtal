/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#pragma once

/**
 * @file PointVector.h
 * @author David Coeurjolly (@c david.coeurjolly@liris.cnrs.fr )
 * @author Guillaume Damiand
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5807), University of Savoie, France
 *
 * @date 2010/05/14
 *
 *
 * This file is part of the DGtal library.
 */

#if defined(PointVector_RECURSES)
#error Recursive header files inclusion detected in PointVector.h
#else // defined(PointVector_RECURSES)
/** Prevents recursive inclusion of headers. */
#define PointVector_RECURSES

#if !defined PointVector_h
/** Prevents repeated inclusion of headers. */
#define PointVector_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
#include <boost/array.hpp>

#include "DGtal/base/Common.h"
#include "DGtal/base/BasicTypes.h"
#include "DGtal/kernel/NumberTraits.h"
#include "DGtal/io/boards/Board2D.h"
#include "DGtal/io/Color.h"
#include "DGtal/kernel/CCommutativeRing.h"

#include "DGtal/io/Display3D.h"




//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{
  /// @return a bitset having true for each dimension presents in dimensions.
  template<Dimension dim, typename Container>
  std::bitset<dim> setDimensionsIn( const Container &dimensions );

  /// @return a bitset having true for each dimension not presents in dimensions.
  template<Dimension dim, typename Container>
  std::bitset<dim> setDimensionsNotIn( const Container &dimensions );

  /////////////////////////////////////////////////////////////////////////////
  // class PointVector
  /**
   * Description of class 'PointVector' <p>
   *
   * @brief Aim: Implements basic operations that will be used in 
   * Point and  Vector classes.
   *
   * A PointVector may represent either a symbolic point or a symbolic
   * vector depending on the context. The coordinates of the point or
   * the components of the vector should be part of a ring. For
   * performance reasons, these two types are just aliases. The user
   * should take care how to use it depending on the context. For
   * instance, adding two points has no meaning, but will be
   * authorized by the compiler.
   *
   * @tparam dim static constant of type DGtal::uint32_t that
   * specifies the static  dimension of the space and thus the number
   * of elements  of the Point or Vector.
   * @tparam Ring speficies the ring number type used as
   * type of PointVector elements (Coordinate for Point and Component
   * for Vector).
   *
   * The default less than operator is the one of the lexicographic
   * ordering, starting from dimension 0 to N-1.
   *
   * PointVector also realizes the concept CLattice with an infimum
   * (meet, greatest lower bound) and a supremum (join, least upper
   * bound) operation.
   *
   * Usage example:
   * @code
   *
   * ...
   * typedef PointVector<5, int> VectorD5;
   * VectorD5 p, q, r;
   *
   * p.at(1) = 2;  // p = {0, 2, 0, 0, 0}
   * q.at(3) = -5   // q = {0, 0, 0, -5, 0}
   * r =  p + q ;   //  r = {0, 2, 0, -5, 0}
   *
   * ...
   * @endcode
   *
   * @see testPointVector.cpp

   * @tparam dim the dimension of the space (i.e. the number of components or of coordinates)
   * @tparam TComponent the ring used to specify the arithmetic computations (default type = int).
   *
   */
  template < DGtal::Dimension dim, typename TComponent >
  class PointVector
  {
    // ----------------------- Standard services ------------------------------
  public:

    typedef TComponent Component;

    //Ring must be a model of the concept CRing.
    BOOST_CONCEPT_ASSERT(( CCommutativeRing<Component> ) );

    typedef PointVector<dim, Component> Self;
    typedef Component Coordinate;

    // JOL need it in various norm().
    typedef typename NumberTraits<Component>::UnsignedVersion UnsignedComponent;
    
    ///Copy of the dimension type
    typedef DGtal::Dimension Dimension;

    ///Copy of the static dimension of the Point/Vector.
    static const Dimension dimension = dim;

    /**
     *  Copy of the Boost::array iterator type
     *
     **/
    typedef typename boost::array<Component, dimension>::iterator Iterator;
    typedef typename boost::array<Component, dimension>::const_iterator ConstIterator;
    
    /**
     * Constructor.
     */
    PointVector();

    /**
     * Constructor from array of values.
     *
     * @param ptrValues the array of values.
     */
    explicit PointVector( const Component* ptrValues );

    /**
     * Constructor from two values (the Dimension of the vector should
     * be at least 2). Other components are set to 0.
     *
     * @param x the first value.
     * @param y the second value.
     */
    PointVector( const Component & x, const Component & y );

    /**
     * Constructor from three values (the Dimension of the vector should
     * be at least 3). Other components are set to 0.
     *
     * @param x the first value.
     * @param y the second value.
     * @param z the third value.
     */
    PointVector( const Component & x, const Component & y, const Component & z );

    /**
     * Constructor from four values (the Dimension of the vector should
     * be at least 4). Other components are set to 0.
     *
     * @param x the first value.
     * @param y the second value.
     * @param z the third value.
     * @param t the fourth value.
     */
    PointVector( const Component & x, const Component & y, const Component & z, const Component & t );

#ifdef CPP0X_INITIALIZER_LIST
    /**
     * Constructor from initializer list.
     * @param the initializer list.
     */
    PointVector( std::initializer_list<Component> init );
#endif // CPP0X_INITIALIZER_LIST

    /** Constructor taking apoint and a functor as parameters.
     *  The new point is initialized by the result of functor f
     *  for each coordinate of apoint1 and apoint2
     */
    template<typename Functor>
    PointVector( const Self& apoint1, const Self& apoint2,
     const Functor& f );

    /**
     * Destructor.
     */
    ~PointVector();

    // ----------------------- Iterator services ------------------------------
  public:
    /**
     * Copy constructor.
     * @param other the object to clone.
     */
    PointVector( const Self & other );

    /**
     * Assignement Operator
     *
     * @param other the object to copy.
     * @return a reference on 'this'.
     */
    Self & operator= ( const Self & pv );


#ifdef CPP0X_INITIALIZER_LIST
    /**
     * Partial copy of a given PointVector. Only coordinates in dimensions
     * are copied.
     *
     * @param other the object to copy.
     * @param dim the dimensions of v to copy
     *        (Size between 0 and N, all differents).
     * @return a reference on 'this'.
     */
    Self& partialCopy (const Self & pv,
           std::initializer_list<Dimension> dimensions);

    /**
     * Inverse partial copy of a given PointVector. Only coordinates not 
     * in dimensions are copied.
     *
     * @param other the object to copy.
     * @param dim the dimensions of v to copy
     *        (Size between 0 and N, all differents).
     * @return a reference on 'this'.
     */
    Self& partialCopyInv (const Self & pv,
        std::initializer_list<Dimension> dimensions);
#endif
    /**
     * Partial copy of a given PointVector. Only coordinates in dimensions
     * are copied.
     *
     * @param other the object to copy.
     * @param dim the dimensions of v to copy
     *        (Size between 0 and N, all differents).
     * @return a reference on 'this'.
     */
    Self& partialCopy (const Self & pv,
           const std::vector<Dimension> &dimensions);

    /**
     * Partial copy of a given PointVector. Only coordinates not 
     * in dimensions are copied.
     *
     * @param other the object to copy.
     * @param dim the dimensions of v to copy
     *        (Size between 0 and N, all differents).
     * @return a reference on 'this'.
     */
    Self& partialCopyInv (const Self & pv,
        const std::vector<Dimension> &dimensions);

    /**
     * Partial equality.
     *
     * @param pv Point/Vector to compare to this.
     *
     * @return true iff points are equal for given dimensions .
     */
    bool partialEqual ( const Self & pv,
      const std::vector<Dimension> &dimensions )  const;

    /**
     * Partial inverse equality.
     *
     * @param pv Point/Vector to compare to this.
     *
     * @return true iff points are equal for dimensions not in dimensions.
     */
    bool partialEqualInv ( const Self & pv,
         const std::vector<Dimension> &dimensions )  const;
    
    // ----------------------- Iterator services ------------------------------
  public:
    /**
     * PointVector begin() iterator.
     *
     * @return an Iterator on the first element of a Point/Vector.
     **/
    Iterator begin();

    /**
     * PointVector end() iterator.
     *
     * @return an Iterator on the last element of a Point/Vector.
     **/
    Iterator end();

    /**
     * PointVector begin() const iterator.
     *
     * @return an ConstIterator on the first element of a Point/Vector.
     **/
    ConstIterator begin() const;

    /**
     * PointVector end() const iterator.
     *
     * @return a ConstIterator on the last element of a Point/Vector.
     **/
    ConstIterator end() const;

    // ----------------------- Array services ------------------------------
  public:
    /**
     * Returns the size of the vector (i.e. the number of its
     * coefficients).
     * Same as getDimension
     */
    static Dimension size();

    /**
     * Returns the  @a i-th coefficient of the vector.
     *
     * @pre The @a i index must lie between @a 0 and @a size() .
     *
     * @param i is the index of the retrieved coefficient.
     */
    const Component& at( Dimension i ) const;

    /**
     * Returns a non-const reference to the @a i-th element of the
     * vector.
     *
     * @pre The @a i index must lie between @a 0 and @a size() .
     *
     * @param i is the index of the retrieved coefficient.
     */
    Component& at( Dimension i );

    /**
     * Returns the  @a i-th coefficient of the vector.
     *
     * @pre The @a i index must lie between @a 0 and @a size() .
     *
     * @param i is the index of the retrieved coefficient.
     */
    const Component& operator[]( Dimension i ) const;

    /**
     * Returns a non-const reference to the @a i-th element of the
     * vector.
     *
     * @pre The @a i index must lie between @a 0 and @a size() .
     *
     * @param i is the index of the retrieved coefficient.
     */
    Component& operator[](Dimension i );

    // ----------------------- Comparison operations --------------------------
  public:
    /**
     * Equality operator.
     *
     * @param pv Point/Vector to compare to this.
     *
     * @return true iff points are equal.
     */
    bool operator== ( const Self & pv ) const;

    /**
     * Difference operator on Points/Vectors.
     *
     * @param pv the Point/Vector to compare to this.
     *
     * @return true iff this differs from pv, false otherwise.
     */
    bool operator!= ( const Self & pv ) const;

    /**
     * Comparison operator on Points/Vectors (LesserThan).
     *
     * @param pv the Point/Vector to compare to this.
     *
     * @return true iff this < pv, false otherwise.
     */
    bool operator< ( const Self & pv ) const;

    /**
     * Comparison operator on Points/Vectors (LesserOrEqualThan).
     *
     * @param pv the Point/Vector to compare to this.
     *
     * @return true iff this <= pv, false otherwise.
     */
    bool operator<= ( const Self & pv ) const;

    /**
     * Comparison operator on Points/Vectors (GreaterThan).
     *
     * @param pv the Point/Vector to compare to this.
     *
     * @return true iff this > pv, false otherwise.
     */
    bool operator> ( const Self & pv ) const;
    
    /**
     * Comparison operator on Points/Vectors (GreaterOrEqualThan).
     *
     * @param pv the Point/Vector to compare to this.
     *
     * @return true iff this >= pv, false otherwise.
     */
    bool operator>= ( const Self & pv ) const;

    // ----------------------- Operations ------------------------------
  public:
    /**
     * Multiplies @a *this by the @a coeff scalar number.
     *
     * @param coeff is the factor @a *this get multiplied by.
     * @return a reference on 'this'.
     */
    PointVector & operator*= ( Component coeff );

    /**
     * Multiplication operator with a scalar number
     *
     * @param coeff is the factor 'this' is multiplied by.
     * @return a new Point that is the multiplication of 'this' by coeff.
     */
    PointVector operator*( Component coeff );
    
    /**
     * dot product with a PointVector
     *
     * @param v a vector that is dot-producted to *this.
     * @return the dot product of this and v.
     */
    Component dot( const Self &v);

    /**
     * Addition operator with assignement.
     *
     * @param v is the Point that gets added to @a *this.
     * @return a reference on 'this'.
     */
    Self & operator+= ( const Self & v );

    /**
     * Addition operator.
     *
     * @param v is the Point that gets added to @a *this.
     * @return a new Point that is the addition of 'this' to [v].
     */
    Self operator+ ( const Self & v ) const;

    /**
     * Substraction operator with assignement.
     *
     * @param v is the Point that gets substracted to  *this.
     * @return a reference on 'this'.
     */
    Self & operator-= ( const Self & v );

    /**
     * Substraction operator.
     * Point - Vector => Point
     *
     * @param v is the Point that gets added to @a *this.
     * @return a new Point that is the subtraction 'this'-[v].
     */
    Self operator- ( const Self & v ) const;

    /**
     * Resets all the values to zero.
     */
    void reset();

    /**
     * Implements the infimum (or greatest lower bound). It means the
     * point whose coordinates are exactly the minimum of the two
     * points coordinate by coordinate.
     *
     * @param apoint any point.
     * @return a new point being the inf between *this and apoint.
     * @see isLower
     */
    Self inf( const Self& apoint ) const;

    /**
     * Implements the supremum (or least upper bound). It means the
     * point whose coordinates are exactly the maximum of the two
     * points coordinate by coordinate.
     *
     * @param apoint any point.
     * @return a new point being the sup between *this and apoint.
     * @see isUpper
     */
    Self sup( const Self& apoint ) const;

    /**
     * @param p any point.
     * @return true if this is below p (ie. this==inf(this,p))
     * NB: faster than computing the infimum and compare it afterwards.
     */
    bool isLower( const Self& p ) const;

    /**
     * @param p any point.
     * @return true if this is upper p (ie. this==sup(this,p))
     * NB: faster than computing the supremum and compare it afterwards.
     */
    bool isUpper( const Self& p ) const;

    /** 
     * Return the maximum component value of a point/vector.
     * 
     * @return the maximum value.
     */
    Component max() const;
   
    /** 
     * Return the minimum component value of a point/vector.
     * 
     * @return the minimum value.
     */ 
    Component min() const;

    /** 
     * Return the iterator on the component with maximim value of a
     * point/vector.
     * 
     * @return an iterator.
     */
    Iterator maxElement();
   
    /** 
     * Return the iterator on the component with minimum value of a
     * point/vector.
     * 
     * @return an iterator.
     */ 
    Iterator minElement();


    /**
     * Specify the set of norm types
     *
     */
    enum NormType { L_2, L_1, L_infty };

    /**
     * Computes the norm of a point/vector.
     * \warning This method performs a conversion
     * from the type T to double for each components to compute the
     * norms. For exact norms (restricted to L_1 and L_infinity
     * norms), please refer to PointVector::norm1 and PointVector::normInfinity. 
     *
     * @param type specifies the type of norm to consider (see @ref NormType).
     * @return the norm of the point/vector as a double.
     */
    double norm( const NormType type = L_2 ) const;

    /**
     * Computes the 1-norm of a vector.
     *
     * @return the absolute sum of the components of this vector.
     */
    UnsignedComponent norm1() const;

    /**
     * Computes the infinity-norm of a vector.
     *
     * @return the maximum absolute value of the components of this vector.
     */
    UnsignedComponent normInfinity() const;

    // ------------------------- Standard vectors ------------------------------
  public:

    /**
     * @param val any value.
     * @return the diagonal vector (val,val, .. val).
     */
    static Self diagonal( Component val = 1 );

    /**
     * @param k any number between 0 and Dimension-1.
     * @param val any value.
     * @return the [k]-th base vector (0,0, ..., 0, val, 0, ..., 0).
     */
    static Self base( Dimension k, Component val = 1 );

    // ------------------------- Private Datas -------------------------------
  private:

    /**
     * Default styles.
     */
    struct DefaultDrawStylePaving : public DrawableWithBoard2D
    {
      virtual void selfDraw( Board2D & aBoard ) const
      {
  aBoard.setPenColorRGBi(160,160,160);
  aBoard.setLineStyle( Board2D::Shape::SolidStyle );
  aBoard.setFillColorRGBi(220,220,220);
  aBoard.setLineWidth(1);
      }
    };

    
    struct DefaultDrawStyleGrid : public DrawableWithBoard2D
    {
      virtual void selfDraw( Board2D & aBoard ) const
      {
  aBoard.setPenColor(Color::Black);
  aBoard.setLineStyle( Board2D::Shape::SolidStyle );
      }
    };



    // --------------- CDrawableWithBoard2D realization -------------------
  public:

    /**
     * Default drawing style object.
     * @return the dyn. alloc. default style for this object.
     */
    DrawableWithBoard2D* defaultStyle( std::string mode = "" ) const;


    
    /**
     * @return the style name used for drawing this object.
     */
    std::string styleName() const;
    
    /**
     * Draw the object on a Board2D board.
     * @param board the output board where the object is drawn.
     */
    void selfDraw( Board2D & board ) const;

    
    /**
     * Draw a pixel as a unit square on a Board2D board.
     * @param board the output board where the object is drawn.
     */
    
    void selfDrawAsPaving( Board2D & board ) const;
    
    
    /**
     * Draw a pixel as a point on a LiBoard board
     * @param board the output board where the object is drawn.
     */
    void selfDrawAsGrid( Board2D & board ) const;
    
    



    /**
     * Default drawing style object.
     * @return the dyn. alloc. default style for this object.
     */
    DrawableWithDisplay3D* defaultStyleDisplay3D( std::string mode = "" ) const;

    /**
     * Draw the object on a Board2D board.
     * @param board the output board where the object is drawn.
     */
    void selfDrawDisplay3D ( Display3D & display ) const;
    void selfDrawDisplay3D ( Display3D & display, const Self &startingPoint ) const;
    void selfDrawAsGridDisplay3D( Display3D & display  ) const;
    void selfDrawAsPavingDisplay3D( Display3D & display ) const;
    void selfDrawAsPavingWiredDisplay3D( Display3D & display ) const;


    
    // ----------------------- Interface --------------------------------------
  public:
    /**
     * Draw the object (as a Vector from aPoint) on a Board2D board
     *
     * @param board the output board where the object is drawn.
     * @param startingPoint the starting point of the vector
     * @tparam Functor a Functor to specialize the Board style
     */
    void selfDraw( Board2D & board, const Self &startingPoint ) const;

    /**
     * Writes/Displays the object on an output stream.
     * @param out the output stream where the object is written.
     */
    void selfDisplay( std::ostream & out ) const;

    /**
     * Checks the validity/consistency of the object.
     * @return 'true' if the object is valid, 'false' otherwise.
     */
    bool isValid() const;

    /// Static const for zero PointVector.
    static Self zero;
    
    // ------------------------- Hidden services ------------------------------
  protected:
    
    ///Internal data-structure: boost/array with constant size.
    boost::array<Component, dimension> myArray;
    
  }; // end of class PointVector

  
  /**
   * Modifier class in a Board2D stream. Realizes the concept
   * CDrawableWithBoard2D.
   */
  struct DrawPavingPixel : public DrawWithBoardModifier {
    void selfDraw( Board2D & board ) const
    {
      board.myModes[ "PointVector" ] = "Paving";
    }
  };
  
  /**
   * Modifier class in a Board2D stream. Realizes the concept
   * CDrawableWithBoard2D.
   */
  struct DrawGridPixel : public DrawWithBoardModifier {
    void selfDraw( Board2D & board ) const
    {
      board.myModes[ "PointVector" ] = "Grid";
    }
  };




  /**
   * Modifier class in a Board2D stream. Realizes the concept
   * CDrawableWithBoard2D.
   */



  struct DrawPavingVoxel : public DrawableWithDisplay3D {
      void selfDrawDisplay3D( Display3D & viewer ) const
      {
  viewer.myModes[ "PointVector" ] = "Paving";
      }
  };
  
  
  struct DrawGridVoxel : public DrawableWithDisplay3D {
    void selfDrawDisplay3D( Display3D & viewer ) const
    {
      viewer.myModes[ "PointVector" ] = "Grid";
    }
  };

 

  /// Operator <<
  template<Dimension dim, typename Component>
  std::ostream&
  operator<<( std::ostream & out, const PointVector<dim, Component> & object );

  template< Dimension dim, typename Component>
  PointVector<dim, Component>  PointVector<dim, Component>::zero;
} // namespace DGtal

///////////////////////////////////////////////////////////////////////////////
// Includes inline functions
#include "DGtal/kernel/PointVector.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined PointVector_h

#undef PointVector_RECURSES
#endif // else defined(PointVector_RECURSES)
