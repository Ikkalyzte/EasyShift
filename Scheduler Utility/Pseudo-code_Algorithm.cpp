/*

pointer smallest_available_array_;\
pointer arrays: temporary versions of each person and shift's arrays; (these copies will be what are edited and changed by the program, the origional will allways remain the same)
int minimum_number_of_ppl; (for each shift) [need to be copies, not the origional that is imputed on home screen]
int maximum_number_of_ppl; (for each shift) [need to be copies, not the origional that is imputed on home screen]


Loop 1 
	if shift, in the 'array of all shifts', has an 'array of availible ppl'
	else begin loop 2

		For (shifts that have reached their minimum number of ppl)
			if  size of a shift's 'array of assigned ppl' < size of 'minimum number of ppl int'
				continue
			else restart this for statement with next shift
		end


		for (size of array of all ppl and shifts) 
			if  size of person's 'available shifts array' is smallest and !==0
				person = smallest_available_array
			if  size of shift's 'availible ppl array' is smallest and !==0
				shift = smallest_available_array
		end


		for (selecting which shift/person to assign)
			if  a person's array is smallest_available_array_amt
				get size of all shift arrays that that person is availible for
				choose smallest and !==0
				add that shift to that person's 'array of assigned shifts'
				add that person to that shift's 'array of assigned ppl'
			if  a shift's array is smallest_available_array_amt
				get size of all person arrays that that shift is availible for
				choose smallest and !==0
				add that person to that shifts 'array of assigned ppl'
				add that shift to that person's 'array of assigned shifts'
		end

		for (changing ppl's availibility as they get assigned to shifts)
			if  a slot is filled in a shift's 'array of assigned ppl'
				clear that shift from that person's 'availible shifts array'
				clear that person from that shift's 'availible ppl array'
		end

		for (changing a shift's minimum number of ppl)
			if  a person is added to a shift's 'array of assigned ppl'
				decrease shift's 'minimum number of ppl int' by 1
			if  a shift's 'minimum number of ppl int' == 0
				add shift to 'array of shifts w/ min # of ppl'
				clear shift from 'array of all shifts'
		end

		for (changing a person's 'maximum number of shifts int')
			if	a shift is added to a person's 'array of assigned shifts'
				decrease 'maximum number of shifts int' by 1
			if  'maximum number of shifts int' == 0
				clear that person from each shift's 'array of availible people' that that person is still listed as availible for (use that person's 'array of availible shifts' as pointers to the shifts that he is part of)
				clear 'array of availible shifts'
		end

		for (changing a shift's 'maximum number of ppl int')
			if	a person is added to a shift's 'array of assigned ppl'
				decrease 'maximum number of ppl int' by 1
			if  'maximum number of ppl int' == 0
				clear that shift from each person's 'array of availible shifts' that that shift is still listed as availible for (use that shift's 'array of availible people' as pointers to the people that are part of that shift)
				clear 'array of availible people'
		end

		
end loop

//we have now filled all possible shifts with their minimum number of ppl 
//we will now do the same operation without the clause checking the minimun required ppl

loop 2
	if a shift, in the 'array of shifts w/ min # of ppl' has an 'array of availible ppl'
	else begin loop 3 

		for (size of array of all ppl and shifts) 
			if  size of person's 'available shifts array' is smallest and !==0
				person = smallest_available_array
			if  size of shift's 'availible ppl array' is smallest and !==0
				shift = smallest_available_array
		end


		for (selecting which shift/person to assign)
			if  a person's array is smallest_available_array_amt
				get size of all shift arrays that that person is availible for
				choose smallest and !==0
				add that shift to that person's 'array of assigned shifts'
				add that person to that shift's 'array of assigned ppl'
			if  a shift's array is smallest_available_array_amt
				get size of all person arrays that that shift is availible for
				choose smallest and !==0
				add that person to that shifts 'array of assigned ppl'
				add that shift to that person's 'array of assigned shifts'
		end

		for (changing ppl's availibility as they get assigned to shifts)
			if  a slot is filled in a shift's 'array of assigned ppl'
				clear that shift from that person's 'availible shifts array'
				clear that person from that shift's 'availible ppl array'
		end

		for (changing a person's 'maximum number of shifts int')
			if	a shift is added to a person's 'array of assigned shifts'
				decrease 'maximum number of shifts int' by 1
			if  'maximum number of shifts int' == 0
				clear that person from each shift's 'array of availible people' that that person is still listed as availible for (use that person's 'array of availible shifts' as pointers to the shifts that he is part of)
				clear 'array of availible shifts'
		end

		for (changing a shift's 'maximum number of ppl int')
			if	a person is added to a shift's 'array of assigned ppl'
				decrease 'maximum number of ppl int' by 1
			if  'maximum number of ppl int' == 0
				clear that shift from each person's 'array of availible shifts' that that shift is still listed as availible for (use that shift's 'array of availible people' as pointers to the people that are part of that shift)
				clear 'array of availible people'
		end

end loop

loop 3
	
	for (Shifts that don't have their minimum amt of ppl)
		if  size of shift < minimum number of ppl int
			add all ppl in shift's 'array of assigned ppl' back onto other shift's 'array of availible ppl'
			//do this by using the person pointers to find those ppl then use the permanent 'array of availible shifts' to refil those ppl's temporary 'arrays of availible shifts'
			check availibilities of those ppl against their 'arrays of assigned shifts'
			clear all repeated shifts
			add 1 to each person, on the origional shift's 'array of assinged ppl', 'maximum number of shifts int'
			clear that shift from everyone's 'array of availible shifts'
			clear that shift's 'array of availible ppl'
			begin loop 1
		else begin loop 4
	end
end loop


loop 4

		CASES

end loop
	
	
	
	display results
*/