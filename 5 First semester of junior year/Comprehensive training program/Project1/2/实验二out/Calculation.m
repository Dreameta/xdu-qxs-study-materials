function [X,Y,Z] = Calculation(G0,H0,lambada,P,dP,r,seta)
%地心球坐标下的地磁三分量
R=6371200.0;
g=G0;h=H0;
X=0;Y=0;Z=0;
for i=2:14
    for j=1:i
        n=i-1;m=j-1;
        X=X+(R/r)^(n+2)*(g(i,j)*cos(m*lambada)+h(i,j)*sin(m*lambada))*dP(i,j);
        Y=Y+(R/r)^(n+2)*(g(i,j)*sin(m*lambada)-h(i,j)*cos(m*lambada))*m*P(i,j)/sin(seta);
        Z=Z-(n+1)*(R/r)^(n+2)*(g(i,j)*cos(m*lambada)+h(i,j)*sin(m*lambada))*P(i,j);
    end
end












X=0;Y=0;Z=0;
R=6371200.00;
for i=2:14
    for j=1:i
        n=i-1;m=j-1;
      X=X+(R/r)^(n+2)*(G0(i,j)*cos(m*lambada)+H0(i,j)*sin(m*lambada))*dP(i,j);
        Y=Y+(R/r)^(n+2)*(G0(i,j)*sin(m*lambada)-H0(i,j)*cos(m*lambada))*m*P(i,j)/sin(seta);
        Z=Z-(n+1)*(R/r)^(n+2)*(G0(i,j)*cos(m*lambada)+H0(i,j)*sin(m*lambada))*P(i,j);
    end
end

