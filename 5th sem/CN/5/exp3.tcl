# Implement an Ethernet LAN using n nodes, set multiple traffic nodes, and plot the congestion window for different source/destination pairs.

# Create simulator
set ns [new Simulator]

# Open trace files
set nf [open prog3.nam w]
$ns namtrace-all $nf

set nd [open prog3.tr w]
$ns trace-all $nd

# Colors
$ns color 1 Blue
$ns color 2 Red


# Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]


# Configure destination nodes
$n7 shape box
$n7 color Blue

$n8 shape hexagon
$n8 color Red


# Point-to-point links
$ns duplex-link $n1 $n0 2Mb 10ms DropTail
$ns duplex-link $n2 $n0 2Mb 10ms DropTail
$ns duplex-link $n0 $n3 1Mb 20ms DropTail


# Ethernet LAN
$ns make-lan "$n3 $n4 $n5 $n6 $n7 $n8" 512Kb 40ms LL Queue/DropTail Mac/802_3


# Link orientation for NAM
$ns duplex-link-op $n1 $n0 orient right-down
$ns duplex-link-op $n2 $n0 orient right-up
$ns duplex-link-op $n0 $n3 orient right


# Queue limit
$ns queue-limit $n0 $n3 20


# TCP 1 - TCP Vegas
set tcp1 [new Agent/TCP/Vegas]
$ns attach-agent $n1 $tcp1

set sink1 [new Agent/TCPSink]
$ns attach-agent $n7 $sink1

$ns connect $tcp1 $sink1

$tcp1 set class_ 1
$tcp1 set packetSize_ 55


# FTP application 1
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1


# Congestion window trace 1
set tfile [open cwnd.tr w]
$tcp1 attach $tfile
$tcp1 trace cwnd_


# TCP 2 - TCP Reno
set tcp2 [new Agent/TCP/Reno]
$ns attach-agent $n2 $tcp2

set sink2 [new Agent/TCPSink]
$ns attach-agent $n8 $sink2

$ns connect $tcp2 $sink2

$tcp2 set class_ 2
$tcp2 set packetSize_ 55


# FTP application 2
set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2


# Congestion window trace 2
set tfile2 [open cwnd2.tr w]
$tcp2 attach $tfile2
$tcp2 trace cwnd_

# Finish procedure
proc finish {} {
    global ns nf nd tfile tfile2

    $ns flush-trace

    close $nf
    close $nd
    close $tfile
    close $tfile2

    exec nam prog3.nam &
    exit 0
}


# Start / Stop traffic

$ns at 0.5 "$ftp1 start"
$ns at 1.0 "$ftp2 start"

$ns at 5.0 "$ftp1 stop"
$ns at 5.0 "$ftp2 stop"

$ns at 5.5 "finish"


# Run simulation
$ns run