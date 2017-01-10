# target entry to build program named sorting from sorting.cpp
# compiler
CC = g++

# compiler flags
CFLAGS = -g -Wall -std=c++11

# The object files
OFILES = sentence.o

# the build target executable
TARGET = WSD

.PRECIOUS: %.o

all: $(TARGET)


$(TARGET) : $(TARGET).cpp $(OFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(OFILES)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<


.PHONY: clean
clean:
	$(RM) $(TARGET)
	$(RM) *.o
