function out = read_doc(filename)
% function out = read_doc(filename)
% This function reads in an asci file and creates a single long string to
% represent it.  This is useful for generating documentation.
  
fid = fopen(filename);
out = '';
ii=1;
while 1>0
  try
    tline = fgetl(fid);
    if tline<0, return; end
    out = sprintf('%s\n%s', out, tline);
    
    ii=ii+1;
  catch
    return
  end
end
