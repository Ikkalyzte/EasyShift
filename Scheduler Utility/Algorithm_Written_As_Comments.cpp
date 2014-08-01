/* 
1) Inputs

people (names) (jason, we should make this give an error message if someone tries to put the same name as someone else in the system, have it suggest that they add their last name, middle name or any variation of those)
times blocks that they can work
time blocks that work takes place at
maximnum number of people that can work at an activity
minimum number of ppl that can work at an activity
maximum hours that a person is willing to work per day
maximum hours that a person is willing to work per week
*/

/* 2)  Array 1

creats array that plots time blocks vs. people
boolean values-yes that person can work that time block or no that person can't work that time block

counts how many time slots each person is availible for
counts how many people are availible for each time slot

slots people into time slots based on 
-which ppl have the least availible time
-which time slots have the fewest ppl availible to work them

in the event of ties (multiple ppl and time slots have the same number of ppl/times  availible)
execute cases 1-7

1. choose first person in array
2. choose first time in array
3. rotate between ppl and time slots (eg. first tie pick first person, second tie pick first time)
4+. choose second person in array, chose 3rd, choose 4th ect.
5+. choose 2nd time slot, choose 3rd, choose 4th ect.

After a person has been placed in 3 time slots do not place in any more until all other ppl havce been placed in 3 time slots or there are no other options for that time slot

Once a time slot has reached its minimum amount of ppl do not add any more ppl until all other time slots have minimum amount of ppl or there are no other options for those ppl

When a time slot reaches it's maximum number of ppl do not add any more ppl

when a person reaches their maximum amount of hours do not schedual them into any more time slots

When no more ppl can be assigned time slots assign a case number and save results in a second array (results being number of Activitiess filled with minimum number of people)

Run through all variations of all cases

*/

/* 3) Array 2

Array of case number vs number of Activities filled with minimum number of ppl

Pick top ten cases 

re run through all cases until the desired case numbers are found

store those cases

*/

/* 4)  Output

Display case with the most activities filled with the minimum number of people on the calendar

Allow manager to display any of the top ten cases on the calendar

Allow manger to select which case they prefer and finalize that case for everyone to see

*/

/* 5) Extras

Run once a week automatically or as specified by manager

*/






/*  Algorithm Outline



1. creates arrays 
		1. ppl vs Shifts [permanent] (already created by jason for input purposes)
		2. ppl vs Shifts [changes] (used for calculating arrays 3 and 4)
		3. ppl vs # of Shifts availible [Changes] (array for calculatig # of time slots ppl are avilible for)
		4. Shifts vs # of ppl availible for it [Changes] (array for calculating # of ppl availible for each time slot)
		5. Shifts vs ppl [changes](final array of which ppl are going to be assigned to each time slot)
		6. case # vs # of Shifts with minimum # of ppl filled [Permanent] (array for keeping track of which cases worked the best)
		
	NOTE: arrays 3 and 4 are actually lots of arrays, one for each shift and person


2. fills in 1st array with boolean values representing availible and not availible

3. Use 'get size' for each array of "ppl vs shifts availible" and "shifts vs ppl availible"

4. Get smallest integer value.

5. if that integer value corresponds to
		a) the number of shifts that a person can attend
				1. use get size on the shifts that he can attend
				2. get smallest integer value

		b) the number of people able to attend a shift
				1. use get size on the people that can attend
				2. get smallest integer value


6. 'assign a person to a shift' aka change Array 4 to that person attending that shift

7. change array 2 to that person is no longer availible for that shift AND any other shifts taking place at the same time

8. clear arrays 3 and 4

9. get new data for arrays 3 and 4 from new data in array 2

10. loop back to step 3 until no more people are availible for shifts that have avilibilities

11. check # of people in each shift against that shifts minimum required # of people

12. When shifts are found that dont have enough people in them
		a) check which shift has the most people still needed for it
			1. get size of each array
			2. subtract integer number of minimum # of people required for that shift from # of people who are sloted into that shift
			3. get largest integer value (aka the shift with the most people still needed to fill it's minimum)
		b) remouve all of the people from that shift (same way as described above)
		c) clear that shift from array 2
		d) clear corresponding arrays 3 and 4
		d) loop back to step 3

13. display the final assignemts on the main calendar
		a) if cases were needed (they almost certainly will be) allow manager to view the top ten cases and choose which one is best



CASES

Each time that a case is needed the program should make sure to run every possible iteration (eg. always choose 1st person, then loop and always choose second, then loop and always choose third ect, when that finishes do 2 first people then second then third...)

(this will take a REALLY long time. That's why i said only run the program once a week or as otherwise selected by the manager)

To save case numbers have it assign each permutation a number then use that number to track which permutation it used at the end when we want to recreate it.

For step 5:
	For when there's a tie in how many poeple can attend each shift and/or how many shifts each person can attend

1. choose nth person in array (Permutations, YAY!)
2. choose nth shift in array (Permutations AGAIN!)
	a. rotate between ppl and shifts
	b. don't rotate always choose people over shifts
	c. don't rotate alays choose shifts over people


For step 12:
	For when there's a tie in how many more people are needed for a shift

1. choose nth shift (Ugh Permutations again. Tell me we can copy paste this stuff?)


*/

