function [a,g,e] = LPC_analysis(x,p,h,w)
% [a,g,e] = LPC_analysis(x,p,h,w)  Fit LPC to short-time segments
%    x is a stretch of signal.  Using w point (2*h) windows every 
%    h points (128), fit order p LPC models.  Return the successive 
%    all-pole coefficients as rows of a, the per-frame gains in g 
%    and the residual excitation in e.
% 2001-02-25 dpwe@ee.columbia.edu

if nargin < 2
  p = 12;
end
if nargin < 3
  h = 128;
end
if nargin < 4
  w = 2*h;
end

if (size(x,2) == 1)
  x = x';  % Convert X from column to row
end

npts = length(x);

nhops = floor(npts/h);

% Pad x with zeros so that we can extract complete w-length windows
% from it
x = [zeros(1,(w-h)/2),x,zeros(1,(w-h/2))];

a = zeros(nhops, p+1);
g = zeros(nhops, 1);
e = zeros(1, npts);

% Pre-emphasis
pre = [1 -0.9];
x = filter(pre,1,x);

for hop = 1:nhops

  % Extract segment of signal
  xx = x((hop - 1)*h + [1:w]);
  % Apply hanning window
  wxx = xx .* hanning(w)';
  % Form autocorrelation (calculates *way* too many points)
  rxx = xcorr(wxx,wxx);
  % extract just the points we need (middle p+1 points)
  rxx = rxx(w+[0:p]);
  % Setup the normal equations
  R = toeplitz(rxx(1:p));
  % Solve for a (horribly inefficient to use full inv())
  an = inv(R)*rxx(2:(p+1))';
  % Calculate residual by filtering windowed xx
  %rs = filter([1 -an'],1,wxx);
  aa = [1 -an'];
  rs = filter(aa, 1, xx((w-h)/2 + [1:h]));
  G = sqrt(mean(rs.^2));
  % Save filter, gain and residual
  a(hop,:) = aa;
  g(hop) = G;
  %e((hop - 1)*h + [1:w]) =  e((hop - 1)*h + [1:w]) + rs'/G;
  e((hop - 1)*h + [1:h]) = rs'/G;
  
end
