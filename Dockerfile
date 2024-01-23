FROM ubuntu:latest


COPY ./src/*.cpp ./src/*.cpp

RUN apt-get update && apt-get install -y locales && rm -rf /var/lib/apt/lists/* \
	&& localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8 && sudo apt-get install -y libgtest-dev cmake
ENV LANG en_US.utf8


RUN cd src && g++ -o main main.cpp App.cpp BloomFilter.cpp HashNo1.cpp HashNo2.cpp AddUrl.cpp CheckUrl.cpp ConsoleMenu.cpp


CMD ["./main"]