%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库

%
% Copyright (c) 2015, Yarpiz (www.yarpiz.com)
% All rights reserved. Please read the "license.txt" for license terms.
%
% Project Code: YPML110
% Project Title: Implementation of DBSCAN Clustering in MATLAB
% Publisher: Yarpiz (www.yarpiz.com)
% 
% Developer: S. Mostapha Kalami Heris (Member of Yarpiz Team)
% 
% Contact Info: sm.kalami@gmail.com, info@yarpiz.com
%

function PlotClusterinResult(X, IDX)

    k=max(IDX);

    Colors=hsv(k);

    Legends = {};
    for i=0:k
        Xi=X(IDX==i,:);
        if i~=0
            Style = 'x';
            MarkerSize = 8;
            Color = Colors(i,:);
            Legends{end+1} = ['Cluster #' num2str(i)];
        else
            Style = 'o';
            MarkerSize = 6;
            Color = [0 0 0];
            if ~isempty(Xi)
                Legends{end+1} = 'Noise';
            end
        end
        if ~isempty(Xi)
            plot(Xi(:,1),Xi(:,2),Style,'MarkerSize',MarkerSize,'Color',Color);
        end
        hold on;
    end
    hold off;
    axis equal;
    grid on;
    legend(Legends);
    legend('Location', 'NorthEastOutside');

end

%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库