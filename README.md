
# Endless Runner Game 

## Project Description

This project is an **Endless Runner Game** developed in C++. Players control a character that runs automatically through an endless landscape, avoiding obstacles and collecting items. The game tests reflexes and decision-making skills as the character speeds up over time, making it increasingly challenging.

## Table of Contents
- [Features](#features)
- [How to Play](#how-to-play)
- [Running the Game](#running-the-game)
- [Code Structure](#code-structure)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)


## Features

- **Endless Gameplay**: The game generates an infinite level as the character runs.
- **Obstacle Avoidance**: Players must jump over or slide under various obstacles.
- **Item Collection**: Collect items for points and bonuses.
- **Score Tracking**: The game tracks and displays the current score based on collected items.
- **Difficulty Scaling**: The game becomes progressively harder with increased speed and more frequent obstacles.

## How to Play

1. **Controls**:
   - Press the **Spacebar** to jump over obstacles.
   - Press the **Down Arrow** key to slide under obstacles.
   
2. **Objective**:
   - Survive as long as possible while avoiding obstacles and collecting items.
   - Try to achieve the highest score by collecting items along the way.

3. **Game Over**:
   - The game ends when the character collides with an obstacle. The final score will be displayed.


## Running the Game

Once the game starts:

- Use the controls to navigate the character.
- Avoid obstacles and collect items to increase your score.
- Keep track of your score displayed on the screen.

### Example Gameplay Output:
```
Welcome to the Endless Runner Game!
Controls: Spacebar to jump, Down Arrow to slide.
Score: 0
...
Game Over! Your final score is: 150
```

## Code Structure

The project utilizes object-oriented principles and consists of the following main classes:

### `Player`
- Represents the player character.
- Contains attributes for position, score, and state (jumping, sliding).

### `Obstacle`
- Represents obstacles that the player must avoid.
- Attributes include position and type of obstacle.

### `Game`
- Manages the game loop and logic.
- Handles user input, collision detection, and score tracking.
- Responsible for generating obstacles and items.

## Future Enhancements

- **Graphics and Animation**: Use a graphics library (e.g., SFML or SDL) to add graphics and animations for a better visual experience.
- **Sound Effects**: Implement sound effects for jumps, item collection, and game over scenarios.
- **Power-ups**: Introduce power-ups that grant temporary abilities like speed boosts or invincibility.
- **High Score Tracking**: Store high scores and display them on the main menu.
- **Multiplayer Mode**: Add a multiplayer option where two players can compete against each other.

## Contributing

Contributions are welcome! Here’s how to contribute:

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature-branch
   ```
3. Make your changes and commit:
   ```bash
   git commit -m "Add feature"
   ```
4. Push to the branch:
   ```bash
   git push origin feature-branch
   ```

