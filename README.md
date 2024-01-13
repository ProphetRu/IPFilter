# IP Filter
Educational project with [googletest](https://github.com/google/googletest)

## Build local
```shell
cd IPFilter
git clone https://github.com/google/googletest.git

mkdir build && cd build

cmake ..

# build release
cmake --build . --config Release

# build deb-package
cmake --build . --target package
```

## Testing
```shell
cat ip_filter.tsv | ./IPFilter | md5sum
# 24e7a7b2270daee89c64d3ca5fb3da1a  -
```
