The magic.cpp file contains the implementation of the **Magic** class, which is
intended to exemplify the utilization of a C++ class in C. To utilize objects
instantiated from the **Magic** class in C, an additional class,
**MagicWrapper**, is required. This is intended to adapt **Magic** to be
invoked safely from C code through **MagicWrapper**. In fact, **MagicWrapper**
handles C++'s own peculiarities, such as smart pointers, by showing them to C
code as normal pointers.

The **MagicWrapper** class cannot yet be used directly in C code. What is
needed is a C++ <-> C interface, so that C code can invoke plain C functions
that internally interface with objects instantiated by the **MagicWrapper**
(which in turn handle instances of **Magic**).

To this end, the magic_interface.cpp file encapsulates the C++-to-C adaptation
logic. In a C file, it is only necessary to include the corresponding header
file (e.g., magic_interface.h).
The mainc.c file demonstrates the use of the interface functions defined in
magic_interface.h.

For further information and details, please refer to the appropriately
commented code in all key steps.
