# Define the compiler to use
CPP = g++
CC = gcc

CFLAGS = -Wall

# -lstdc++ is a linker option in the GCC compiler that links the C++ standard
# library (libstdc++) with the compiled executable. This option tells the linker
# to include the necessary C++ standard library functions and classes in the
# final binary file.
LFLAGS = -lstdc++

C_SRC = mainc.c

CPP_SRCS = magic.cpp magic_interface.cpp
CPP_OBJS = $(CPP_SRCS:.cpp=.o)

TARGET = fooc

%.o: %.cpp
	$(CPP) -c $< -o $@ $(FLAGS)

$(TARGET): $(CPP_OBJS) $(C_SRC)
	$(CC) -o $@ $(C_SRC) $(CPP_OBJS) $(CFLAGS) $(LFLAGS)

all: $(TARGET)

clean:
	rm -f $(CPP_OBJS) $(TARGET)
