The first assignment for this lab was to create the map of the members by showing their connectings with a hashtable. This hashtable
holds member connections which are used to link two members, and also shows the group that links them. The group is important for the later 
problems as it will be used for the weight of movement between the members. For this first problem we had to go through the groups, and then
loop through all the members of the groups, and add add their member connection. This required a total of 3 loops one for the groups, and then
two in order to compare all the members within each group. this leads to a big O of GK^2.

The next two assignments dealt with searches within the map. The first which was implemented was the breadth first search. This will begin with
a member, and then search all the connecting members until and work its way down the map one level at a time from the first node. The second
search which was implemented was the iterative depth first search. The depth first search will go all the way down a certain path before exploring
the next node attached to the original. This is similar, but the depth of the path is slowly increased as the search goes on. This allows for
the search to be tweaked between depth first and breadth first, but does come at the cost of some time. When running the program the iterative
search was always slower than the breadth first search. This is likely because the depth is set to begin at 0, and so in a way it is acting like
a slower form of breadth first search. With the setup the search is restarted once the final depth is reached, and so whenever a new layer
is moved to the search before must be repeated. Also because it only implements by 1 each time the depth is reached, the search acts similar to breadth
first anyway. However changing the starting depth could alter this and give it an initial depth first search thaat turns into breadth first.

The final problem dealt with implementing primm's algorithm, and creating a minimum spanning tree. This was meant to be completed by finding the 
smallest weighted linked from the member which have been sorted, and then moving along that link. From there new links are made available, and the smallest
from all of the available links is then selected for a new node. This will find the smllest path to and from the original member for all other members.
I attmpted to go through a list of the sorted members, and find the smallest link and then add the new member to the sorted list, but could not manage
the syntax. 
