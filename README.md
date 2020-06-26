# My command line adventure game

[Github](https://github.com/jcarlos0305/zork)

This is a command line adventure game, in which the main character will travel across the world facing different circumstances that will need decision making in order to progress and that will impact in the outcome of the story.

# Game Features!

- Increasing your stats by picking up items
- Upgrading your items
- Locked up areas
- Fighting NPCs

### Tech

The game was developed in C++

- The Windows SDK version used in this project is 10.0.18362.0

### Commands

These are the commands that will get your adventure going!

| Command | Argument       | Valid Options            | Outcome                                           |
| ------- | -------------- | ------------------------ | ------------------------------------------------- |
| Go      | <direction>    | North, South, East, West | The character will move in that direction         |
| Pick    | [item \| name] | Item, Stick, Rock        | The character will pick an item if there's any    |
| Drop    | [item \| name] | Item, Stick, Rock        | The character will drop an item if it has any     |
| Attack  | [name]         | Wolf                     | The character will attack an enemy if there's any |
| Show    | <information>  | Inventory, Stats         | The requested information will be displayed       |
| Exit    |                |                          | Close the game                                    |

I won't tell you how to beat the game, you will have to experience it by yourself, but here's a friendly hint. ↑\*←\*→↓→↓→

### Challenges

The experience was so much fun! I've programmed other kind of applications in C++, however programming a video game for the first time got me really excited. During the process I faced some challenges like parsing the user input into function calls, designing the classes towards the game requirements I wanted to implement, and testing all the possible scenarios the player could face.

Upgrading items was a feature that has always make games more dynamic, so I designed the item to be able to contain a group of items to improve it's stats. Not been able to progress in the adventure is a challenge that make players go back and take different decisions, so having areas that have the exit locked up was another feature I wanted my game to have, and finally the possibility to battle against enemies and to be defeated makes the player engage with the game.

As a future improvement of the game I want to implement a feature that will allow the user to load custom stories based on files that contain the game data that conforms the adventure.

### Authors

- Game: Juan Carlos Sánchez
- Story: Mariana Ramírez
- Game testers: Juan Diego Araya & Armando González

## License

MIT
