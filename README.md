# SRI-Epidemic-Modelling
 SRI (Susceptible, Recovered, Infected) based epidemic modelling software system to better prepare for such situations in the aftermath of “The Event”. An SRI model consists of modelling the random motion of people who are classified as being either susceptible to infection, recovered from infection, or infected.
In the simulation, non-player characters will randomly move through a two-dimensional area.
Your logic must be placed in the SRISpace namespace.
Initialisation:
• The size of the environment, infection chance, recovery chance, immunity chance and
the initial numbers of each type of character must be specified via the command line
• All characters are initially randomly placed anywhere in the environment
Movement:
• Each character independently moves one step in a random direction (including
diagonals). It is also possible for characters to stay still.
• Characters may not leave the environment
• Characters may not move into each other
Update:
• A susceptible or recovered character has a cumulative chance of becoming infected
for each infected character within a one-square radius of each other (the base chance
is specified on the command line)
• An infected character has a fixed chance of recovering each turn (this chance is
specified on the command line)
o When an infected character recovers, they have a fixed chance of becoming
immune (this chance is specified on the command line)
o If a character recovers but does not become immune, they instead become
recovered
End-simulation:
• The simulation ends when either
o There are no infected characters or
o The user selects to end the simulation
• At the end of the simulation, the system must output the average number of infections
caused by each infected character over the run of the simulation
