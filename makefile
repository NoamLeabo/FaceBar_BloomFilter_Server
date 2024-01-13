all:
      g++ -std=c++17 /AL_src/AL_Tests.cpp -o al_test

test:
	chmod +x hello
	./al_test

clean:
      $(RM) al_test