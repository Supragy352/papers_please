.PHONY: all clean

# Define required environment variables
#------------------------------------------------------------------------------------------------
# Define target platform: PLATFORM_DESKTOP, PLATFORM_RPI, PLATFORM_DRM, PLATFORM_ANDROID, PLATFORM_WEB
PLATFORM			  ?= PLATFORM_DESKTOP

# Define required raylib variables
PROJECT_NAME		  ?= papers_please
RAYLIB_VERSION		?= 4.5.0
RAYLIB_PATH			?= ..

# Locations of raylib.h and libraylib.a/libraylib.so
# NOTE: Those variables are only used for PLATFORM_OS: LINUX, BSD
RAYLIB_INCLUDE_PATH	?= /usr/local/include
RAYLIB_LIB_PATH		?= /usr/local/lib

# Library type compilation: STATIC (.a) or SHARED (.so/.dll)
RAYLIB_LIBTYPE		?= STATIC

# Build mode for project: DEBUG or RELEASE
BUILD_MODE			?= RELEASE

# Use external GLFW library instead of rglfw module
USE_EXTERNAL_GLFW	 ?= FALSE

# Use Wayland display server protocol on Linux desktop (by default it uses X11 windowing system)
# NOTE: This variable is only used for PLATFORM_OS: LINUX
USE_WAYLAND_DISPLAY	?= FALSE

# PLATFORM_WEB: Default properties
BUILD_WEB_ASYNCIFY	?= TRUE
BUILD_WEB_SHELL		?= $(RAYLIB_PATH)/src/minshell.html
BUILD_WEB_HEAP_SIZE	?= 134217728
BUILD_WEB_RESOURCES	?= TRUE
BUILD_WEB_RESOURCES_PATH  ?= $(dir $<)resources@resources

# Define default C compiler: CC
#------------------------------------------------------------------------------------------------
CC = gcc

# Define default make program: MAKE
#------------------------------------------------------------------------------------------------
MAKE ?= make

# Define compiler flags: CFLAGS
#------------------------------------------------------------------------------------------------
#  -O1				  defines optimization level
#  -g					include debug information on compilation
#  -s					strip unnecessary data from build
#  -Wall				turns on most, but not all, compiler warnings
#  -std=c99			 defines C language mode (standard C from 1999 revision)
#  -std=gnu99			defines C language mode (GNU C from 1999 revision)
#  -Wno-missing-braces  ignore invalid warning (GCC bug 53119)
#  -Wno-unused-value	ignore unused return values of some functions (i.e. fread())
#  -D_DEFAULT_SOURCE	use with -std=c99 on Linux and PLATFORM_WEB, required for timespec
CFLAGS = -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result

ifeq ($(BUILD_MODE),DEBUG)
	CFLAGS += -g -D_DEBUG
else
	CFLAGS += -O2
endif

# Additional flags for compiler (if desired)
#  -Wextra				  enables some extra warning flags that are not enabled by -Wall
#  -Wmissing-prototypes	 warn if a global function is defined without a previous prototype declaration
#  -Wstrict-prototypes	  warn if a function is declared or defined without specifying the argument types
#  -Werror=implicit-function-declaration	catch function calls without prior declaration
#CFLAGS += -Wextra -Wmissing-prototypes -Wstrict-prototypes

ifeq ($(PLATFORM_OS),LINUX)
	ifeq ($(RAYLIB_LIBTYPE),SHARED)
		# Explicitly enable runtime link to libraylib.so
		CFLAGS += -Wl,-rpath,$(RAYLIB_RELEASE_PATH)
	endif

	# Libraries for Debian GNU/Linux desktop compiling
	# NOTE: Required packages: libegl1-mesa-dev
	LDLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt

	# On X11 requires also below libraries
	LDLIBS += -lX11

	# Explicit link to libc
	LDLIBS += -lc

	# NOTE: On ARM 32bit arch, miniaudio requires atomics library
	LDLIBS += -latomic
endif

# Define include paths for required headers: INCLUDE_PATHS
#------------------------------------------------------------------------------------------------
# NOTE: Some external/extras libraries could be required (stb, easings...)
INCLUDE_PATHS = -I. -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/external

# Define additional directories containing required header files
INCLUDE_PATHS += -I$(RAYLIB_INCLUDE_PATH)

# Define library paths containing required libs: LDFLAGS
#------------------------------------------------------------------------------------------------
LDFLAGS = -L. -L$(RAYLIB_RELEASE_PATH) -L$(RAYLIB_PATH)/src

# Define libraries required on linking: LDLIBS
# NOTE: To link libraries (lib<name>.so or lib<name>.a), use -l<name>
#------------------------------------------------------------------------------------------------
LDLIBS += -lraylib -lGL -lm -lpthread -ldl -lrt

# Explicit link to libc
LDLIBS += -lc

# NOTE: On ARM 32bit arch, miniaudio requires atomics library
LDLIBS += -latomic

# Define raylib release directory for compiled library
RAYLIB_RELEASE_PATH	?= $(RAYLIB_PATH)/src

# Define target for all
all: $(PROJECT_NAME)

# Compile project
$(PROJECT_NAME):
	$(CC) -o $(PROJECT_NAME) main.c $(INCLUDE_PATHS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

run: $(PROJECT_NAME)

$(PROJECT_NAME):
	$(CC) -o $(PROJECT_NAME) main.c $(INCLUDE_PATHS) $(CFLAGS) $(LDFLAGS) $(LDLIBS) && ./$(PROJECT_NAME)

# Clean project
clean:
	rm -f $(PROJECT_NAME)