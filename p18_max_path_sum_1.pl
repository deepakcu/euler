#!/bin/perl


sub maximum {
	my $a = shift;
	my $b = shift;
	if($a > $b) {
		return $a;
	} else {
		return $b;
	}
}

my $filename = "p18.txt";
open(my $fh, '<', $filename) or die "cannot open file";

my @arr;

my $i = 0;
while(my $line = <$fh>) {
	my @row = split ' ', $line;
	push(@arr, \@row);
}

my @max = @arr;

for (my $row = 1; $row < scalar @max; $row++) {
	my @rarr = @{$arr[$row]};
	for (my $col = 0; $col < scalar @rarr; $col++) {		
		if($col !=0) {
			$max[$row][$col] = maximum($max[$row-1][$col]   + $max[$row][$col],
         	                        $max[$row-1][$col-1] + $max[$row][$col]);
		} else {
			$max[$row][$col] = $max[$row-1][$col] + $max[$row][$col];
		}
	}
}

foreach my $row (@max) {
	my @rarr = @{$row};
	foreach my $col (@rarr) {
		print $col.",";
	}
	print "\n";
}


my @rarr = @{$max[scalar @max -1]};
my $maxim = 0;
foreach my $entry (@rarr) {
	if($entry > $maxim) {
		$maxim = $entry;
	}
}

print "Max = $maxim";

close($fh);
