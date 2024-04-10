cd build
rm -rf *
cmake ..
cmake --build .
cd ..
./build/sim -lf
