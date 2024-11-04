%--------------------------------------------------------------------------
%
% GAST
%
% Purpose:
%   Greenwich Apparent Sidereal Time
%
% Input:
%   Mjd_UT1   Modified Julian Date UT1
%
% Output:
%   gstime    GAST in [rad]
% 
% Last modified:   2015/08/12   M. Mahooti
% 
%--------------------------------------------------------------------------
function gstime = gast (Mjd_UT1)

pi        = 3.14159265358979324;
pi2       = 2.0*pi;              % 2pi

gstime = mod ( gmst(Mjd_UT1) + EqnEquinox(Mjd_UT1), pi2 );

