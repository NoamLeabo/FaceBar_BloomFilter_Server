FROM gcc:latest


COPY ./src/*.cpp ./src/*.cpp

RUN cd src && g++ -o main main.cpp App.cpp BloomFilter.cpp HashNo1.cpp HashNo2.cpp AddUrl.cpp CheckUrl.cpp ConsoleMenu.cpp


CMD ["./main"]