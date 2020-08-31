# DS_AOE
Implement of Activity On Edge (AOE) Network
## Description
This program allows the user to input an AOE network. </br>
Assume activity i is represented by edge <*u*, *v*> and its duration is 𝑎𝑖. The program should
calculate and output the the following: </br>
(a) a table of all events with their *earliest* and *latest times*, </br>
(b) a table of all activities with their *early* and *late times*, the *slack*, and the *criticality*, </br>
(c) the critical network. </br>
## How to Use
### input
The first line contains an integer number *N* (0 < *N* < 100) indicating the number of activities. </br> 
The following *N* lines are the information of activities. Each of these *N* lines consists of four integer numbers, representing the activity index *i* (0 < *i* < 100),
the start vertex of activity *u*, the end vertex of activity *v* (0 ≤ *u*,*v* < 100), and the
duration of activity *𝑎𝑖* (0 < *𝑎𝑖* < 100) respectively. </br>
### output
The output consists of three parts. Each part is separated by an empty line. </br>
(a) Event table: Print out each event’s index *j*, earliest time *ee[j]*, and latest time *le[j]*. </br>
(b) Activity table: Print out each activity’s index *i*, early time *e(i)*, late time *l(i)*, slack *l(i)-e(i)*, and criticality status (if *l(i)-e(i)*==0: Yes; else: No). </br>
(c) Critical network: Print out the index of the activities in the critical network.
