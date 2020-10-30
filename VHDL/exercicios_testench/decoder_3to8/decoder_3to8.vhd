-------------------------------------------------------
--! @file decoder_3to8.vhd
--! @brief 3 to 8 decoder
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-03-28
-------------------------------------------------------

-- The decoder implements a 1-out-of-n encoding circuit

entity decoder_3to8 is
  port (
    A : in bit_vector (2 downto 0);
    Y : out bit_vector (7 downto 0)
    );
end entity decoder_3to8;

architecture dataflow of decoder_3to8 is
begin
  Y(7) <= A(2) and A(1) and A(0);
  Y(6) <= A(2) and A(1) and (not(A(0)));
  Y(5) <= A(2) and (not(A(1))) and A(0);
  Y(4) <= A(2) and (not(A(1)) and (not(A(0))));
  Y(3) <= not(A(2)) and A(1) and A(0);
  Y(2) <= not(A(2)) and A(1) and (not(A(0)));
  Y(1) <= not(A(2)) and (not(A(1))) and A(0);
  Y(0) <= not(A(2)) and (not(A(1)) and (not(A(0))));  
end architecture dataflow;

architecture with_select of decoder_3to8 is
begin
  with A select
    Y <=
    "00000001" when "000",
    "00000010" when "001",
    "00000100" when "010",
    "00001000" when "011",    
    "00010000" when "100",
    "00100000" when "101",
    "01000000" when "110",
    "10000000" when "111",
    "00000000" when others; 
end architecture with_select;

architecture when_else of decoder_3to8 is
begin
  Y <=
    "00000001" when A = "000" else
    "00000010" when A = "001" else
    "00000100" when A = "010" else
    "00001000" when A = "011" else    
    "00010000" when A = "100" else
    "00100000" when A = "101" else
    "01000000" when A = "110" else
    "10000000" when A = "111" else 
    "00000000";
end architecture when_else;

           
                    
