
#include "magic.hpp"

//Magic::Magic(int value) : m_value(value) {}

Magic::Magic(int value) {
	m_value = value;
}

// Method that returns an auto pointer to a dynamically allocated object of
// this class
std::unique_ptr<Magic> Magic::create(int value) {
	return std::unique_ptr<Magic>(new Magic(value));
}

void Magic::printValue() {
	std::cout << "Value: " << m_value << std::endl;
}

int Magic::getValue() {
	return m_value;
}

/* Wrapper used by C code */

MagicWrapper::MagicWrapper(int value) {
	uptr_m = Magic::create(value);
}

MagicWrapper::~MagicWrapper() {
	/* After calling the reset() method on the unique_ptr, the resource it
	 * was managing is released and the memory is deallocated.
	 */
	uptr_m.reset();
}

int MagicWrapper::getValue() {
	return uptr_m->getValue();
}
