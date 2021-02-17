 # Space Adventure
 
 Authors: 
 - [Dana Savin](https://github.com/danams101)
 - [Kevin Ni](https://github.com/Keeevini)
 - [Fengchun Fan](https://github.com/FengchunFan)
 

## Project Description

Our project is a text-based RPG where the user can interact with the game through text and buttons they click on in a window.

Story premise:
        The story follows a group of people who crash land on exoplanet Proxima B when trying to deliver supplies, due to an engine malfunction. Without the supplies and a wrecked ship, the group must do their best to survive and carve a place to live in this hostile environment while they build a radio strong enough to reach earth to call for help.
        
### Game Features:
- Player interaction through text dialogues and buttons. They can push the buttons to gather resources like wood and food and build shelters for the crew and expand the base.
- The player will have access to an inventory
- The player will also interact with they story through dialogue options, depending on what the player chooses the game will alter its response.
 
### Motivation: 
This project is interesting to us because it would allow us the opportunity to test our coding and design skills in a creative and challenging way. The nature of game design and storytelling would require clear communication and collaboration in our group, which is an important aspect of this project. And the inherent structure of a game lends well to the use and implementation of the design patterns we will learn this quarter.
 
 ### Languages:
 c++
 ### Tools:
 - Standard c++ library
 - [SFML graphics Library](https://www.sfml-dev.org/index.php)
 

 ### Input:
The interaction with the player will happen in a window in which, depending on what state the game is in, will provide buttons representing actions for the player to use. Depending on what button is pushed the game will execute an action. For example, if the game is in the main menu state there will be a start game button, which will start the game, and a quit game button, which will quit the game.
 
 ### Output:
 The program will output a window which will display different game states. Depending on which state the game is in the window will display different buttons/options. For example, if the game is in the main menu state the window will show the game title and two buttons, a button to start the game, and a button to quit the game.
 
 
 ## Design Patterns:

 ### State - Behavioral
We will use the State pattern to organize different states of our game. For example, the game will start in a main menu state, then once the user pushes the start button, the game will enter the game state and display a different screen with different options, this is where most of the game and user input/output will take place. From that game state, the user can navigate to several other states like back to the main menu or enter an inventory state, etc. This design pattern solves the problem of haveing a bunch of switch cases and if/else statements in our main game class and this pattern makes it easier to change things without messing something up in the rest of the code. Using this pattern we can also easily add more states if we wanted and not have to change multiple areas of code. 

 ### Composite - Structural
We will use the composite pattern to construct a Graphic User Interface using the SFML graphics library. The GUI system will consist of a class interface called UIObject whcih will have the virtual functions: drawTo, Add, Remove, and GetChild. There will be a composite class called UIObjectComposite that groups primitive objects together and displays them, and the primitive objects will be a button class, a text class, a status bar class and a textbox class. The text class outputs text and the textbox class lets the user input text. The problem we expected to encounter was having to create objects constantly when building a good looking game, that could quickly become unorganized and repetative. By using this pattern, we put the GUI in one place and we could draw groups of objects at once rather than one at a time. We could also easly add more types of objects to the GUI without breaking anything.


## Class Diagram

![classDiagram](https://github.com/cs100/final-project-powerrangers/blob/master/CS100_--_UML_7.png)

### Class Diagram Description:
The launcher just contains the main, in main a game object is instantiated. The Game class contains a list of States and calls update and render functions of the current state the game is in in its relative update and render functions. It also determines when to quits the game and when to run the game. The state class is where we implement the State design pattern. We declare an abstract state class with virtual functions: HandleInput, update, and render. Then we curently have two main states, MainMenuState and GameState, where those functions are implemented along with functions specific to each state. The GameState contains an inventory which is a class that stores the amount of items the player has. Both the GameState and MainMenuState instantiate several UIObjects. The UIObject class is where we implemented the Composite Design Pattern. There is the abstract class UIObject, the compoite class UIObjectComposite, and the leaf classes Button, Text, Textbox, StatBar. Each subclass of UIObject implements the drawTo virtual function, with each leaf class haveing their own unique functions they implement. 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
