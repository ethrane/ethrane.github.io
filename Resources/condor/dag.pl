#! /usr/bin/perl
# E. Thrane

$home = "/archive/home/ethrane";
$sub = "condor";

$LIB = "/archive/home/ethrane/glue_install/lib64/python2.4/site-packages:/ldcg/matlab_r2007a/sys/os/glnxa64:/ldcg/matlab_r2007a/bin/glnxa64:/ldcg/matlab_r2007a/sys/java/jre/glnxa64/jre1.5.0/lib/amd64/native_threads:/ldcg/matlab_r2007a/sys/java/jre/glnxa64/jre1.5.0/lib/amd64/server:/ldcg/matlab_r2007a/sys/java/jre/glnxa64/jre1.5.0/lib/amd64:/ldcg/matlab_r2007a/sys/opengl/lib/glnxa64:/opt/lscsoft/lalstochastic/lib64:/opt/lscsoft/glue/lib64/python2.4/site-packages:/opt/lscsoft/libframe/lib64:/opt/lscsoft/libmetaio/lib64:/opt/lscsoft/ldas-tools/lib64:/opt/lscsoft/dol/lib64:/opt/lscsoft/root/lib64:/opt/ldg-4.8/tclglobus/lib:/opt/ldg-4.8/apache/lib:/opt/ldg-4.8/myodbc/lib:/opt/ldg-4.8/unixodbc/lib:/opt/ldg-4.8/glite/lib64:/opt/ldg-4.8/glite/lib:/opt/ldg-4.8/jdk1.5/jre/lib/i386:/opt/ldg-4.8/jdk1.5/jre/lib/i386/server:/opt/ldg-4.8/jdk1.5/jre/lib/i386/client:/opt/ldg-4.8/mysql5/lib/mysql:/opt/ldg-4.8/berkeley-db/lib:/opt/ldg-4.8/expat/lib:/opt/ldg-4.8/globus/lib:/opt/ldg-4.8/globus/lib:/ligotools/lib";

open(dag,">./eric.dag");
for ($i=0; $i<=10; $i=$i+1) {
    print dag "JOB $i /archive/home/ethrane/sub/$sub.sub\n";
    print dag "VARS $i ";
    print dag "jobNumber=\"$i\" ";
    print dag "ld_library_path=\"$LIB\"";
    print dag "\n\n";
}
print dag "PARENT 0 CHILD ";
for ($j=1; $j<$i; $j=$j+1) {print dag "$j ";}
print dag "\n";
close(dag);
