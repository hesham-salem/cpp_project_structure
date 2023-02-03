FROM rikorose/gcc-cmake
WORKDIR /app
RUN apt-get update
RUN apt-get install libfmt-dev -y
RUN cd /usr/src &&\
    git clone https://github.com/google/googletest && \
    cd googletest  && \
    mkdir build && \
    cd build  && \
    cmake ..  && \
    make  && \
    make install 

ENTRYPOINT ["tail", "-f", "/dev/null"]
#ENTRYPOINT [ "/bin/bash" ]
VOLUME /app
#CMD ["c"]