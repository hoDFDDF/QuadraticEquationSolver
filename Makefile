CC = g++ #переменная СС указыкает компилятор, используемый для сборки

CFLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

EXECUTABLE = program 
SOURSES = io.cpp main.cpp SolveEquation.cpp Test.cpp
OBJECTS= $(addprefix Source/,$(SOURSES:.cpp=.o))

# add_prefix
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) 

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
io.o: io.cpp
	$(CC) $(CFLAGS) io.cpp
SolveEquation.o: SolveEquation.cpp
	$(CC) $(CFLAGS) SolveEquation.cpp
Test.o: Test.cpp
	$(CC) $(CFLAGS) Test.cpp

clean:
	rm -rf *.o $(EXECUTABLE)


