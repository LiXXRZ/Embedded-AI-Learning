function [snr, Y, Yq, Sr] = QUAN_demo(R, stg)
% The OUTPUTS are:
% snr: The signal-to-noise ratio of quantatization
% Y  : The original speech/audio data in the file 
% Yq : The quantized data (integer values, not bits)
% Sr : The sample rate
%
% The INPUTS are:
% R  : The number of bits for the creation of L = 2^R quantization levels
% stg: The input WAV filename

disp('Quantizing. Please wait...');
% Read the speech file data
[Y, Sr]= audioread(stg);
% Calculate the number of Quantization Levels
L = 2^R;
% Maximum and minimum sample values
max_val = max(Y);
min_val = min(Y);
% Range of sample values
get_range = max_val - min_val;
% Compute the quantization step
q_step = get_range / L;
% Calcuate the values of the quantization levels
q_levels = min_val + (q_step/2) + (0:q_step:(get_range-q_step/2));
% Intiate the quantization
Yq = zeros(1, length(Y))';
for i=1:length(Y)
    distance        = abs(Y(i)-q_levels);
    idx_of_min_dist = find(distance == min(distance), 1);
    Yq(i)           = q_levels(idx_of_min_dist);
end
% Print a message to screen
fprintf('Quantized with R = %d bits or L = %d levels\n', R, L);
% Compute the SNR 
snr = sum(abs(Y).^2)/sum(abs(Y-Yq).^2);
end