FROM amytabb/docker_ubuntu16_essentials
COPY . /ttt
WORKDIR /ttt/build
#RUN g++ -o ttt helloworld2.cpp
CMD ["cmake .. "]