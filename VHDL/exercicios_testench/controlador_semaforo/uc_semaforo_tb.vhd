-------------------------------------------------------
--! @file uc_semaforo_tb.vhd
--! @brief Testbench para a UC do semáforo
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-05-13
-------------------------------------------------------

--  A testbench has no ports.
entity uc_semaforo_tb is
end entity uc_semaforo_tb;

architecture testbench of uc_semaforo_tb is

  --  Declaration of the component to be tested.  
  component uc_semaforo
    port (
      RESET : in bit;
      CLOCK : in bit;      
      CAR : in bit;
      TIMED : in bit;
      START_TIMER : out bit;
      MJGREEN : out bit
      );
  end component uc_semaforo;
  
  -- Declaration of signals
  signal reset : bit;
  signal clock : bit;  
  signal start_timer : bit;  
  signal car : bit;
  signal timed : bit;
  signal major_green : bit;

begin
  -- Component instantiation
  -- DUT = Device Under Test 
  DUT: entity work.uc_semaforo port map (
    RESET => reset,
    CLOCK => clock,
    CAR => car,
    TIMED => timed,
    START_TIMER => start_timer,
    MGREEN => major_green
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
      timed : bit;
      --  The expected outputs of the circuit.
      start_timer : bit;
      major_green : bit;
    end record;

    --  The patterns to apply.
    type pattern_array is array (natural range <>) of pattern_type;
    constant patterns : pattern_array :=
      (
        ('1','0','0','0','1'),
        ('0','0','0','0','1'),
        ('0','1','0','1','0'),
        ('0','0','0','1','0'),
        ('0','0','0','1','0'),        
        ('0','0','1','0','1'),
        ('0','0','0','0','1'));
    
  begin
    --  Check each pattern.
    for k in patterns'range loop

      --  Set the inputs.
      reset <= patterns(k).reset;
      car <= patterns(k).car;
      timed <= patterns(k).timed;      

      --  Wait for the results.
      wait for 1 ns;
      
      --  Check the outputs.
      assert start_timer = patterns(k).start_timer
        report "bad START_TIMER" severity error;

      assert major_green = patterns(k).major_green
        report "bad MAJOR_GREEN" severity error;
    
    end loop;
    
    assert false report "end of test" severity note;
    
  --  Wait forever; this will finish the simulation.
    wait;
  end process;
  
end architecture testbench;
  

