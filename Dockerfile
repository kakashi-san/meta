# Use Ubuntu 18.04 as the base image
FROM ubuntu:18.04

# Set environment variables for the compiler
ENV COMPILER=gcc
ENV GCC_VERSION=5

# Update the package list and install necessary packages
RUN apt-get update && apt-get install -y \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common \
    sudo \
    wget \
    cmake \
    libicu-dev \
    git \
    libjemalloc-dev \
    zlib1g-dev \
    && add-apt-repository ppa:ubuntu-toolchain-r/test -y \
    && apt-get update && apt-get install -y \
    gcc-5 \
    g++-5 \
    docker.io \
    default-libmysqlclient-dev \
    default-jdk \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create a symbolic link for gcc and g++
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 60 \
    --slave /usr/bin/g++ g++ /usr/bin/g++-5

# Set the default command to run when starting the container
CMD ["bash"]
