#include "core.h"

extern "C" {

static PyMethodDef wobblepy_methods[] = {
    { nullptr, nullptr, 0, nullptr }
};

static PyModuleDef wobblepy_module = {
    PyModuleDef_HEAD_INIT,
    "wobblepy",       /* m_name */
    "Test module for wobblepy.",  /* m_doc */
    -1,                /* m_size */
    wobblepy_methods,  /* m_methods */
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
