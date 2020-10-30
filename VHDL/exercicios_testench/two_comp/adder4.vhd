-------------------------------------------------------
--! @file adder4.vhd
--! @brief 4-bit carry lookahead adder
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2018-10-01
-------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all;

entity adder4 is
  port (
        cin     :   in std_logic;
        x       :   in std_logic_vector (3 downto 0);
        y       :   in std_logic_vector (3 downto 0);
        sum     :   out std_logic_vector (3 downto 0);
        cout    :   out std_logic
    );
end entity adder4;

architecture adder4_arch of adder4 is

  signal g0,g1,g2,g3      :   std_logic;
  signal p0,p1,p2,p3      :   std_logic;
  signal c0,c1,c2,c3,c4   :   std_logic;
  signal x0,x1,x2,x3      :   std_logic;
  signal y0,y1,y2,y3      :   std_logic;
  
begin

  x0 <= x(0);
  x1 <= x(1);
  x2 <= x(2);
  x3 <= x(3);
  y0 <= y(0);
  y1 <= y(1);
  y2 <= y(2);
  y3 <= y(3);
  
  g0 <= x0  and  y0;
  p0 <= x0  xor  y0;
  g1 <= x1  and  y1;
  p1 <= x1  xor  y1;
  g2 <= x2  and  y2;
  p2 <= x2  xor  y2;
  g3 <= x3  and  y3;
  p3 <= x3  xor  y3;

  c0 <= cin;
  
  c1 <= g0 or (p0 and c0);
  c2 <= g1 or (p1 and g0) or (p1 and p0 and c0);
  c3 <= g2 or (p2 and g1) or (p2 and p1 and g0) or (p2 and p1 and p0 and c0);
  c4 <= g3 or (p3 and g2) or (p3 and p2 and g1) or (p3 and p2 and p1 and p0 and c0);

  cout <= c4;

  sum(0) <= x0 xor y0 xor c0;
  sum(1) <= x1 xor y1 xor c1;
  sum(2) <= x2 xor y2 xor c2;
  sum(3) <= x3 xor y3 xor c3;

end architecture adder4_arch;