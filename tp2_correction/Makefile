# Makefile template
## The selected compiler
CXX = gcc
## The compilation flags (-g adds debugging symbols)
CFLAGS = -Wall -Werror -ansi -g
## The directories of the libraries to include
LIBSDIR = -L. -L/usr/lib
## The directories of the header files to include
INCLUDEDIR = -I. -I/usr/include

# Library-related macros
## The name of the library we will produce
LIBTARGET = product
## The source dependencies required to build the library
## Note: product and product list will be gathered in a single library
LIBSOURCE = product product_list
LIBSOURCECFILE = $(LIBSOURCE:=.c)
LIBSOURCEOFILE = $(LIBSOURCE:=.o)

# Application-related macros
## The name of the target application
TARGET = product_list_test.exe
## The source file of the application
EXESOURCE = main
EXESOURCECFILE = $(EXESOURCE:=.c)
EXESOURCEOFILE = $(EXESOURCE:=.o)

# To overload the content of the LD_LIBRARY_PATH
# export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.

# Make all
all: $(TARGET) $(LIBTARGET)

# Running the program
run: $(TARGET)
	@echo "\n Executing the executable " $(TARGET)
	sh exportLD.sh $(TARGET)

# Generating the executable
$(TARGET): $(EXESOURCEOFILE) lib$(LIBTARGET).so
	@echo "\n Generating the executable " $@
	$(CXX) $(EXESOURCEOFILE) $(LIBSDIR) -l$(LIBTARGET) -o $(TARGET)

# Generating the library binary code
lib$(LIBTARGET).so: $(LIBSOURCEOFILE)
	@echo "\n Generating the library " $@
	$(CXX) $(CFLAGS) -shared $(LIBSOURCEOFILE) -o lib$(LIBTARGET).so

# Generating an object file from a C file having the same name
.c.o:
	@echo "\n Generating " $@ " from " $<
	$(CXX) $(CFLAGS) $(INCLUDEDIR) -c -o $@ $<

# Cleaning the content of the current directory
clean:
	@echo "\n Cleaning temporary files"
	rm -rf *.o *~ *.so *.exe