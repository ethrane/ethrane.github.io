#! /usr/bin/perl5.30
# ./sort_bib_arc.pl
# DESCRIPTION: Reads in pubs.bib file from your latex CV and outputs
#  pubs_arc.bib---the bib file stripped of all unpublished papers. All
#  shortcut @strings are removed so that the journal name is written out each
#  for each entry to avoid RMS errors. Special characters are removed from
#  author names. Bold face is removed from author names. A list of excluded
#  bib entries is generated in preprints.dat.
# HOW TO RUN: ./sort_bib_arc.pl
# ADDITIONAL INSTRUCTIONS:
#  1. Manage Research Outputs
#  2. Select all; bulk delete permanently (don't worry; nothing is permanent)
#  3. Import bibtex
# Bulk Delete Permanently; don't want temporarily deleted

# define bib file from overleaf
open(input, "pubs.bib");

$i = 0;
while (<input>) {
    # remove collaboration field
    $_ =~ s/collaboration.*//;
    # standardise notes to avoid abbreviations
    $_ =~ s/note.*/note = "none"}/;
    # replace all backslash with # to avoid escape issues
    $_ =~ s/\\/#/g;
    
    # replace all special characters: umlaut
    $_ =~ s/{#"(.)}/\1/g;
    # accent aigu
    $_ =~ s/{#'(.)}/\1/g;
    # slavic l
    $_ =~ s/#l{}/l/g;
    
    # remove bold face from author list
    if ($_ =~ m/^author.*/) {
	$_ =~ s/#textbf{//g;
	$_ =~ s/{#bf//g;
	$_ =~ s/{//g;
	$_ =~ s/}//g;
    }
    # At this point, there should be no more # symbols.
    
    # replace journal entries
    if (m/journal.*/) {
	$_ =~ s/mnrasl/"Mon. Not. R. Ast. Soc. Lett."/;
	$_ =~ s/mnras/"Mon. Not. R. Ast. Soc."/;
	$_ =~ s/aap/"Astron. Astrophys."/;
	$_ =~ s/apjl/"Astrophys. J. Lett."/;
	$_ =~ s/apjs/"Astrophys. J. Supp."/;
	$_ =~ s/apj/"Astrophys. J."/;
	$_ =~ s/cqg/"Class. Quantum Grav."/;
	$_ =~ s/pra/"Phys. Rev. A"/;
	$_ =~ s/prd/"Phys. Rev. D"/;
	$_ =~ s/prx/"Phys. Rev. X"/;
	$_ =~ s/prl/"Phys. Rev. Lett."/g;
	$_ =~ s/prr/"Phys. Rev. Res."/;
	$_ =~ s/pasa/"Pub. Astron. Soc. Aust."/;
    }
    # skip over white space
    if (/^\s*$/) {}
    else {
	# acceptable bibtex entries begin with @
	if ($_ =~ m/\@article.*/ || $_ =~ m/\@inproceedings/) {
	    $i++;
	    $entries[$i] = $_;
	    $bad[$i] = 0;
	}
	# unacceptable bib entries beginning with @
	elsif ($_ =~ m/misc.*/) {
	    $i++;
	    $entries[$i] = $_;
	    $bad[$i] = 1;
	}
	# still part of the same bibtex entry
	else {
	    $entries[$i] = $entries[$i].$_;
	    if ($_ =~ m/.*\"\".*/) {$bad[$i]=1;}
	}
    }
}
close(input);

# count the number of unpublished works
$nbad = 0;
for ($k=1; $k<=$i; $k++) {
    if ($bad[$k]==1) {$nbad++;}
}
print("$i total entries\n");
print("$nbad bad entries\n");

# create extra space between strings and bib entries
#print "\n";

# print non-preprint files
open(out, ">./pubs_arc.bib");
for ($j=1; $j<=$i; $j++) {
    if ($bad[$j]==0) {
	print out $entries[$j]."\n";
    }
}
close(out);

# record preprints excluded from bib
open(preprints, ">./preprints.dat"); 
for ($j=1; $j<=$i; $j++) {
    if ($bad[$j]==1) {
        print preprints $entries[$j]."\n";
    }
}
close(preprints);
