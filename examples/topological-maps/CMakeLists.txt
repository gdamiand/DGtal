SET(DGTAL_EXAMPLES_SRC
  buildTopologicalMap
)

include_directories (${CMAKE_SOURCE_DIR}/src/DGtal/topological-maps/)


FOREACH(FILE ${DGTAL_EXAMPLES_SRC})
  add_executable(${FILE} ${FILE})
  target_link_libraries (${FILE} ${LIBDGTAL_NAME})
ENDFOREACH(FILE)

