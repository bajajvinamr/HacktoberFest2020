------------------------------------------------------------
--! @file ffd.vhd
--! @brief D-Type Flip-Flop
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-06-03
------------------------------------------------------------

library ieee;
use ieee.numeric_bit.rising_edge;

entity ffd is
  port (
    CLOCK : in bit;
    RESET : in bit;
    D : in bit;
    Q, Q_L : out bit
    );
end entity ffd;

architecture behavioral of ffd is
  signal qi : bit;  
begin
  FF: process(CLOCK,RESET)
  begin
    if (RESET = '1') then
      qi <= '0';
    elsif(rising_edge(CLOCK)) then      
      qi <= D;
    end if;
  end process FF;
  Q <= qi;
  Q_L <= not(qi);
end architecture behavioral;



           
                    
