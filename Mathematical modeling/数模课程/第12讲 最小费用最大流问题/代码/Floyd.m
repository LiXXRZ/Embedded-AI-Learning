%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库

function [path, dis] = Floyd(gra)
    n = size(gra);
    dis = gra;
    path = zeros(n);
    for k  = 1 : n %这是跳板节点
        for i = 1 : n
            for j = 1 :n
                if (dis(i,k) + dis(k,j) < dis(i,j)) % 通过跳板发现了更短的路径，更新最短路径
                    dis(i,j) = dis(i,k) + dis(k,j);
                    path(i,j) = k;
                end
        end
    end
end

%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库
