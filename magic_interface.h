#ifndef MAGIC_INTERFACE
#define MAGIC_INTERFACE

#ifdef __cplusplus
extern "C" {
#endif
	/* The purpose of declaring a struct in a header file without
	 * defining it is to allow other source files that include the header
	 * to use pointers to the struct without needing to know the full
	 * definition of the struct. This technique is commonly used in C and
	 * C++ to create a "opaque" type, where the details of the struct are
	 * hidden from external code. This can be useful for encapsulating
	 * data and behavior within a library or module, and only exposing a
	 * limited interface to the outside world.
	 */
	struct MHandler;

	typedef struct MHandler MHandler_t;

	MHandler_t *create_magic(int);
	int getValue_magic(MHandler_t *);
	void destroy_magic(MHandler_t *);
#ifdef __cplusplus
}
#endif

#endif /* MAGIC_INTERFACE */
