# wobblepy utility code repository

wobblepy is a repository of utility code to be included in other projects.

The repository has these rules:

 - all code is unit tested
 - all header files are thoroughly documented
 - it must be possible to perform a simple search and replace of the strings
   'WOBBLEPY' and 'wobblepy', so that the code can be deployed to fit as part
   of another library.
 - APIs are stable. Also ABIs, whenever possible.
 - code only depends on C++17 standard library features and the Python 3 C API
 - it must be easier to maintain wobblepy code than it is to manage
   dependencies on an ecosystem of libraries that provide the same funtionality

wobblepy does not build into a library: you just take the bits you need and use
them in your sources. Since the API is stable, you can occasionally refresh
your sources just by copying. Please contribute your fixes to wobblepy code
back to wobblepy, with unit tests.

Note that wobblepy defines `PY_SSIZE_T_CLEAN` before importing `Python.h`,
which may break existing python code that does not, when mixed with wobblepy.:
see <https://bugs.python.org/issue37465> for details.

To run wobblepy's unit tests:

```shell
mkdir build
cd build
# You can use "ccmake .." instead of "cmake .." to get an interactive
# interface for selecting configuration parameters.
cmake ..
make
make check
```
