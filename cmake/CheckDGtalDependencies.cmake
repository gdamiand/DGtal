# -----------------------------------------------------------------------------
# Check Mandatory Dependencies
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Look for boost 
# -----------------------------------------------------------------------------
set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)



FIND_PACKAGE(Boost 1.40.0 REQUIRED COMPONENTS program_options)
if ( Boost_FOUND )
  message(STATUS "Boost and boost_program_options found.")
  include_directories( ${Boost_INCLUDE_DIR} )
   SET(DGtalLibDependencies ${DGtalLibDependencies} 
     ${Boost_LIBRAIRIES}  
     ${Boost_PROGRAM_OPTIONS_LIBRARY})
   SET(DGtalLibInc ${Boost_INCLUDE_DIR})
endif( Boost_FOUND )

