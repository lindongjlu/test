CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		TestCLib.o TestCStdio.o TestCStdlib.o TestCString.o TestCTime.o

LIBS =

TARGET =	TestCLib.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
