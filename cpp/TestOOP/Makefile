CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		TestOOP.o

LIBS =

TARGET =	TestOOP.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
