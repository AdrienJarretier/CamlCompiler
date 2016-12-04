echo "begingin"
if [ "$(uname)" == "Darwin" ]; then
  # Do something under Mac OS X platform
  echo "jksjfklsdjfdlkj"
  brew install cmake
  cd externalLib/gtest-1.8.0/googletest
  mkdir build
  cd build
  cmake -Dgtest_build_samples=ON -Dgtest_build_tests=ON ../.
  make clean
  make all
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
  echo "djkvjdkvjkldjvd"
  # Do something under GNU/Linux platform
  sudo apt-get install libgtest-dev
  sudo apt-get install cmake # install cmake
  cd /usr/src/gtest
  sudo cmake CMakeLists.txt
  sudo make clean
  sudo make all
  sudo cp *.a /usr/lib
fi

echo "ending"
