FROM gcc:latest

# Set the working directory
WORKDIR /usr/src/app

# Copy individual source files
COPY ./src/main.cpp ./src/
COPY ./src/App.cpp ./src/
COPY ./src/BloomFilter.cpp ./src/
COPY ./src/HashNo1.cpp ./src/
COPY ./src/HashNo2.cpp ./src/
COPY ./src/AddUrl.cpp ./src/
COPY ./src/CheckUrl.cpp ./src/
COPY ./src/ConsoleMenu.cpp ./src/

# Compile the source files
RUN g++ -o main ./src/main.cpp ./src/App.cpp ./src/BloomFilter.cpp ./src/HashNo1.cpp ./src/HashNo2.cpp ./src/AddUrl.cpp ./src/CheckUrl.cpp ./src/ConsoleMenu.cpp

# Set the command to run when the container starts
CMD ["./main"]