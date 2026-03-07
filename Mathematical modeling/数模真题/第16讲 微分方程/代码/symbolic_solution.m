%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库

%% 用MATLAB求解微分方程符号解
syms y(x) % 定义符号变量，告诉MATLABy(x)是关于x的函数
%微分方程：y-y'=2x
eq = y - diff(y,x) == 2*x; %diff(y,x)表示dy/dx，即y'，表示y对x的一阶导数
dsolve(eq) %求通解
dsolve(eq, y(0) == 3) %求特解
%%
syms y(x)
%微分方程：y'' + 4y' +29y = 0
eq = diff(y,x,2) + 4*diff(y,x) + 29*y == 0;
Dy = diff(y,x); %因为我们要用到y'(0)=0这个初值，为了方便我们这里先记录一下
conds = [y(0) == 0, Dy(0)==1] %你可以试试如果用diff(y,x)(0) == 1会怎么样
ySol(x) = dsolve(eq, conds)

%%
syms x(t) y(t) % 定义符号变量，x(t)和y(t)都是关于t的函数
%微分方程：x'(t) = y, y'(t) = -x
eq1 = diff(x,t) == y;
eq2 = diff(y,t) == -x;
eqs = [eq1, eq2];
conds = [x(0) == 0, y(0) == 1];
[xSol(t), ySol(t)] = dsolve(eqs, conds)

%% 导弹追击问题
syms y(x)
eq = 2*x*diff(y,x,2) == sqrt(1 + diff(y,x)^2)
Dy = diff(y,x);
conds = [y(16) == 0, Dy(16) == 0];
ySol(x) = dsolve(eq, conds)

%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库
