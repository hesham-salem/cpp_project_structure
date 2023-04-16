FROM rikorose/gcc-cmake
#WORKDIR /server
RUN apt-get update
#RUN apt-get install libfmt-dev  \
#   libboost-all-dev -y
WORKDIR /usr/src 
RUN    git clone https://github.com/google/googletest && \
    cd googletest  && \
    mkdir build && \
    cd build  && \
    cmake ..  && \
    make  && \
    make install 
WORKDIR /server
ENTRYPOINT ["tail", "-f", "/dev/null"]
#ENTRYPOINT [ "/bin/bash" ]
#VOLUME /app
