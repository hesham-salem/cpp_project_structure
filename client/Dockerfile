FROM ubuntu:latest
WORKDIR /client

RUN apt-get update && \
    apt-get install -y \
    g++ \
    cmake \
    libboost-all-dev



ENTRYPOINT  ["tail", "-f", "/dev/null" ]

