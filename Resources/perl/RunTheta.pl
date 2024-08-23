#! /usr/bin/perl

foreach $EMU (0.2, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 6
    .5, 7.0, 7.5) {
    $emu=$EMU;
    print ($emu,": ");
    $enu = $emu+0.5;
    if ($emu==0.2) {$enu=0.5;}
    if ($emu==int($emu)) {$emu = $emu.".0"}
    $dat = "./tmp/".$emu.".dat";
    system "rm -f $dat";
    while ($enu <= 8) {
        print ($enu," ");
        $outfile = "./tmp/".$emu."-".$enu.".m";
        open(output, ">>$outfile");
        open(template, "./theta.m");
        while (<template>) {
            s/prob.\../prob$emu/;
            s/mpow=.\../mpow=$emu/;
            s/npower=.\../npower=$enu/;
            print output $_;
        } #writing new .m file
        close(template);
        close(output);
        open(dat, ">>$dat");
        print dat ($enu," ");
        system "./math.sh $outfile | ./math.pl >> $dat";
        system "rm -f $outfile";
        $enu += 0.5;
    } #enu loop
    print "\n";
} #EMU loop
