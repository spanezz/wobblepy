project(wobblepy)

find_package(Python3 COMPONENTS Interpreter Development)

add_definitions(--std=c++11 -Wall -Werror)

# glob through source files/headers
file(GLOB WOBBLEPY_HEADERS *.h)
file(GLOB WOBBLEPY_SOURCES *.cc)

include_directories(${wobblepy_SOURCE_DIR}/.. ${wobblepy_BINARY_DIR}/.. ${Python3_INCLUDE_DIRS})
add_definitions(${OPT_FLAGS})

Python3_add_library(wobblepy MODULE ${WOBBLEPY_SOURCES})

configure_file(wobblepy-test.py wobblepy-test.py COPYONLY)

add_test(wobblepy-test wobblepy-test.py)


# add_executable(wobblepy-test ${WOBBLEPY_SOURCES})
# target_link_libraries(wobblepy-test ${Python3_LIBRARIES})

# add_dependencies(check wobblepy-test)
