program ThreadTest1
	sub thread1 as thread
		writeln("In thread1")
		while true
		wend
	end sub
	
	sub thread2 as thread
		call thread1
		writeln("In thread2")
		while true
		wend
	end sub
	
	call thread2
	writeln("In main")
	
	do
	loop
end
