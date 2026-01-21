Library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all;

entity adder4_tb is
end entity;

architecture testb of adder4_tb is

    component adder4 is
    port(
            cin     :   in std_logic;
            x       :   in std_logic_vector (3 downto 0);
            y       :   in std_logic_vector (3 downto 0);
            sum     :   out std_logic_vector (3 downto 0);
            cout    :   out std_logic
        );
    end component;

    signal a_in, b_in, s_out : std_logic_vector (3 downto 0);
    signal c_out : std_logic;

begin

    DUT: adder4 port map(
            cin => '0', 
            x => a_in, 
            y => b_in, 
            sum => s_out, 
            cout => c_out
        );

    process
    begin
        a_in <= "0000";
        b_in <= "0000";
        wait for 1 ns;
        assert(c_out & s_out = "00000") report "0+0 Falhou" severity error;

        a_in <= "0001";
        b_in <= "0001";
        wait for 1 ns;
        assert(c_out & s_out = "00010") report "1+1 Falhou" severity error;

        a_in <= "1000";
        b_in <= "1000";
        wait for 1 ns;
        assert(c_out & s_out = "10000") report "8+8 Falhou" severity error;

        a_in <= "1111";
        b_in <= "0001";
        wait for 1 ns;
        assert(c_out & s_out = "10000") report "F+1 Falhou" severity error;

        a_in <= "1110";
        b_in <= "0111";
        wait for 1 ns;
        assert(c_out & s_out = "10101") report "E+7 Falhou" severity error;

        a_in <= "0111";
        b_in <= "0011";
        wait for 1 ns;
        assert(c_out & s_out = "11010") report "7+3 Falhou" severity error;

        a_in <= "1100";
        b_in <= "0101";
        wait for 1 ns;
        assert(c_out & s_out = "10001") report "C+5 Falhou" severity error;

        a_in <= "0000";
        b_in <= "0000";

        assert false report "FIM DO TESTE." severity note;
        wait;
    end process;
end testb;