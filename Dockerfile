FROM gcc:latest

WORKDIR .

COPY .

RUN g++ -O test ./AL_Tests.cpp
