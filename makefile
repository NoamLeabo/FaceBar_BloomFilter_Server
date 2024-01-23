all:
	cd src && g++ -o main main.cpp App.cpp BloomFilter.cpp HashNo1.cpp HashNo2.cpp AddUrl.cpp CheckUrl.cpp ConsoleMenu.cpp


test:
	chmod +x src\main
	cmake -B build -S .
	cmake --build build
	ctest --test-dir build --output-on-failure

clean:
	$(RM) main