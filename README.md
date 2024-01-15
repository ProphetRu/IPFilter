# IP Filter
Educational project with [googletest](https://github.com/google/googletest)

## Build local Linux
```shell
sudo apt-get update && sudo apt-get install cmake libgtest-dev -y

cd IPFilter
mkdir build && cd build

cmake ..

# build release
cmake --build . --config Release

# build deb-package
cmake --build . --target package
```

## Build local Windows
```shell
vcpkg install gtest
vcpkg integrate install

cd IPFilter
mkdir build && cd build

cmake .. -DCMAKE_TOOLCHAIN_FILE="path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"

# build release
cmake --build . --config Release
```

## Testing
```shell
cat ip_filter.tsv | ./IPFilter | md5sum
# 24e7a7b2270daee89c64d3ca5fb3da1a  -
```
