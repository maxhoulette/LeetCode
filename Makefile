CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -c
AR = ar
ARFLAGS = rcs

PROJECTS = easy medium hard

# Source files are in src/
easy_SRCS = $(wildcard easy/src/*.cc)
medium_SRCS = $(wildcard medium/src/*.cc)
hard_SRCS = $(wildcard hard/src/*.cc)

# Object files go into build/ with same filenames as sources
easy_OBJS = $(patsubst easy/src/%.cc, easy/build/%.o, $(easy_SRCS))
medium_OBJS = $(patsubst medium/src/%.cc, medium/build/%.o, $(medium_SRCS))
hard_OBJS = $(patsubst hard/src/%.cc, hard/build/%.o, $(hard_SRCS))

all: easy/libeasy.a medium/libmedium.a hard/libhard.a

# Create build directories if they don't exist
$(shell mkdir -p easy/build medium/build hard/build)

# Compile .cc to .o in build/
easy/build/%.o: easy/src/%.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

medium/build/%.o: medium/src/%.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

hard/build/%.o: hard/src/%.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

# Archive static libs
easy/libeasy.a: $(easy_OBJS)
	$(AR) $(ARFLAGS) $@ $^

medium/libmedium.a: $(medium_OBJS)
	$(AR) $(ARFLAGS) $@ $^

hard/libhard.a: $(hard_OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -rf easy/build medium/build hard/build
	rm -f easy/libeasy.a medium/libmedium.a hard/libhard.a
