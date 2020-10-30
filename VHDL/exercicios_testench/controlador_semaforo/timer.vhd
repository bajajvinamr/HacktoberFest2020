------------------------------------------------------------
--! @file timer.vhd
--! @brief Timer para o controlador do semáforo
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-05-13
------------------------------------------------------------

library ieee;
use ieee.numeric_bit.rising_edge;

entity timer is
  port (
    RESET : in bit;
    CLOCK : in bit;
    START_TIMER : in bit;
    TIMED : out bit
    );
end entity timer;

architecture behavioral of timer is
  type state_type is (A,B,C,D);
  signal present_state, next_state : state_type;
begin

  ESTADO_ATUAL: process (RESET,CLOCK) is
  begin
    if (RESET = '1') then
      present_state <= A;
    elsif (rising_edge(CLOCK)) then
      present_state <= next_state;
    end if;
  end process ESTADO_ATUAL;


-- Bloco função combinatória Próximo Estado (D)

  next_state <=
    A when (present_state = A) and (START_TIMER = '0') else
    B when (present_state = A) and (START_TIMER = '1') else
    C when (present_state = B) else
    D when (present_state = C) else
    A when (present_state = D) else    
    A;

-- Bloco função combinatória Saída (Z)

  TIMED <=
    '0' when present_state = A else
    '0' when present_state = B else
    '0' when present_state = C else
    '1' when present_state = D else    
    '0';
  
  
end architecture behavioral;
