function [G0,H0]=Get_GM()
[~,~,C]=xlsread('IGRF13coeffs');
[p,~]=size(C);
for i=1:p
temp1=C(i,1);
temp1=temp1{1};
temp2=C(i,2);
temp2=temp2{1}; 
temp3=C(i,3);
temp3=temp3{1};
temp4=C(i,end-1);
temp4=temp4{1}; 
if(strcmp(temp1,'g'))
G0(temp2+1,temp3+1)=temp4;
end
if(strcmp(temp1,'h'))
H0(temp2+1,temp3+1)=temp4;
end 
end
