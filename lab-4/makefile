# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall 
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/main

# Encuentra todos los .cpp en src/ recursivamente
SOURCES = $(shell find $(SRCDIR) -name '*.cpp')

# Genera los .o correspondientes en obj/, manteniendo la estructura
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Regla por defecto
all: $(TARGET)

# Linkeo final
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regla para compilar cada archivo fuente
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -rf $(OBJDIR) $(BINDIR)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean

