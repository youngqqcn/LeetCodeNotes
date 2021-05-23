all:cpp

SOURCE=$(shell pwd | awk -F "\/"  '{print $$6}' |  sed 's/[0-9]\{4\}_//g')
TARGET=main

echo:
	$(SOURCE)

cpp:clean
	g++ $(SOURCE).cc -o $(TARGET) -std=c++2a
	$(MAKE) run

go:clean
	go build -o $(TARGET) $(SOURCE).go
	$(MAKE) run

rust:clean
	rustc $(SOURCE).rs -o $(TARGET)
	$(MAKE) run

run:
	./$(TARGET)

clean:
	- rm -f $(TARGET)

.PHONY:clean
