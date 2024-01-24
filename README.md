# Foobar_Project

How to compile and run our Project:

COMPILE: g++ -o main main.cpp App.cpp  BloomFilter.cpp HashNo1.cpp HashNo2.cpp AddUrl.cpp CheckUrl.cpp ConsoleMenu.cpp

RUN: ./main

JIRA explanantion:

We started by reading the exercise a few times and understanding all components.
Then we decided how to divide the project between all the teammates.
After that everyone wrote his own tasks in the Jira and we checked that all tasks were covered.
We started working on the project and everyone updated his tasks and what he was currently working on.
Every crucial step was written in the Jira so everyone could now where we are standing and what needs to be done.

TDD:

We wrote the BloomFilter in the TDD method as expected.
Our process was as followed:
1. Writing a test and failing.
2. Writing code to pass the test.
3. Refactoring to improve the code


After we finished writing the BloomFilter class we refactored it again to improve our code and make it more abstract and loose-coupled from the hash functions.
We then wrote a simple main that is running the BloomFilter and gettןng inputs from the user.
Then we started to refactor the main to get OOP classes to have the MenuCommands separate form the user 
inputs and a small main function.
We then found out that our BloomFilter needs to be refactored and other files needed also to 
be changed.
We continued refactoring according to tests we made to pass all tests and have more abstract and readable code.
Our final code contains the following main components: 
1. BloomFilter- the blomfilter asked to code in the exercise.
2. App- file who runs the main loop of the program and interacting with the user's input.
3. ConsoleMenu- getting the first crucial input that indicates us the length of the bloomfilter and the number of hash functions used.
4. main- creating an APP object and calling APP's run fucntion.
5. HashNo1,2- specific hash functions that were asked to use.
6. CheckUrl- checking if a specific URL is in the bloomfilter.
7. AddUrl- adding a URL to a bloomfilter.


DOCKER:
For the docker part, we created a yml file to create and push a new image to dockerhub.
We also created a Dockerfile for the yml to use.

Dockerfile explanation: 
Copyies all cpp files and relevant header files to the machine, compiles the cpp files and runs the created exe file.

Docker push-to-hub explanation:
on release, the yml file logins to docker hub, downloads builds and pushes an image of the program to dockerhub/
