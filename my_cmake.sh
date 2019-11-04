mkdir cmake_files
cd cmake_files
cmake  -DCMAKE_BUILD_TYPE=RELEASE -DHAVE_TBB=ON -DWITH_ALLOCATOR=TBB -DTBB_LIBRARIES_RELEASE=/usr/lib/x86_64-linux-gnu/libtbb.so -DCMAKE_CXX_COMPILER=/usr/bin/g++-7 -DENABLE_FLAT_FIELDMAP=Y ../
make
cd ..
mkdir release
cp cmake_files/src/C++/libquickfix.a ./release/