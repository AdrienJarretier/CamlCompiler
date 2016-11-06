if [ "$(uname)" == "Darwin" ]; then
  # Do something under Mac OS X platform
  brew install cmake
  cd externalLib/gtest-1.8.0/googletest
  mkdir build
  cd build
  cmake ../
  make

  sudo mkdir /usr/local/Cellar/gtest
  cd ../../
  sudo cp googletest/build/libgtest.a /usr/local/Cellar/gtest/
  sudo ln -snf /usr/local/Cellar/gtest/libgtest.a /usr/local/lib/libgtest.a
  #sudo ln -snf /usr/local/Cellar/gtest/libgtest.a /usr/lib/libgtest.a
  sudo cp -r googletest/include /usr/local/Cellar/gtest/
  ln -snf ../Cellar/gtest/include/gtest /usr/local/include/gtest
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
  # Do something under GNU/Linux platform
  sudo apt-get install libgtest-dev
  sudo apt-get install cmake # install cmake
  cd /usr/src/gtest
  sudo cmake CMakeLists.txt
  sudo make clean
  sudo make all
  sudo cp *.a /usr/lib
fi
