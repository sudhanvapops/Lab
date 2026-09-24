# 2. Implement transmission of ping messages / traceroute over a
# network topology consisting of 6 nodes 
# and find the number of packets dropped due to congestion in the network.

# Initialize the simulator and open trace files
set ns [new Simulator]

set nf [open exp2.nam w]
$ns namtrace-all $nf

set tf [open exp2.tr w]
$ns trace-all $tf


# Create the nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]


# Establish duplex links with bandwidth, delay, and DropTail queuing
$ns duplex-link $n0 $n4 1005Mb 1ms DropTail
$ns duplex-link $n1 $n4 50Mb 1ms DropTail
$ns duplex-link $n2 $n4 2000Mb 1ms DropTail
$ns duplex-link $n3 $n4 200Mb 1ms DropTail
$ns duplex-link $n4 $n5 1Mb 1ms DropTail


# Set queue limits for specific links
$ns queue-limit $n0 $n4 5
$ns queue-limit $n2 $n4 3
$ns queue-limit $n4 $n5 2


# Attach Ping agents to the nodes
set p1 [new Agent/Ping]
$ns attach-agent $n0 $p1
$p1 set packetSize_ 50000
$p1 set interval_ 0.0001

set p2 [new Agent/Ping]
$ns attach-agent $n1 $p2

set p3 [new Agent/Ping]
$ns attach-agent $n2 $p3
$p3 set packetSize_ 30000
$p3 set interval_ 0.00001

set p4 [new Agent/Ping]
$ns attach-agent $n3 $p4

set p5 [new Agent/Ping]
$ns attach-agent $n5 $p5


# Custom function to handle received Ping responses
Agent/Ping instproc recv {from rtt} {
    $self instvar node_
    puts "node[$node_ id] received answer from $from with round trip time $rtt msec"
}


# Connect Ping agents for communication
$ns connect $p1 $p5
$ns connect $p3 $p4


# Finish procedure to end the simulation and close files
proc finish {} {
    global ns nf tf

    $ns flush-trace
    close $nf
    close $tf

    exec nam exp2.nam &
    exit 0
}


# Schedule the sending of Ping packets at different times

# Ping packets from node 0 to node 5
$ns at 0.1 "$p1 send"
$ns at 0.2 "$p1 send"
$ns at 0.3 "$p1 send"
$ns at 0.4 "$p1 send"
$ns at 0.5 "$p1 send"
$ns at 0.6 "$p1 send"
$ns at 0.7 "$p1 send"
$ns at 0.8 "$p1 send"
$ns at 0.9 "$p1 send"
$ns at 1.0 "$p1 send"


# Ping packets from node 2 to node 3
$ns at 0.1 "$p3 send"
$ns at 0.2 "$p3 send"
$ns at 0.3 "$p3 send"
$ns at 0.4 "$p3 send"
$ns at 0.5 "$p3 send"
$ns at 0.6 "$p3 send"
$ns at 0.7 "$p3 send"
$ns at 0.8 "$p3 send"
$ns at 0.9 "$p3 send"
$ns at 1.0 "$p3 send"


# Schedule the simulation to end at 2 seconds
$ns at 2.0 "finish"


# Run the simulation
$ns run