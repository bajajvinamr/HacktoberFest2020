-------------------------------------------------------
--! @file semaforo.vhd
--! @brief Controlador de Semáforo
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-05-13
-------------------------------------------------------

entity semaforo is
  port( 
    RESET : in bit;
    CLOCK : in bit;
    CAR : in bit;
    MAJOR_GREEN : out bit;
    MAJOR_RED : out bit;
    MINOR_GREEN : out bit;
    MINOR_RED : out bit
    );
end entity semaforo;

architecture dataflow of semaforo is

  component fd_semaforo is
    port (
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
  end component fd_semaforo;

  component uc_semaforo is
    port (
      RESET : in bit;
      CLOCK : in bit;
      CAR : in bit;
      TIMED : in bit;
      START_TIMER : out bit;
      MJGREEN : out bit
      );
  end component uc_semaforo;

  signal start_timer : bit;
  signal timed : bit;  
  signal mjgreen : bit;
  
begin

  FD: entity work.fd_semaforo port map (
    RESET => RESET,
    CLOCK => CLOCK,
    START_TIMER => start_timer, 
    MJGREEN => mjgreen,
    TIMED => timed,
    MAJOR_GREEN => MAJOR_GREEN,
    MAJOR_RED => MAJOR_RED,
    MINOR_GREEN => MINOR_GREEN,
    MINOR_RED => MINOR_RED
    );

  UC: entity work.uc_semaforo port map (
    RESET => RESET,
    CLOCK => CLOCK,    
    CAR => CAR,
    TIMED => timed,
    START_TIMER => start_timer,
    MJGREEN => mjgreen
    );

end architecture dataflow;
  

