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
 * @file CConstRange.h
 * @author Guillaume Damiand
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @date 2011/08/31
 *
 * Header file for concept CConstRange
 *
 * This file is part of the DGtal library.
 */

#if defined(CConstRange_RECURSES)
#error Recursive header files inclusion detected in CConstRange.h
#else // defined(CConstRange_RECURSES)
/** Prevents recursive inclusion of headers. */
#define CConstRange_RECURSES

#if !defined CConstRange_h
/** Prevents repeated inclusion of headers. */
#define CConstRange_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/base/ConceptUtils.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // class CConstRange
  /**
     Description of \b concept '\b CConstRange' <p>
     @ingroup Concepts
    
     \brief Aim: Defines the concept describing a const range.
     
     <p> Refinement of
    
     <p> Provided types :

     - ConstIterator: the const iterator type, a model of const iterator
          concept.
     - ReverseConstIterator: the const reverse iterator type, a model of
          const iterator concept.

     <table>
     <tr> 
     <td class=CName> \b Name </td> 
     <td class=CExpression> \b Expression </td>
     <td class=CRequirements> \b Type requirements </td> 
     <td class=CReturnType> \b Return type </td>
     <td class=CPrecondition> \b Precondition </td> 
     <td class=CSemantics> \b Semantics </td> 
     <td class=CPostCondition> \b Postcondition </td> 
     <td class=CComplexity> \b Complexity </td>
     </tr>
     <tr> 
     <td class=CName>            \t x should have a begin method. </td>
     <td class=CExpression>      \t x.begin </td> 
     <td class=CRequirements>    static member has type \t Dimension </td>
     <td class=CReturnType>      ConstIterator</td>
     <td class=CPrecondition>    </td> 
     <td class=CSemantics>       </td> 
     <td class=CPostCondition>   </td> 
     <td class=CComplexity>      </td>
     </tr>
     </table>
    
     <p> Invariants <br>
    
     <p> Models <br>
    
     <p> Notes <br>

     @tparam T the type that is checked. T should be a model of CConstRange.

   */
  template <typename T>
  struct CConstRange
  {
    // ----------------------- Concept checks ------------------------------
  public:
    typedef typename T::ConstIterator ConstIterator;
    typedef typename T::ReverseConstIterator ReverseConstIterator;

    BOOST_CONCEPT_ASSERT(( boost_concepts::SinglePassIteratorConcept<ConstIterator> ));
    BOOST_CONCEPT_ASSERT(( boost_concepts::SinglePassIteratorConcept<ReverseConstIterator> ));

    BOOST_CONCEPT_USAGE(CConstRange)
    {
      ConstIterator it=i.begin();
      it=i.end();
      ReverseConstIterator it2=i.rbegin();
      it2=i.rend();
    };

  private:
    T i;
  }; // end of concept CConstRange
  
} // namespace DGtal



//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined CConstRange_h

#undef CConstRange_RECURSES
#endif // else defined(CConstRange_RECURSES)
