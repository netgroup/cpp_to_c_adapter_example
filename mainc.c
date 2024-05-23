
#include <stdio.h>
#include <errno.h>

#include "magic_interface.h"

int main()
{
	MHandler_t *h = create_magic(17);
	int val;

	if (!h) {
		printf("Cannot create MHandler\n");
		return -ENOMEM;
	}

	val = getValue_magic(h);
	printf("getValue=%d\n", val);

	/* destroy the opaque handler along with the C++ objects */
	destroy_magic(h);

	printf(" *** Done! ***\n");

	return 0;
}
