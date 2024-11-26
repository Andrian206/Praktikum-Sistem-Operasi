program CriticalRegion
    var g integer

    sub thread1 as thread
        writeln("In thread1")
        g = 0
        for n = 1 to 20
            g = g + 1
        next
        writeln("thread1 g = ", g)
        writeln("Exiting thread1")
    end sub

    sub thread2 as thread
        writeln("In thread2")
        g = 0
        for n = 1 to 12
            g = g + 1
        next
        writeln("thread2 g = ", g)
        writeln("Exiting thread2")
    end sub

    writeln("In main")

    call thread1
    call thread2

    wait
    
    writeln("Exiting main")
end