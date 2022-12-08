# Hello 👋 , it is my simple project with C++ and SFML 
![](https://komarev.com/ghpvc/?username=PavelErsh)
### If you want to run this code from Ubuntu 

~~~
    1. sudo apt upgrade && sudo apt update -y
    
    2. sudo apt install g++

    3. sudo apt-get install libsfml-dev

    4. g++ main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

    5. ./sfml-app 
~~~
### If you want to run this code from MacOS
~~~
    1. /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

    2. brew install sfml
    
    3. brew install g++

    4. g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -o prog -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

    5. ./prog 
~~~

### if you want to run this code form Windows
### Read this [official documentation] [1]

## Game screenshots
![screen](https://raw.githubusercontent.com/PavelErsh/SFML-Game/master/images/Screenshot%202022-07-16%20at%2009.42.08.png)

## Game control
### Use ___UP___, ___DOWN___, ___RIGHT___, ___LEFT___ arrow for control your hero
### ___R___ and ___T___ for rotation
### ___U___ and ___Y___ for zoom camera,  ___S___ for set camera size


[1]: (https://www.sfml-dev.org/tutorials/2.5/start-vc.php)
