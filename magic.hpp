
#ifndef MAGICCLASS_HPP
#define MAGICCLASS_HPP

#include <iostream>
#include <memory>

class Magic {
public:
    Magic(int value);
    static std::unique_ptr<Magic> create(int value);
    void printValue();
    int getValue();

private:
    int m_value;
};

/* Wrapper class incapsulating an unique_ptr. An unique_ptr is a kind of smart
 * pointer which is able to automatically delete the pointed object if is
 * not referenced anymore.
 * Better avoiding to expose a unique_ptr.get() (raw) pointer to C directly.
 * Instead, instantiate a new class object (warpper) which builds the internal
 * object using whatever approch is required (factory, new, etc). In this case,
 * the Magic object is built using a static method (like a factory) and it
 * returns an unique_ptr. This pointer still remain valid unless the
 * MagicWrapper is (manually) destroyed.
 */
class MagicWrapper {
public:
	MagicWrapper(int value);
	~MagicWrapper();
	int getValue();

private:
	std::unique_ptr<Magic> uptr_m;
};

#endif
