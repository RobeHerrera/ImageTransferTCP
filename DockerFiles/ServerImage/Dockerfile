FROM gcc:4.9
COPY . /ServerImage
WORKDIR /ServerImage
#RUN g++ -o Server demo_Server.cpp
RUN sudo apt-get install libstdc++6
CMD ["./Server"]
