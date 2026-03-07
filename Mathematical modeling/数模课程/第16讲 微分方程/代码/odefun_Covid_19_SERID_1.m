%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库

function dydt = odefun_Covid_19_SERID_1(t,y)
    lamda = 0.6;%传染强度
    lamda1 = 0.6;%潜伏者的传染强度
    i = 0.125;% 转病率
    r = 0.1; %康复率 
    k = 0.05;%感染者死亡率
    c = 0.05;%转阴率
    dydt = zeros(5,1); % y(1)表示S  y(2)表示I   y(3)表示e   y(4)表示r   y(5)表示d
    dydt(1) = -1*lamda*y(1)*y(2) - lamda1*y(3)*y(1) + c*y(3); 
    dydt(2) = i*y(3) - r*y(2) - k*y(2) ;
    dydt(3) = lamda*y(1)*y(2) +lamda1*y(3)*y(1) - i*y(3) - c*y(3);
    dydt(4) = r*y(2);
    dydt(5) = k*y(2);
end

%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库

