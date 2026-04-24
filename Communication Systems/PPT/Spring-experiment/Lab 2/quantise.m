function [out, delta] = quantise(input,nlevels,minn,maxx,zero_flag)
    
%%  out = quantize_fcn(input,nlevels,minn,maxx,zero_flag)
%
%  This function quantizes each component of "input" with a uniform scalar
%  quantizer with "nlevels" uniformly spaced output.
%  
%% Input Parameters:
%   input     -- the value(s) to be quantized.  Can be an N-dim array.
%   nlevels   -- number of levels to quantize to
%   minn      -- target minimum of quantizer range
%   maxx      -- target maximum of quantizer range
%   zero_flag = 1 -- forces the quantizer to place a level at zero (optional)
%
%%  If zero_flag ~= 1, the quantizer range is [minn,maxx], the level spacing is 
%
%       delta = (maxx-minn)/nlevels
%
%   and the levels are
%
%       minn+delta/2, minn+3delta/2, ..., minn + (2N-1)/2 delta = maxx-delta/2 
%
%   except that if  nlevels ==1,  then the one level is  (maxx+minn)/2.
% 
%%  If zero_flag = 1, it is assumed that nlevels is even, maxx>0, and minn < 0. 
%   The quantizer is designed to have a level at 0.  So it is asymmetric with
%   one more level on the side corresponding to the larger of maxx and -minn.
%
%   If  maxx > - minn,  the the level spacing, range, and levels are 
%
%      delta = maxx*2/(nlevels+1),   [-maxx + delta, maxx] .
%
%      0, delta, 2 delta, ... , N/2 delta = maxx - delta/2 
%      and   -delta, -2 delta, ... , -(N/2 -1) delta = -maxx + 3/2 delta
%   
%   If  -minn > maxx,  then the level spacing, range, and levels are
%
%      delta = -minn*2/(nlevels+1),   [minn, -minn-delta] . 
%
%     minn-delta/2 = -N/2 delta, (-N/2 +1) delta, ..., -delta, 0,
%     delta, 2 delta, ... , (N/2 - 1) delta = -minn - 3/2 delta
%
%   except that if nlevels = 1, then the one level is at zero
%
%  Values of "input" outside the range are quantized to the closest level 
%  within the range



if ~exist('zero_flag','var') | isempty(zero_flag)
    zero_flag = 0;
end

if zero_flag
    if maxx < 0
        % This scheme won't work for maxx < 0
        error('maxx must be positive with zero_flag=1');
    end
    if minn > 0
        error('minn must be negative with zero-flag=1');
    end
end

if  nlevels == 1
    if zero_flag
        out = zeros(size(input));
    else
        out = zeros(size(input)) + (maxx + minn) /2 ;
    end
else
    if zero_flag  %% quantizer has level at zero, reset minn and maxx
        if maxx > - minn
            delta = maxx * 2 /(nlevels+1) ;
            minn = - (maxx - delta) ;
        else
            delta = - minn * 2 / (nlevels+1) ;
            maxx = - minn - delta ;
        end
    else  %% quantizer does not necessarily have level at zero 
        delta = (maxx-minn)/nlevels ;
    end
    
    bits = ceil(log2(nlevels));

    %find index of quantization cell: 0 to nlevels-1
    index = floor((input - minn)/delta) ;

    % saturate the quantizer to nlevels values of the index
    jkl = find( index >= nlevels) ;
    index(jkl) = (nlevels-1) * ones(size(jkl))  ;
    jkl = find (index < 0) ;
    index(jkl) = 0 * ones(size(jkl)) ;

    % produce the quantizer output
    out = index*delta + delta/2 + minn;
end
