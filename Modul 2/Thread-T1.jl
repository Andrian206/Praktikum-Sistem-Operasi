program ThreadTest2
	var s1 string(4)
	var s2 string(8)
	
	sub thread1 as thread
		s1 = "Fuad"
	 	writeln("Raja Jawa")
	 	while true
	 	wend
	 end sub
	 
	 sub thread2 as thread
	 	call thread1
	 	s2 = "Donpollo"
	 	writeln("Raja Sigma")
	 	while true
	 	wend
	 end sub
	 
	 call thread2
	 writeln("Raja Mewing")
	 wait
	 
	 writeln(s1)
	 writeln(s2)
end
