-------------------------------------------------------
--! @file detector_glingon.vhd
--! @brief Detecta transmissão em Glingon
--! @brief Máquina de Estado no Modelo Moore
--! @author Edson Midorikawa (emidorik@usp.br)
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-06-03
-------------------------------------------------------
library ieee;
use ieee.numeric_bit.rising_edge;

entity detector_glingon is
  port (
    CLOCK : in bit;
    RESET : in bit;
    STX   : in bit;
    SIN   : in bit;
    SOUT  : out bit_vector(1 downto 0);
    ACK   : out bit
    );
end entity detector_glingon;

architecture fsm of detector_glingon is
  type estado_t is (I,K,UM,Z,W);
  signal EA,PE : estado_t;
begin

  sincrono: process(clock, reset)
  begin
    if (reset='1') then
      EA <= I;
    elsif (rising_edge(clock)) then
      EA <= PE;
    end if;
  end process sincrono;
  
  PE <=
    I  when EA=I  and STX='0' else
    K  when EA=I  and STX='1' and SIN='0' else
    UM when EA=I  and STX='1' and SIN='1' else
    K  when EA=K  and SIN='0' else
    UM when EA=K  and SIN='1' else
    Z  when EA=UM and SIN='0' else
    W  when EA=UM and SIN='1' else
    K  when EA=Z  and SIN='0' else
    UM when EA=Z  and SIN='1' else
    K  when EA=W  and SIN='0' else
    UM when EA=W  and SIN='1' else
    I;

  ACK <=
    '0' when EA=I or EA=UM else
    '1' when EA=K or EA=Z or EA=W else
    '0';

  SOUT <=
    "00" when EA=K else
    "01" when EA=Z else
    "10" when EA=W else
    "11" when EA=I or EA=UM else
    "11";

end architecture fsm;

architecture dataflow of detector_glingon is
  component ffd
    port (
      CLOCK : in bit;
      RESET : in bit;
      D : in bit;
      Q, Q_L : out bit
      );
  end component ffd;
  
  signal pe2,pe1,pe0 : bit;
  signal ea2,ea1,ea0 : bit;
  signal ea2_l,ea1_l,ea0_l : bit;
  signal sout1,sout0 : bit;
  
begin
-- Flip-Flops  
  FF2: entity work.ffd port map (CLOCK,RESET,pe2,ea2,ea2_l);
  FF1: entity work.ffd port map (CLOCK,RESET,pe1,ea1,ea1_l);
  FF0: entity work.ffd port map (CLOCK,RESET,pe0,ea0,ea0_l);  

-- Função Próximo Estado
  pe2 <= (SIN and ea1 and ea0_l) or
         (ea2 and ea1 and ea0_l) or
         (ea2 and sin and ea1_l) or
         (stx and sin and ea1_l and ea0_l);
  pe1 <= (ea2_l and ea1 and ea0_l) or
         (ea2 and ea1_l) or
         (stx and ea1_l and ea0_l);
  pe0 <= ea2 and sin and ea1 and ea0_l;

-- Saídas
  sout1 <= ea0 or
           (ea2_l and ea1_l) or
           (ea2 and ea1);
  sout0 <= (ea2_l and ea1_l) or
           (ea2 and ea1) or
           (ea1_l and ea0_l) or
           (ea1 and ea0);
  SOUT <= sout1 & sout0;
  ACK <= (ea2 and ea1_l) or (ea2_l and ea1 and ea0_l);
  
end architecture dataflow;

