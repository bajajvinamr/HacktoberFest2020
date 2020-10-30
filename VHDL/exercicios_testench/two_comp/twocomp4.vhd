-------------------------------------------------------
--! @file twocomp4.vhd
--! @brief 4-bit 2's Complement
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2018-10-07
-------------------------------------------------------

entity twocomp4 is
  port (
    A : in bit_vector (3 downto 0);
    A2COMP : out bit_vector (3 downto 0)
    );
end entity twocomp4;

architecture twocomp4_arch of twocomp4 is

component adder4 is
  port (
    cin : in bit;
    x : in bit_vector (3 downto 0);
    y : in bit_vector (3 downto 0);
    sum : out bit_vector (3 downto 0);
    cout : out bit
    );
end component adder4;

signal B,B_L : bit_vector (3 downto 0);
  
begin
  UADD : component adder4 port map ('0',B_L,"0001",A2COMP,open);
  B <= A;
  B_L <= not(B);

end architecture twocomp4_arch;
