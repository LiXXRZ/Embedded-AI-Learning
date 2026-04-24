function d = LPC_synthesis(a,g,e,h)
% d = LPC_synthesis(a,g,e,h)   Resynthesize from LPC representation
%    Each row of a is an LPC fit to a h-point (non-overlapping) 
%    frame of data.  g gives the overall gains for each frame and 
%    e is an excitation signal (if e is empty, white noise is used; 
%    if e is a scalar, a pulse train is used with that period).
%    Return d as the resulting LPC resynthesis.
% 2001-02-25 dpwe@ee.columbia.edu

if nargin < 3
  e = [];
end
if nargin < 4
  h = 128;
end

[nhops,p] = size(a);

npts = nhops*h;

if length(e) == 0
  e = randn(1,npts);
elseif length(e) == 1
  pd = e;
  e = sqrt(pd) * (rem(1:npts,pd) == 0);
else
  npts = length(e);
end

d = 0*e;

for hop = 1:nhops
  
  hbase = (hop-1)*h;
  
%  oldbit = d(hbase + [1:h]);
  aa = a(hop,:);
  G = g(hop);
  newbit = G*filter(1, aa, e(hbase + [1:h]));
%  d(hbase + [1:w]) = [oldbit, zeros(1,(w-h))] + (hanning(w)'.*newbit);
  d(hbase + [1:h]) = newbit;

end

% De-emphasis (must match pre-emphasis in lpcfit)
pre = [1 -0.9];
d = filter(1,pre,d);
