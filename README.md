# Hangman Game

This repository contains a hangman game built using the OpenGL graphics library in C++. The game allows players to guess letters to complete a word before running out of attempts.

## Installation

To install and run the hangman game on Linux, please follow the instructions below:

1. Make sure you have the following dependencies installed on your system:
    - OpenGL
    - Eigen3
    - GLEW
    - Freetype
    - GLFW
    - irrKlang

   If any of the dependencies are missing, you can install them using your package manager. For example, on Ubuntu, you can use the following command:

   ```bash
   sudo apt-get install libglu1-mesa-dev libeigen3-dev libglew-dev libfreetype6-dev

1. Clone this repository to your local machine:
    
    ```bash
    git clone https://github.com/aadarshadhakalg/OpenGL.git
    ```

1. Change to the project directory:

    ```bash
    cd OpenGL
    ```

1. Create a build directory:

    ```bash
    mkdir build
    cd build
    ```

1. Generate build files:

    ```bash
    cmake ..
    ```
   
1. Copy ikpMP3 plugin to build directory:

    ```bash
    cp ../libraries/irrKlang/linux-gcc-64/ikpMP3.so ikpMP3.so
    ```

1. build the game and run:

    ```bash
    make && ./hangman
    ```

## Usage
- When the game starts, a blank word will be displayed along with the hangman figure.
- Guess letters one by one by typing them on the keyboard. If the letter is correct, it will be revealed in the word. If the letter is incorrect, the hangman figure will start to form.
- You have a limited number of attempts to guess the word correctly before the hangman figure is completed. If the hangman figure is completed before you guess the word, the game is over, and you lose.
- If you successfully guess the word before the hangman figure is completed, you win the game.

## Author

- Aadarsha Dhakal [Twitter @aadarshadhakalg](https://twitter.com/aadarshadhakalg) | [LinkedIn @aadarshadhakalg](https://www.linkedin.com/in/aadarshadhakalg/)

## Acknowledgements
This hangman game uses the following libraries:

- GLFW (included as a subdirectory in this repository)
- irrKlang (included as a subdirectory in this repository)

## License
The code in this repository is licensed under the #MIT('https:') License. Feel free to use and modify the code for your own purposes.

