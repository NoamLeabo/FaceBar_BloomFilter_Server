FROM gcc:latest


COPY ./AL_Tests.cpp ./AL_Tests.cpp

RUN g++ -o test AL_Tests.cpp

CMD ["./test"]