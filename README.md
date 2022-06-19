# Hello, it is my simple project with C++ and SFML 

## If you want to run this code from ubuntu 

~~~
    1. sudo apt upgrade && sudo apt update -y
    
    2. sudo apt install g++

    3. sudo apt-get install libsfml-dev

    4. g++ main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

    5. ./sfml-app 
~~~

## If you want to run this code from macos 

~~~
    1. /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

    2. brew install sfml

    3. g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -o prog -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

    4. ./prog 
~~~
