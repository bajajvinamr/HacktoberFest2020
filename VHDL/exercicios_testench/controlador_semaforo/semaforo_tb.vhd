-------------------------------------------------------
--! @file semaforo_tb.vhd
--! @brief Testbench para o controlador de semáforo
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-05-13
-------------------------------------------------------

--  A testbench has no ports.
entity semaforo_tb is
end entity semaforo_tb;

architecture testbench of semaforo_tb is

  --  Declaration of the component to be tested.  
  component semaforo
    port(
      RESET : in bit;
      CLOCK : in bit;
      CAR : in bit;
      MAJOR_GREEN : out bit;
      MAJOR_RED : out bit;
      MINOR_GREEN : out bit;
      MINOR_RED : out bit
      );
  end component semaforo;
  
  -- Declaration of signals
  signal reset : bit;
  signal clock : bit;
  signal car : bit;
  signal major_green, major_red : bit;
  signal minor_green, minor_red : bit;

begin
  -- Component instantiation
  -- DUT = Device Under Test 
  DUT: entity work.semaforo port map (
    RESET => reset,
    CLOCK => clock,
    CAR => car,
    MAJOR_GREEN => major_green,
    MAJOR_RED => major_red,
    MINOR_GREEN => minor_green,
    MINOR_RED => minor_red
    );

  -- Clock generator
  clk: process is
  begin
    clock <= '0';
    wait for 0.5 ns;
    clock <= '1';
    wait for 0.5 ns;
  end process clk;  

  --  This process does the real job.
  stimulus_process: process is
    type pattern_type is record
      --  The inputs of the circuit.
      reset : bit;
      car : bit;
      --  The expected outputs of the circuit.
      major_green : bit;
      major_red : bit;
      minor_green : bit;
      minor_red : bit;
    end record;

    --  The patterns to apply.
    type pattern_array is array (natural range <>) of pattern_type;
    constant patterns : pattern_array :=
      (
        ('1','0','1','0','0','1'),
        ('0','0','1','0','0','1'),
        ('0','1','0','1','1','0'),
        ('0','0','0','1','1','0'),
        ('0','0','0','1','1','0'),
        ('0','0','0','1','1','0'),
        ('0','0','1','0','0','1'),
        ('0','0','1','0','0','1'));
        
  begin
    --  Check each pattern.
    for k in patterns'range loop

      --  Set the inputs.
      reset <= patterns(k).reset;
      car <= patterns(k).car;      

      --  Wait for the results.
      wait for 1 ns;
      
      --  Check the outputs.
      assert major_green = patterns(k).major_green
        report "bad Major Green" severity error;

      assert major_red = patterns(k).major_red
        report "bad Major Red" severity error;

      assert minor_green = patterns(k).minor_green
        report "bad Minor Green" severity error;      

      assert minor_red = patterns(k).minor_red
        report "bad Minor Red" severity error;      

    end loop;
    
    assert false report "end of test" severity note;
    
  --  Wait forever; this will finish the simulation.
    wait;
  end process;
  
end architecture testbench;
  

