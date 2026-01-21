-------------------------------------------------------
--! @file decoder_3to8_tb.vhd
--! @brief Testbench for 3-to-8 decoder
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-03-28
-------------------------------------------------------

entity decoder_3to8_tb is
end entity decoder_3to8_tb;

architecture testbench of decoder_3to8_tb is

--  Declaration of the component that will be instantiated.  
  component decoder_3to8
  port (
    A : in bit_vector (2 downto 0);
    Y : out bit_vector (7 downto 0)
    );
  end component decoder_3to8;

  signal a : bit_vector(2 downto 0);
  signal y : bit_vector(7 downto 0);
  
begin
  --  Component instantiation.
  DUT: entity work.decoder_3to8 (dataflow) port map (
    A => a,
    Y => y
    );

  --  This process does the real job.
  stimulus_process: process is
    type pattern_type is record
      --  The inputs of the circuit.
      a : bit_vector (2 downto 0);
      
      --  The expected outputs of the circuit.
      y : bit_vector (7 downto 0);
    end record;

    --  The patterns to apply.
    type pattern_array is array (natural range <>) of pattern_type;
    constant patterns : pattern_array :=
      (
        ("000","00000001"),
        ("001","00000010"),
        ("010","00000100"),
        ("011","00001000"),
        ("100","00010000"),
        ("101","00100000"),
        ("110","01000000"),
        ("111","10000000")
        );
    
  begin
    for k in patterns'range loop

      --  Set the inputs.
      a <= patterns(k).a;
      
       --  Wait for the results.
      wait for 1 ns;
      
  --  Check the outputs.

      assert y = patterns(k).y        
        report "bad y" severity error;

    end loop;
    
    assert false report "end of test" severity note;
    
  --  Wait forever; this will finish the simulation.
    wait;
  end process;
  
end architecture testbench;
  

