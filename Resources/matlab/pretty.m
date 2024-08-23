% E. Thrane
% makes plots look pretty
function pretty()
  h_xlabel = get(gca,'XLabel');
  set(h_xlabel,'FontSize',20);
  h_ylabel = get(gca,'YLabel');
  set(h_ylabel,'FontSize',20);
  h_zlabel = get(gca,'ZLabel');
  set(h_zlabel,'FontSize',20);
  set(gca,'FontSize',20);
return
