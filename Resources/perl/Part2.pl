#! /usr/bin/perl
#opendir(DIR, "./tmp");
#@list = readdir(DIR);
#closedir(DIR);
#foreach $file (@list) {
foreach $input (<./tmp/*.dat>) {
    open(input, "$input");
    print ($input,"\n");
    $output = $file.".p2";
    open(output, ">>$output");
    $j = 0;
    while(<input>) {
        @array = split (/ /,$_);
        chomp($array[1]);
        if($j==0) {print output ($array[0]," ",$array[1],"\n");}
        else {print output ($array[0]," ",$array[1]-$last,"\n");}
        $last = $array[1];
        $j++;
    } # while(<input>)
} #foreach $file
