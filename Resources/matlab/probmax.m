function prob = probmax(maxsnr, T)
% prob = probmax(maxsnr, T)
%   T is the number of trials, maxsnr is the measured max SNR
%   prob = is the false alarm probability of SNR given T (assuming that only
%   POSITIVE SNR is evidence of an outlier)
% Small prob is evidence of an outlier.
% Assumes that the underlying distribution for SNR is normal with unit
% variance.

% domain of utility: maxsnr is between -R and R
R = 6;
if maxsnr<-R || maxsnr>R
  error('maxsnr out of range');
end

% specify precision
da = 0.0001;

% define probability density function for maximum of a T samples drawn from a 
% normal distribution with zero mean and unit variance
mpdf =@(a) normcdf(a).^(T-1) .* normpdf(a,0,1) ;

% create an array of SNR's
aa = -R:da:R;

% round maxsnr to the nearest array value
idx = find( abs(aa-maxsnr) == min(abs(aa-maxsnr)) );

% calculate probability: note that the normalization by sum(mpdf(aa)) is 
% important to get an accurate result
prob = 1 - sum(mpdf(aa(1:idx)))/sum(mpdf(aa));

end
