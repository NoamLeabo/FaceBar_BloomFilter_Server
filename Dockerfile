FROM gcc:latest


COPY ./AL_Tests.cpp ./AL_Tests.cpp

RUN g++ -std=c++17 AL_src/AL_Tests.cpp -o al_test
