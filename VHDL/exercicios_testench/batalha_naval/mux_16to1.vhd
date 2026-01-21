-------------------------------------------------------
--! @file mux_16to1.vhd
--! @brief 16 to 1 multiplexer
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-04-01
-------------------------------------------------------

entity mux_16to1 is
  port (
    SEL : in bit_vector (3 downto 0);
    I : in bit_vector (15 downto 0);
    Y : out bit
    );
end entity mux_16to1;

architecture with_select of mux_16to1 is
begin
  with SEL select
    Y <=
    I(0)  when "0000",
    I(1)  when "0001",
    I(2)  when "0010",
    I(3)  when "0011",
    I(4)  when "0100",
    I(5)  when "0101",
    I(6)  when "0110",
    I(7)  when "0111",
    I(8)  when "1000",
    I(9)  when "1001",
    I(10) when "1010",
    I(11) when "1011",
    I(12) when "1100",
    I(13) when "1101",
    I(14) when "1110",
    I(15) when "1111",
    '0'   when others;
end with_select;
