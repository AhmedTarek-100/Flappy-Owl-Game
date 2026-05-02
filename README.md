Flappy Owl 🦉
Developed by ECU++ Studio

A 2D arcade game built using C++ and the SFML (Simple and Fast Multimedia Library). This project focuses on implementing core game development patterns like State Management and Asset Management within a mechatronics engineering context.

🎮 Game Overview
Flappy Owl challenges players to navigate an owl through a series of obstacles (pipes). The game features a smooth gravity-based movement system and real-time collision detection.

🛠️ Technical Features
State Machine Architecture: Manages transitions between Splash Screen, Main Menu, Gameplay, and Game Over states.

Centralized Asset Manager: Efficiently loads and manages textures, fonts, and sounds to optimize memory usage.

Physics Engine: Custom implementation of gravity and bird "flap" mechanics.

Collision Detection: Precise bounding-box intersection logic for game entities.

Input Handling: Responsive controls for keyboard and mouse interactions.

📁 Project Structure (Key Files)
Based on the SFML Template:

main.cpp: The entry point of the application.

Bird.cpp/h: Logic for the player's character movement and animation.

Pipe.cpp/h: Generation and movement of obstacles.

GameState.cpp/h: The core game loop and logic.

AssetManager.cpp/h: Utility for handling game resources.

Resources/: Directory containing all textures, fonts, and audio files.

🚀 How to Run
Clone the repository.

Open the .sln file in Visual Studio.

Ensure the SFML library is correctly linked in your project properties.

Build and Run (Press F5).

👥 Team: ECU++ Studio
Ahmed Tarek - Lead Developer

Mohamed Hazem - Developer & UI
