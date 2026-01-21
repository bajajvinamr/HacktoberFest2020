-------------------------------------------------------
--! @file fd_semaforo.vhd
--! @brief Fluxo de Dados (FD) do controlador de semáforo
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-05-13
-------------------------------------------------------

--  A testbench has no ports.
entity fd_semaforo is
  port( 
    RESET : in bit;
    CLOCK : in bit;
    START_TIMER : in bit;
    MJGREEN : in bit;
    TIMED : out bit;
    MAJOR_GREEN : out bit;
    MAJOR_RED : out bit;
    MINOR_GREEN : out bit;
    MINOR_RED : out bit
    );
end entity fd_semaforo;

architecture dataflow of fd_semaforo is

  component timer
    port (
      RESET : in bit;
      CLOCK : in bit;      
      START_TIMER : in bit;      
      TIMED : out bit      
      );
  end component timer;

  signal magreen : bit;
  
begin
  TEMPORIZADOR: entity work.timer port map (
    RESET => RESET,
    CLOCK => CLOCK,    
    START_TIMER => START_TIMER, 
    TIMED => TIMED
    );  

  magreen <= MJGREEN;  
  MAJOR_GREEN <= magreen;
  MAJOR_RED <= not(magreen);
  MINOR_GREEN <= not(magreen);
  MINOR_RED <= magreen;
  
end architecture dataflow;
  

