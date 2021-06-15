all:cpp

SOURCE=$(basename $(wildcard *.cc))
TARGET=main

echo:
	echo $(SOURCE)

cpp:clean
	@g++ -g $(SOURCE).cc -o  $(TARGET) -std=c++2a
	@$(MAKE) run

go:clean
	@go build -o $(TARGET) $(SOURCE).go
	@$(MAKE) run

rust:clean
	@rustc $(SOURCE).rs -o $(TARGET)
	@$(MAKE) run

run:
	./$(TARGET)

clean:
	@ rm -f $(TARGET)

.PHONY:clean
