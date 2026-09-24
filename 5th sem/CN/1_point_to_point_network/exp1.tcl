# Initialize simulator and open trace files
set ns [new Simulator]
$ns use-newtrace

set tf [open abc.tr w]
$ns trace-all $tf

set nf [open exp1.nam w]
$ns namtrace-all $nf


# Create network nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]


# Color the packets
$ns color 1 "red"
$ns color 2 "blue"

$n0 label "Source/udp0"
$n1 label "Source/udp1"
$n2 label "Router"
$n3 label "Destination/Null"


# Set up links with bandwidth, delay, and drop-tail
$ns duplex-link $n0 $n2 100Mb 300ms DropTail
$ns duplex-link $n1 $n2 10Mb 300ms DropTail
$ns duplex-link $n2 $n3 1Mb 300ms DropTail


# Set queue limits
$ns queue-limit $n0 $n2 50
$ns queue-limit $n1 $n2 50
$ns queue-limit $n2 $n3 50


# Attach UDP agents and applications
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1

set null3 [new Agent/Null]
$ns attach-agent $n3 $null3


set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0

set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1


# Set class for packet coloring
$udp0 set class_ 1
$udp1 set class_ 2
# $udp0 set fid_ 1
# $udp1 set fid_ 2

# Connect the agents
$ns connect $udp0 $null3
$ns connect $udp1 $null3


# Set packet size and interval (data rate)
$cbr0 set packetSize_ 500
$cbr1 set packetSize_ 500
$cbr1 set interval_ 0.005


# Finish procedure to close simulation
proc finish {} {
    global ns nf tf

    $ns flush-trace

    exec nam exp1.nam &

    close $tf
    close $nf

    exit 0
}


# Start the traffic
$ns at 0.1 "$cbr0 start"
$ns at 0.3 "$cbr1 start"


# End simulation after 10 seconds
$ns at 10.0 "finish"


# Run the simulation
$ns run