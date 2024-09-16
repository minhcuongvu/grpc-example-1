# step-by-step

prerequesites:

- [g++ from gnu/gcc](https://ftp.gnu.org/gnu/gcc/)
- [gRPC from source](https://github.com/grpc/grpc), clone to `$HOME/grpc`, install to `$HOME/.local`
- CMake in `$HOME/cmake` and PATH contains `$HOME/cmake/bin`
- [protobuf from source](https://github.com/protocolbuffers/protobuf), clone to `$HOME/protobuf`, installed into `$HOME/.local`

make sure to use the latest/stable versions

```shell
mkdir build

cd build

$HOME/cmake/bin/cmake \
    -DCMAKE_BUILD_TYPE:STRING=Debug \
    -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
    -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc \
    -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++ \
    -DCMAKE_PREFIX_PATH=$HOME/.local \
    -DProtobuf_DIR:PATH=$HOME/.local/lib/cmake/protobuf \
    --no-warn-unused-cli \
    -S$HOME/repos/grpc-example-1 \
    -B$HOME/repos/grpc-example-1/build \
    -G "Unix Makefiles"

make
```
