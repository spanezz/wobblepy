#include "core.h"
#include "methods.h"

namespace {

struct run_internal_tests : public wobblepy::MethNoargs<run_internal_tests, PyObject>
{
    constexpr static const char* name = "run_internal_tests";
    constexpr static const char* signature = "";
    constexpr static const char* returns = "None";
    constexpr static const char* summary = "run internal wobblepy tests";
    constexpr static const char* doc = nullptr;

    static PyObject* run(Impl* self)
    {
        Py_RETURN_NONE;
    }
};

wobblepy::Methods<run_internal_tests> methods;

}


extern "C" {

static PyModuleDef wobblepy_module = {
    PyModuleDef_HEAD_INIT,
    "wobblepy",       /* m_name */
    "Test module for wobblepy.",  /* m_doc */
    -1,                /* m_size */
    methods.as_py(),  /* m_methods */
    NULL,              /* m_slots */
    NULL,              /* m_traverse */
    NULL,              /* m_clear */
    NULL,              /* m_free */
};

PyMODINIT_FUNC PyInit_wobblepy(void)
{
    using namespace wobblepy;

    PyObject* m = PyModule_Create(&wobblepy_module);
    if (!m) return m;

    return m;
}

}
