
% Returns if the single ridge in a bifurcation is 
% the going the same direction as the orientation (res=3)
% or in in the opposite (res=2)

function [res, progress, sx, sy, angle] = test_bifurcation(img, x, y, o, core_x, core_y)

   iax = 0; iay = 0; ibx = 0; iby = 0; icx = 0; icy = 0;
   progress = 1;
   path_len = 4; 

   pax = 0; pay=0; pbx = 0; pby=0; pcx = 0; pcy=0;
   pao = 0; pbo = 0; pco = 0;      %1-8 position of 3x3 square around minutia
   
   for i = 1:8
         [ta, xa, ya] = p(img, x, y, i);
         [tb, xb, yb] = p(img, x, y, i+1);
         if (ta > tb) 
           if pao == 0
              if i < 5
                 pao = 4 + i;
              else
                 pao = mod(4 + i, 9) + 1;
              end
              pax = xa;
              pay = ya;
           else
              if pbo == 0 
                 if i < 5
                    pbo = 4 + i;
                 else
                    pbo = mod(4 + i, 9) + 1;
                 end
                 pbx = xa;
                 pby = ya;
              else
                 if i < 5 
                    pco = 4 + i;
                 else
                    pco = mod(4 + i, 9) + 1;
                 end
                 pcx = xa;
                 pcy = ya;
                 break
              end
           end   
         end
   end

   xaa=0; yaa=0; xbb=0; ybb=0; xcc=0; ycc=0;
   
   hist=[];
   hist(1,:)=[pay, pax];
   hist(2,:)=[pby, pbx];
   hist(3,:)=[pcy, pcx];
   hist(4,:)=[y, x];
   stop=0;
   while ( progress < path_len && ~stop)
      progress = progress + 1;
      da = 0; db = 0; dc = 0;
      if pao ~= 0
          i = 1;

          cn = 0;
          for ii = 1:8
               [t1, x_A, y_A] = p(img, pax, pay, ii);
               [t2, x_B, y_B] = p(img,pax,pay, ii+1);
               cn = cn + abs (t1-t2);
          end
          cn = cn / 2;
 
          if cn == 1 || cn == 3
             stop=1;
          end

          while  i < 9 && da == 0

             [ta, xa, ya] = p(img, pax, pay, i);
             [tz, xz, yz] = p(img, pax, pay, i+1);

             ind_y=find(hist(:,1) == ya);
             ind_x=find(hist(ind_y,2) == xa);
             if numel(ind_x) > 0
                i = i+1;
                continue
             end

             if ta > tz && (xa ~=x || xa~=y)
                pax = xa;
                pay = ya;
                hist(size(hist,1)+1,:)=[pay, pax];
                da = 1;
                xaa = xa;
                yaa = ya;
             end
             i = i+1;
 
          end
          if da == 0 
             break
          end
      end

      if pbo ~= 0 && ~stop

          cn = 0;
          for ii = 1:8
               [t1, x_A, y_A] = p(img,pbx, pby, ii);
               [t2, x_B, y_B] = p(img,pbx, pby, ii+1);
               cn = cn + abs (t1-t2);
          end
          cn = cn / 2;
 
          if cn == 1 || cn == 3
             stop=1;
          end

          i=1;

          while  i < 9 && db == 0
 
             [ta, xa, ya] = p(img, pbx, pby, i);
             [tz, xz, yz] = p(img, pbx, pby, i+1);

             ind_y=find(hist(:,1) == ya);
             ind_x=find(hist(ind_y,2) == xa);
             if numel(ind_x) > 0
                i = i+1;
                continue
             end

             if ta > tz && (xa ~=x || xa~=y)
                pbx = xa;
                pby = ya;
                hist(size(hist,1)+1,:)=[pby, pbx];
                db=1;
                xbb=xa;                                                            
                ybb=ya;                                                            
             end
             i = i+1;
 
          end
      end

      if pco ~= 0 && ~stop

          cn = 0;
          for ii = 1:8
               [t1, x_A, y_A] = p(img,pcx, pcy, ii);
               [t2, x_B, y_B] = p(img, pcx, pcy, ii+1);
               cn = cn + abs (t1-t2);
          end
          cn = cn / 2;
 
          if cn == 1 || cn == 3
             stop=1;
          end


          i = 1;
          while  i < 9 && dc == 0
  
             [ta, xa, ya] = p(img, pcx, pcy, i);
             [tz, xz, yz] = p(img, pcx, pcy, i+1);

             ind_y=find(hist(:,1) == ya);
             ind_x=find(hist(ind_y,2) == xa);
             if numel(ind_x) > 0
                i = i+1;
                continue
             end

             if ta > tz && (xa ~=x || xa~=y)
                pcx = xa;
                pcy = ya;
                hist(size(hist,1)+1,:)=[pcy, pcx];
                dc = 1;
                xcc = xa;                                                            
                ycc = ya;                                                            
             end
             i = i+1;
           end
      end
   end

   d1 = sqrt(dist2([xaa yaa], [xbb ybb]));
   d2 = sqrt(dist2([xaa yaa], [xcc ycc]));
   d3 = sqrt(dist2([xcc ycc], [xbb ybb]));


   if d1 >= d3 &&  d2 >= d3
     sx = xaa;
     sy = yaa;
     ind = pao;
   elseif d1 >= d2 && d3 >= d2
     sx = xbb;
     sy = ybb;
     ind = pbo;
   elseif d3 >= d1 && d2 >= d1   
     sx = xcc;
     sy = ycc;
     ind = pco;
   else
     pause
   end


   d1 = sqrt(dist2([xaa yaa], [core_x core_y]));
   d2 = sqrt(dist2([xbb ybb], [core_x core_y]));
   d3 = sqrt(dist2([xcc ycc], [core_x core_y]));

   qx=0;
   qy=0;
   diff=0;
   if d1 >= d2 &&  d1 >= d3
     qx = xaa;
     qy = yaa;
     ind = pao;
   elseif d2 >= d3 && d2 >= d1
     qx = xbb;
     qy = ybb;
     ind = pbo;
   elseif d3 >= d2 && d3 >= d1
     qx = xcc;
     qy = ycc;
     ind = pco;
   else
     pause
   end


%sy
%sx
%y
%x
%   if core_x == 0
      angle = mod(atan2(y-sy, sx-x), 2*pi);
%      o
      if qx==sx && qy==sy %abs(angle - o) > pi/3
         res = 3;
      else 
         res = 3;
      end
%progress
%pause

%   else
%      if dist2([sy sx], [core_y core_x]) <= dist2([y x], [core_y core_x])
%         res = 2;
%      else 
%         res=3;
%      end 
%   end


