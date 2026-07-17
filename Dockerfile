FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential curl libcap-dev git cmake libncurses5-dev \
    python3 python3-pip gcc-multilib g++-multilib \
    clang-10 llvm-10-dev llvm-10-tools \
    bison flex libboost-all-dev perl minisat \
    libsqlite3-dev doxygen \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install lit tabulate wllvm

# Build STP solver
WORKDIR /deps
RUN git clone --depth 1 https://github.com/stp/stp.git && \
    cd stp && git submodule init && git submodule update && \
    mkdir build && cd build && cmake .. && cmake --build . -j$(nproc) && \
    cmake --install .

# Build klee-uclibc
RUN git clone --depth 1 https://github.com/klee/klee-uclibc.git && \
    cd klee-uclibc && \
    ./configure --make-llvm-lib --with-llvm-config=/usr/bin/llvm-config-10 && \
    make -j$(nproc)

# Copy SKLEE source
COPY . /sklee
WORKDIR /sklee

# Build modified KLEE with SKLEE patches
RUN mkdir -p build && cd build && \
    cmake \
    -DENABLE_SOLVER_STP=ON \
    -DENABLE_POSIX_RUNTIME=ON \
    -DENABLE_KLEE_UCLIBC=ON \
    -DKLEE_UCLIBC_PATH=/deps/klee-uclibc \
    -DLLVM_CONFIG_BINARY=/usr/bin/llvm-config-10 \
    -DENABLE_UNIT_TESTS=OFF \
    -DLLVMCC=/usr/bin/clang-10 \
    -DLLVMCXX=/usr/bin/clang++-10 \
    ../klee/ && \
    make -j$(nproc)

ENV PATH="/sklee/build/bin:${PATH}"

WORKDIR /sklee
CMD ["bash"]
