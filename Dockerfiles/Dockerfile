# Basic dockerfile for working with C++ and python programs for development
FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive 

RUN apt-get update \
    && apt-get install -y --no-install-recommends \ 
    wget \
    ca-certificates \
    lsb-release \
    python3 \
    python3-pip \
    python3-setuptools \
    python3-wheel \
    make \
    cmake \
    git \
    g++ \
    ccache \
    screen \
    vim \
    shellcheck \
    clang-format \
    build-essential 

# Set library_path
ENV LD_LIBRARY_PATH /opt/myprogram/:${LD_LIBRARY_PATH}

# Set Working directory 
WORKDIR /opt/myprogram/

