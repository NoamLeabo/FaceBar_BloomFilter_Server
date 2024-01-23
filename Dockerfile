FROM gcc:latest


COPY ./src/*.cpp ./src/*.cpp

RUN sudo apt-get update
RUN sudo apt-get install -y libgtest-dev cmake

 g++ -o test AL_Tests.cpp 

CMD ["./test"]