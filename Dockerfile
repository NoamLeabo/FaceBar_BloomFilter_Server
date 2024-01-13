FROM gcc:latest


COPY ./AL_Tests/AL_Tests.cpp AL_Tests.cpp

RUN g++ -O test ./AL_Tests.cpp
