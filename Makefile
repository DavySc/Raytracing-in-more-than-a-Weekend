CXX := g++
SRCDIR := src
INCDIR := include
BUILDDIR := build
TARGET := main

SRC := $(wildcard $(SRCDIR)/*.cc)
DEPS := $(wildcard $(INCDIR)/*.h)

# Default build is debug
BUILD ?= debug

ifeq ($(BUILD),release)
    CXXFLAGS := -std=c++23 -Wall -Wextra -O2 -I$(INCDIR)
    BUILDDIR := build/release
else
    CXXFLAGS := -std=c++23 -Wall -Wextra -g -O0 -DDEBUG -I$(INCDIR)
    BUILDDIR := build/debug
endif

OBJ := $(patsubst $(SRCDIR)/%.cc, $(BUILDDIR)/%.o, $(SRC))

.PHONY: all debug release clean

all: $(BUILDDIR)/$(TARGET)
debug: BUILD=debug
debug: all
release: BUILD=release
release: all

$(BUILDDIR)/$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cc $(DEPS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build
