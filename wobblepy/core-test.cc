#include "core.h"
#include "methods.h"
#include "type.h"

extern "C" {

typedef struct {
    PyObject_HEAD
} TestObject;

PyTypeObject* TestObject_Type;

}

namespace {

struct Definition : public wobblepy::Type<Definition, TestObject>
{
    constexpr static const char* name = "TestObject";
    constexpr static const char* qual_name = "wobblepy.TestObject";
    constexpr static const char* doc = R"(
Test object for wobblepy python helpers
)";
    wobblepy::GetSetters<> getsetters;
    wobblepy::Methods<> methods;

    static void _dealloc(Impl* self)
    {
        Py_TYPE(self)->tp_free(self);
    }

    static PyObject* _str(Impl* self)
    {
        return PyUnicode_FromString("TestObject");
    }

    static PyObject* _repr(Impl* self)
    {
        return PyUnicode_FromString("TestObject object");
    }

    static int _init(Impl* self, PyObject* args, PyObject* kw)
    {
        static const char* kwlist[] = { nullptr };
        if (!PyArg_ParseTupleAndKeywords(args, kw, "", const_cast<char**>(kwlist)))
            return -1;
        return 0;
    }
};

Definition* definition = nullptr;


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

    definition = new Definition;
    definition->define(TestObject_Type, m);

    return m;
}

}
