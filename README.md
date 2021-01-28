 # Space Adventure
 
 Authors: 
 - [Dana Savin](https://github.com/danams101)
 - [Kevin Ni](https://github.com/Keeevini)
 - [Fengchun Fan](https://github.com/FengchunFan)
 

## Project Description

Our project is a Console based Role Playing Game.
 
This project is interesting to us because it would allow us the opportunity to test our coding and design skills in a creative and challenging way. The nature of game design and storytelling would require clear communication and collaboration in our group, which is an important aspect of this project. And the inherent structure of a game lends well to the use and implementation of the design patterns we will learn this quarter.
 
 ### Languages:
 c++
 ### tools:
 Standard c++ library
 

 ### Input:
 Console Input
 
 ### Output:
 Console text in ASCII and colors
 
 
 ## Design Pattern 1:
 ### Abstract Factory - Creation

There are multiple problems we will anticipate in order to solve with the abstract factory design pattern. One of them will be cross platform console graphics. In order to output color onto the console, it is different between windows and linux. Additionally, they also need to be compiled differently. Thus, an abstract factory can be used to separate the instances between OS for the UI. Additionally, we will have a massive tree of classes revolving around the same type, such as entities. We will need to have an abstract factory in order to minimize the linkage between header files to create a certain type of entity.

 ## Design Pattern 2:
 ### State - Behavioral
We picked this because as we are making a game, we will need the game to load different behavior depending on where you are in the game. For example, a menu should be very different from a battle. Additionally, only one state can be loaded at a time, thus allowing us to use the state design pattern. The problem we anticipate encountering is our tick function. We do not need all the states to tick at the same time since during the menu, the “game state” should be paused. Thus, ticking all of the states at once will be a massive waste of resources. Thus, we will use the state design pattern to switch out the behavior of our “Game” instance.

 ## Design Pattern 3:
 ### Composite - Structural
We will have many classes that require updating their logic and also rendering. Thus, this will require many classes to call the same tick() and render() function depending on the branch/state they are in. Thus, we will be using a composite pattern to direct the chain of command for the tick() and render() functions. Additionally, we will need to use the composite pattern to structure our entities classes tree, since they will be sharing similar data types.




 
 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
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
 
