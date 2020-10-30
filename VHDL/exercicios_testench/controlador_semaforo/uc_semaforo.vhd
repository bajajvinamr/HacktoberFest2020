------------------------------------------------------------
--! @file uc_semaforo.vhd
--! @brief Unidade de controle (UC) do controlador de semáforo
--! @brief Zwolinski, M. Digital System Design with VHDL
--! @brief Seção 5.5, p. 101
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-05-13
------------------------------------------------------------

library ieee;
use ieee.numeric_bit.rising_edge;

entity uc_semaforo is
  port (
    RESET : in bit;
    CLOCK : in bit;    
    CAR : in bit;
    TIMED : in bit;
    START_TIMER : out bit;
    MJGREEN : out bit
    );
end entity uc_semaforo;

architecture behavior of uc_semaforo is
  type state_type is (G,R);
  signal present_state, next_state : state_type;
begin

  ESTADO_ATUAL: process (RESET,CLOCK) is
  begin
    if (RESET = '1') then
      present_state <= G;
    elsif (rising_edge(CLOCK)) then
      present_state <= next_state;
    end if;
  end process ESTADO_ATUAL;

-- Bloco função combinatória Próximo Estado (D)

  next_state <=
    G when (present_state = G) and (CAR = '0') else
    R when (present_state = G) and (CAR = '1') else
    R when (present_state = R) and (TIMED = '0') else
    G when (present_state = R) and (TIMED = '1') else
    G;

-- Bloco função combinatória Saída (Z)

  START_TIMER <=
    '0' when present_state = G else
    '1' when present_state = R else
    '0';

  MJGREEN <=
    '1' when present_state = G else
    '0' when present_state = R else
    '1';
  
end architecture behavior;


