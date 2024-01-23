FROM gcc:latest


COPY ./src/*.cpp ./src/*.cpp

RUN sudo apt-get update
RUN sudo apt-get install -y libgtest-dev cmake

RUN cd src && g++ -o main main.cpp App.cpp BloomFilter.cpp HashNo1.cpp HashNo2.cpp AddUrl.cpp CheckUrl.cpp ConsoleMenu.cpp


CMD ["./main"]