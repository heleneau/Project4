cmake_minimum_required (VERSION 3.0)
project (Ising-Model)

option(USE_OPENMP "Wether to use OpenMP or not" yes)

set(headers
    "${PROJECT_SOURCE_DIR}/functions.h" )
set(sources
    "${PROJECT_SOURCE_DIR}/functions.cpp"
    "${PROJECT_SOURCE_DIR}/main.cpp" )

find_package(Armadillo REQUIRED)
if(USE_OPENMP)
    find_package(OpenMP)
endif(USE_OPENMP)

include_directories(${ARMADILLO_INCLUDE_DIRS})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
if(USE_OPENMP)
    if(${OPENMP_FOUND})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS} -DUSING_OPENMP_YES")
    endif(${OPENMP_FOUND})
endif(USE_OPENMP)

add_executable(${CMAKE_PROJECT_NAME} "${headers}" "${sources}")
target_link_libraries(Ising-Model ${ARMADILLO_LIBRARIES})
