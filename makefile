all:
	g++ -std=c++17 .\AL_src\AL_Tests.cpp -o hello

test:
	chmod +x hello
	./hello

clean:
	$(RM) hello
