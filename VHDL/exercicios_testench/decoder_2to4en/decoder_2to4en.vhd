------------------------------------------------------------
--! @file decoder_2to4en.vhd
--! @brief 2 to 4 decoder with enable and active low outputs
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-03-29
------------------------------------------------------------

-- The decoder implements a 1-out-of-n encoding circuit

entity decoder_2to4en is
  port (
    EN : in bit;
    A : in bit_vector (1 downto 0);
    Y_L : out bit_vector (3 downto 0)
    );
end entity decoder_2to4en;

architecture dataflow of decoder_2to4en is
begin
  Y_L(3) <= not(EN) or not(A(1)) or not(A(0));
  Y_L(2) <= not(EN) or not(A(1)) or A(0);
  Y_L(1) <= not(EN) or A(1) or not(A(0));
  Y_L(0) <= not(EN) or A(1) or A(0);
end architecture dataflow;

architecture with_select of decoder_2to4en is
  signal y_s : bit_vector (3 downto 0);
begin
  with A select
    y_s <=
    "1110" when "00",
    "1101" when "01",
    "1011" when "10",
    "0111" when "11",    
    "1111" when others;
  Y_L <= y_s when (EN = '1')
         else "1111";
end architecture with_select;

architecture when_else of decoder_2to4en is
  signal y_s : bit_vector (3 downto 0);  
begin
  y_s <=
    "1110" when A = "00" else
    "1101" when A = "01" else
    "1011" when A = "10" else
    "0111" when A = "11" else    
    "1111";
  Y_L <= y_s when (EN = '1')
         else "1111";  
end architecture when_else;



           
                    
