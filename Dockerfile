FROM rikorose/gcc-cmake
COPY .  /usr/src/code
WORKDIR /usr/src/code
RUN apt-get update
RUN apt-get install libfmt-dev -y
RUN git clone https://github.com/google/googletest && \
    cd googletest  && \
    mkdir build && \
    cd build  && \
    cmake ..  && \
    make  && \
    make install 
RUN cd build && cmake .. && make 
ENTRYPOINT ["tail", "-f", "/dev/null"]
#CMD ["c"]