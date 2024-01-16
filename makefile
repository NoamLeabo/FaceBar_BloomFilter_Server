all:
	g++ -std=c++17 AL_Tests.cpp -o al_test

test:
	chmod +x al_test
	./al_test

clean:
	$(RM) al_test
