CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		TestSTL.o TestString.o

LIBS =

TARGET =	TestSTL.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
