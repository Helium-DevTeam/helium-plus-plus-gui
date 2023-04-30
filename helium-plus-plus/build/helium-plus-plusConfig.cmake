include(CMakeFindDependencyMacro)
include("${CMAKE_CURRENT_LIST_DIR}/helium-plus-plus.cmake")

get_filename_component(HELIUM-PLUS-PLUS_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(HELIUM-PLUS-PLUS_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

find_dependency(xtd REQUIRED)

set(HELIUM-PLUS-PLUS_LIBRARIES helium-plus-plus xtd.core )
set(HELIUM-PLUS-PLUS_FOUND TRUE)
