#include "core.h"

namespace wobblepy {

const char* PythonException::what() const noexcept
{
    AcquireGIL gil;
    // TODO: use PyErr_FormatUnraisable from Python 3.13
    fprintf(stderr, "Python exception caught from C++\n");
    PyErr_WriteUnraisable(nullptr);
    return "Python exception caught from C++";
}

} // namespace wobblepy
