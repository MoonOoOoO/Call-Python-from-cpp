#include <iostream>
#include "Python.h"
// #include <boost/python.hpp>

int main()
{
    // Initialize the python instance
    Py_Initialize();

    // Run a simple string
    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is',ctime(time()))\n");

    // Run a simple file
    FILE *PScriptFile = fopen("test.py", "r");
    if (PScriptFile)
    {
        PyRun_SimpleFile(PScriptFile, "test.py");
        fclose(PScriptFile);
    }

    // Run a python function
    PyObject *sysPath, *pName, *pModule, *pFunc, *pArgs, *pValue;

    sysPath = PySys_GetObject("path");
    PyList_Append(sysPath, PyUnicode_FromString("."));

    pName = PyUnicode_FromString("script");
    pModule = PyImport_Import(pName);
    if (pModule != NULL)
    {
        std::cout << "Python module found\n";
        pFunc = PyObject_GetAttrString(pModule, "test");
        pArgs = PyTuple_Pack(1, PyUnicode_FromString("Greg"));
        pValue = PyObject_CallObject(pFunc, pArgs);

        auto result = _PyUnicode_AsString(pValue);
        std::cout << result << std::endl;
    }

    // Close the python instance
    Py_Finalize();
}