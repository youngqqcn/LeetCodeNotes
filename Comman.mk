all:cpp

SOURCE=$(basename $(wildcard *.cc))
TARGET=main
FLAGS=-g -fsanitize=address -fsanitize=leak

echo:
	echo $(SOURCE)

cpp:clean
	@g++ $(FLAGS) $(SOURCE).cc -o  $(TARGET) -std=c++2a
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
	@ rm -f core a.out

.PHONY:clean
