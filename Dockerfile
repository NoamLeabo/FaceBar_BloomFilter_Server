FROM gcc:latest


COPY ./src/*.cpp ./src/*.cpp

RUN g++ -o main src/main.cpp src/App.cpp src/BloomFilter.cpp src/HashNo1.cpp src/HashNo2.cpp src/AddUrl.cpp src/CheckUrl.cpp src/ConsoleMenu.cpp



CMD ["./main"]