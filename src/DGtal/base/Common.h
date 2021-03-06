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
 * @file Common.h
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5807), University of Savoie, France
 * @author David Coeurjolly (\c david.coeurjolly@liris.cnrs.fr )
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 * 
 * @date 2009/12/10
 * 
 * Header file for module Common.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(Common_RECURSES)
#error Recursive header files inclusion detected in Common.h
#else // defined(Common_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Common_RECURSES

#if !defined Common_h
#define Common_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions

#ifdef WITH_VISU3D_QGLVIEWER
#include <QGLViewer/qglviewer.h>
#include <QGLWidget>
#include <QKeyEvent>
#endif
 
#include <iostream>
#include <exception>
#include <boost/concept_check.hpp>
#include <boost/static_assert.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept/requires.hpp>
#include <boost/iterator/iterator_concepts.hpp>

#if ( (defined(WIN32)) )
#define _USE_MATH_DEFINES
#endif //win32
#include <cmath>

#if defined( WIN32 )
#define secured_sprintf sprintf_s
#else
#define secured_sprintf snprintf
#endif // defined( WIN32 )

#include "DGtal/base/Config.h"
#include "DGtal/base/Trace.h"
#include "DGtal/base/TraceWriterTerm.h"
#include "DGtal/base/TraceWriterFile.h"
#include "DGtal/base/Assert.h"
#include "DGtal/base/ConceptUtils.h"
#include "DGtal/base/BasicTypes.h"
#include "DGtal/base/BasicFunctors.h"
#include "DGtal/base/GlobalFunctions.h"
#include "DGtal/base/Exceptions.h"


//////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////// 
namespace DGtal 
{
  
  /**
   * Global static type to represent the dimension in DGtal
   */
  typedef DGtal::uint32_t Dimension;

  /** DGtal Global variables
   *
   **/
  extern TraceWriterTerm traceWriterTerm;
  extern Trace trace;

  class Board2D;




  class Display3D;
  /**
   * Interface that specifies that an object can draw itself on a
   *  3DDisplay
   * (BK)
   */
  struct DrawableWithDisplay3D {
    /**
     * Operation to override. Does nothing by default.
     *
     * @param display3D any object of type Display3D.
     */
    virtual void selfDraw( Display3D &  ) const {}
  };

  
  

  /**
   * Interface that specifies that an object can draw itself on a
   * board. 
   * @todo (JOL) Put this class elsewhere.
   */
  struct DrawableWithBoard2D {
    /**
     * Operation to override. Does nothing by default.
     *
     * @param board any object of type Board.
     */
    virtual void selfDraw( Board2D &  ) const {}
  };
  
} // namespace DGtal


//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined Common_h

#undef Common_RECURSES
#endif // else defined(Common_RECURSES)
