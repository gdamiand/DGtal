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

/**
 * @file buildTopologicalMap.cpp
 * @ingroup Examples
 * @author Guillaume Damiand
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @date 2011/09/01
 *
 * An example file named buildTopologicalMap.
 *
 * This file is part of the DGtal library.
 */

///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "DGtal/base/Common.h"
#include "DGtal/kernel/SpaceND.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/kernel/domains/HyperRectDomain.h"
#include <DGtal/topological-maps/Topological_map.h>

int main(int argc, char** argv)
{
  if (argc!=2)
    {
      std::cout<<"usage: a.out filename\n"
	       <<"  to extract the 3D topological map of the 3D image named filename."
	       <<std::endl;
      return EXIT_FAILURE;
    }
  
  trace.beginBlock ( "Example buildTopologicalMap" );
  typedef DGtal::Z3i::Space MySpace;
  typedef HyperRectDomain<MySpace> MyDomain;
  
  CTopologicalMap topoMap;

  /*  if ( topoMap.extractTopologicalMap(argv[1]) )
    {
      std::cout<<"Topological map extracted from"
	       <<argv[1]<<"."<<std::endl;
    }
  else
    {
      std::cout<<"Problem during the extraction of the topological map from "
	       <<argv[1]<<"."<<std::endl;
    }*/
  
  trace.endBlock();
  return EXIT_SUCCESS;
}
