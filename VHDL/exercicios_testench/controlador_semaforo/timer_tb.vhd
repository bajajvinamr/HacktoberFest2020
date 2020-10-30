-------------------------------------------------------
--! @file timer_tb.vhd
--! @brief Testbench para o timer do semáforo
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-05-13
-------------------------------------------------------

--  A testbench has no ports.
entity timer_tb is
end entity timer_tb;

architecture testbench of timer_tb is

  --  Declaration of the component to be tested.  
  component timer
    port (
      RESET : in bit;
      CLOCK : in bit;      
      START_TIMER : in bit;
      TIMED : out bit
      );
  end component timer;
  
  -- Declaration of signals
  signal reset : bit;
  signal clock : bit;
  signal start_timer : bit;
  signal timed : bit;

begin
  -- Component instantiation
  -- DUT = Device Under Test 
  DUT: entity work.timer port map (
    RESET => reset,
    START_TIMER => start_timer,
    CLOCK => clock,
    TIMED => timed
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
      start_timer : bit;
      --  The expected outputs of the circuit.
      timed : bit;
    end record;

    --  The patterns to apply.
    type pattern_array is array (natural range <>) of pattern_type;
    constant patterns : pattern_array :=
      (
        ('1','0','0'),
        ('0','0','0'),
        ('0','1','0'),
        ('0','0','0'),
        ('0','0','1'),
        ('0','0','0'),
        ('0','0','0'));
        
  begin
    --  Check each pattern.
    for k in patterns'range loop

      --  Set the inputs.
      reset <= patterns(k).reset;
      start_timer <= patterns(k).start_timer;      

      --  Wait for the results.
      wait for 1 ns;
      
      --  Check the outputs.
      assert timed = patterns(k).timed
        report "bad TIMED" severity error;

    end loop;
    
    assert false report "end of test" severity note;
    
  --  Wait forever; this will finish the simulation.
    wait;
  end process;
  
end architecture testbench;
  

