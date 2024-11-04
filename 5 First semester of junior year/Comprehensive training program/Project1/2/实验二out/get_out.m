function [F,H,XD,YD,ZD,D,I] = get_out(FAI,lambada,h,G0,H0)
%本函数实现地磁场参数的计算
%输入为：FAI是地理纬度，lambada是地理经度，h是高度,G0,H0是球谐系数
%输出为：F地磁总强度，H地磁水平强度，XD地磁场北向分量，YD地磁场东向分量，ZD地磁场垂直分量，H磁偏角，I磁倾角
[fai,lambada,r,segma] = WGS2GCS(FAI,lambada,h);
[P,dP,seta] = LGD(fai);
[X,Y,Z] = Calculation(G0,H0,lambada,P,dP,r,seta);
[F,H,XD,YD,ZD,D,I] = GCS2WGS(X,Y,Z,segma);
end