# Do something under Mac OS X platform
echo "Mac OS"
brew install cmake
cd externalLib/gtest-1.8.0/googletest
sudo mkdir build
cd build
cmake -Dgtest_build_samples=ON -Dgtest_build_tests=ON ../.
make clean
make all
