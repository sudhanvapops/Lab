BEGIN {
}
{
if($6=="cwnd_") {
printf("%f\t%f\n",$1,$7);
}
}END{}

# plot "a1" with lines title "TCP Vegas", "a2" with lines title "TCP Reno"