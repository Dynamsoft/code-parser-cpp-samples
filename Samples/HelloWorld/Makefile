CC=gcc
CCFLAGS=-c -std=c++11

DCP_PARSERRESOURCES_PATH=../../ParserResources
DS_LIB_PATH="../../Lib/Linux/x64"
LDFLAGS=-L $(DS_LIB_PATH) -Wl,-rpath=$(DS_LIB_PATH) -Wl,-rpath=./
DS_LIB=-lDynamsoftCodeParser -lDynamsoftLicense -lDynamsoftCore

STDLIB=-lstdc++

TARGET=HelloWorld
OBJECT=HelloWorld.o
SOURCE=HelloWorld.cpp

# build rule for target.
$(TARGET): $(OBJECT)
	$(CC) -o $(TARGET) $(OBJECT) $(STDLIB) $(DS_LIB) $(LDFLAGS)
	cp -r $(DCP_PARSERRESOURCES_PATH) $(DS_LIB_PATH)

# target to build an object file
$(OBJECT): $(SOURCE)
	$(CC) $(CCFLAGS) $(SOURCE)

# the clean target
.PHONY : clean
clean: 
	rm -f $(OBJECT) $(TARGET)