-------------------------------------------------------
--! @file encoder_4to2.vhd
--! @brief 4 to 2 encoder
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-04-01
-------------------------------------------------------

entity encoder_4to2 is
  port (
    A : in bit_vector (3 downto 0);
    Y : out bit_vector (1 downto 0)
    );
end entity encoder_4to2;

architecture with_select of encoder_4to2 is
begin
  with A select
    Y <=
    "00" when "0001",
    "01" when "0010",
    "10" when "0100",
    "11" when "1000",    
    "00" when others; 
end architecture with_select;


           
                    
