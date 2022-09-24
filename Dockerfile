FROM rikorose/gcc-cmake
COPY .  /usr/src/code
WORKDIR /usr/src/code
RUN apt-get update
RUN apt-get install libfmt-dev -y
RUN cd build && cmake .. && make 
RUN apt-get install tree
#CMD ["tree"]
CMD ["./build/calculatorX"]