%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库

%% SI模型
lamda = 0.1;
syms i(t) 
%微分方程：i'= lamda*i*(1-i)
eq = diff(i,t) == lamda * i * (1-i);
dsolve(eq) %求通解
iSol(t) = dsolve(eq, i(0) == 0.1) %设疫情刚开始有10%人患病
t = [1:100];
i = iSol(t);
plot(t,i,'-');
title('SI模型-患病比例随时间变化图')
xlabel('时间');   
ylabel('患病比例')

%% SIS模型
lamda = 0.1;
%sigma = 2;% 通过调整接触数可改变传染趋势
sigma = 1;
syms i(t) 
%微分方程：i'= lamda*i*(1-1/sigma-i)
eq = diff(i,t) == lamda*i*(1-1/sigma-i);
dsolve(eq) %求通解
iSol(t) = dsolve(eq, i(0) == 0.1) %设疫情刚开始有10%人患病
iSol_1(t) = dsolve(eq, i(0) == 0.6)%设疫情刚开始有60%人患病
t = [1:100];
i = iSol(t);
i_1 = iSol_1(t);
plot(t,i,'-r',t,i_1,'-b');
legend('i0 < 1-1/sigma', 'i0 > 1-1/sigma');
title('SIS模型-患病比例随时间变化图')
xlabel('时间');   
ylabel('患病比例');

%% SIR模型
[t,y] = ode45('odefun_SIR',[0,50],[0.99,0.01]);% s0=0.99，i0=0.01
plot(t,y(:,1),'-g',t,y(:,2),'-r',t, 1-y (:,1)-y(:,2),'-b')
legend('易感染人S', '患者I', '移除者R');
title('SIR模型-SIR三类人所占比例随时间变化图')
xlabel('时间');   
ylabel('比例');
grid on %可以打开背景网格，方便观察，默认关闭

%% 通过SIR模型观察sigma*s0对传染病流行的影响
[t,y] = ode45('odefun_SIR',[0,50],[0.99,0.01]);% s0=0.99，i0=0.01
[t1,y1] = ode45('odefun_SIR',[0,50],[0.70,0.30]);% s0=0.70，i0=0.30
plot(t,y(:,2),'-r',t1,y1(:,2),'-b');
legend('s0=0.99', 's0=0.70');
title('SIR模型-sigma=1.25时不同s0下患病比例随时间变化图')
xlabel('时间');   
ylabel('患病比例');

%% SIRS模型
[t,y] = ode45('odefun_SIRS',[0,50],[0.99,0.01]);% s0=0.99，i0=0.01
plot(t,y(:,1),'-g',t,y(:,2),'-r',t, 1-y (:,1)-y(:,2),'-b')
legend('易感染人S', '患者I', '移除者R');
title('SIRS模型-SIR三类人所占比例随时间变化图')
xlabel('时间');   
ylabel('比例');
grid on;

%% 注意：代码文件仅供参考，一定不要直接用于自己的数模论文中
%% 国赛对于论文的查重要求非常严格，代码雷同也算作抄袭
%% 全套课程购买地址：https://k.youshop10.com/NjNu80mX
%% 全套教材PPT请关注微信公众号：大师兄的知识库