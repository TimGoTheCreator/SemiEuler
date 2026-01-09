# SemiEuler
Semi implicit Euler implementation in C++ to simulate interaction of N-Body objects

How to compile SemiEuler (CMake Windows)

```bash
mkdir build
cd build
cmake ..
cmake --build .
```
How to compile SemiEuler G++ (Windows)

```bash
g++ -std=c++11 -O2 -Iinclude src/main.cpp -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -lws2_32 -o SemiEuler.exe
```
