clear ;
close all;
t=decyear(2022,10,1);
[G0,H0]=Get_GM();
i=1;j=1;
for latitude=-80:0.5:80
    for longtitude=-180:0.5:180        
        [F(latitude*2+161,longtitude*2+361),H,XD,YD,ZD,D,I]=get_out(latitude,longtitude,500e3,G0,H0);
    end
end
latitude=-80:0.5:80;
longtitude=-180:0.5:180;   

figure(1)
%全球地磁总强度二维分布图
pcolor(longtitude,latitude,F);  %绘制云图
shading interp                  %色彩平滑
colorbar                        %分布柱图
title('全球地磁总强度二维分布图')
xlabel('经度')
ylabel('纬度')

figure(2)
%全球地磁总强度三维分布图
mesh(longtitude,latitude,F)
title(" 全球地磁总强度三维分布图")
xlabel('经度');
ylabel('纬度');
zlabel('地磁场强度');

figure(3)
%全球等强度地磁图
[C,H]=contour(longtitude,latitude,F);
title("等强度地磁图")
clabel(C,H);
xlabel('经度');
ylabel('纬度');

figure(4)
%带有地图的全球等强度地磁图
a=zeros(length([-180:0.5:180]),length([-80:0.5:80]));
longi=([-180:0.5:180]+180).*8640/360;
lati=([80:-0.5:-80]+80).*4320/160;
im=imread('biga.jpg');
imshow(im,[]);
hold on;
title('全球等强地磁图')
hold on 
[C,H]=contour(longi,lati,F);
clabel(C,H,'Color','w');
