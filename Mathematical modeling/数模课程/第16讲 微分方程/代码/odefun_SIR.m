%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库

function dydt = odefun_SIR(t,y)
    %lamda = 0.6;%传染强度
    %miu = 0.3;%治愈率
    lamda = 0.5;
    miu = 0.4;
    dydt = zeros(2,1); % y(1)表示S  y(2)表示I
    dydt(1) = -1*lamda*y(1)*y(2);
    dydt(2) = lamda*y(1)*y(2)-miu*y(2);   
end

%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库