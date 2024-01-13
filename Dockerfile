FROM gcc:latest


COPY ./AL_Tests/AL_Tests ./AL_Tests/AL_Tests

RUN g++ -O test ./AL_Tests.cpp
