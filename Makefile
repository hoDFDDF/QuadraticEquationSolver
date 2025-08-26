# Для C++ нужно использовать CXX, а не CC
CC = g++

INCLUDE_DIRS = include
# Для C++ используем CXXFLAGS вместо CFLAGS
CFLAGS = -c -Iinclude -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

# CFLAGS += $(addprefix -I,$(INCLUDE_DIRS))

EXECUTABLE = program 
SOURCES = main.cpp io.cpp SolveEquation.cpp Test.cpp

# Правильно указываем пути - все файлы в папке Source/
SRC = $(addprefix Source\,$(SOURCES))
OBJECTS = $(SRC:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

# ОДНО правило для всех .cpp файлов - автоматическое!
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
