function [outputArg1,outputArg2] = Drwa_ecef(X,Y,Z,XX,YY,ZZ)
title('卫星轨迹上的磁场矢量图(SPACEBEE-20  )');
xlabel('x坐标')
ylabel('y坐标')
zlabel('z坐标')
grid on;
n = 72;%绘制面的个数为72   
alpha = 1;%球面不透明
%image_file = 'earth.jpg';
image_file = 'World-Winter.bmp';
erad = 6371008.7714; 
prad = 6371008.7714; 
set(gcf,'color','w')
set(gca, 'NextPlot','add', 'Visible','on');
axis equal;%表示设置各坐标轴的单位刻度长度等长显示。
axis auto;%表示根据x，y，z的范围自动确定坐标轴的显示范围。
[x, y, z] = ellipsoid(0, 0, 0, erad, erad, prad, n);
%以三个 (n+1)×(n+1) 矩阵形式返回球面的x、y 和z坐标
globe = surf(x, y, -z, 'FaceColor', 'none', 'EdgeColor', 'w');
cdata = imread(image_file);
set(globe, 'FaceColor', 'texturemap', 'CData', cdata, 'FaceAlpha', alpha, 'EdgeColor', 'none');
m = 200;
n = 30;
view(m,n);
plot3(X,Y,Z,'r','LineWidth',2);
quiver3(X,Y,Z,XX,YY,ZZ,'b');

end