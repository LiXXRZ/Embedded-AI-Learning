%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库

%% 先试试用符号解
r = 1;d = 0.5; a = 0.1; b = 0.02;
syms x(t) y(t) % 定义符号变量，x(t)和y(t)都是关于t的函数
%微分方程：x'(t) = (r-a*y)*x, y'(t) = -(d-b*x)*y
eq1 = diff(x,t) == (r-a*y)*x;
eq2 = diff(y,t) == -(d-b*x)*y;
eqs = [eq1, eq2];
conds = [x(0) == 25, y(0) == 2];
[xSol(t), ySol(t)] = dsolve(eqs, conds)

%% 用数值解
[t,val]=ode45('odefun1',[0 15],[25 2]);
prey=val(:,1); Predator=val(:,2); 
figure(1)
plot(prey,Predator,'-')% 绘制相轨线
title('捕食者和食饵数量变化的相轨线图')
xlabel('食饵数量');   
ylabel('捕食者数量')

figure(2);
plot(t,prey,'--',t,Predator,'-')
legend('食饵数量','鲨鱼数量')
xlabel('时间');   ylabel('数量')

%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库