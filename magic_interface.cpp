
#include <stdlib.h>

#include "magic.hpp"
#include "magic_interface.h"

/* declared in magic_interface.h but defined here */
struct MHandler {
	void *obj;
};

MHandler_t *create_magic(int value)
{
	MagicWrapper *obj;
	MHandler_t *h;

	h = (typeof(h))malloc(sizeof(*h));
	if (!h)
		return NULL;

	obj = new MagicWrapper(value);
	h->obj = obj;

	return h;
}

int getValue_magic(MHandler_t *h)
{
	MagicWrapper *obj;
	int val;

	obj = static_cast<MagicWrapper *>(h->obj);
	val = obj->getValue();

	return val;
}

void destroy_magic(MHandler_t *h)
{
	MagicWrapper *obj;

	obj = static_cast<MagicWrapper *>(h->obj);
	/* Delete the obj instance */
	delete obj;

	/* destroy the opaque handler */
	free(h);
}
