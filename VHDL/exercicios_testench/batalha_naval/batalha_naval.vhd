-------------------------------------------------------
--! @file batalha_naval.vhd
--! @brief PCS3115 - Prova de recuperação 2018
--! @author Edson S. Gomi (gomi@usp.br)
--! @date 2020-04-01
-------------------------------------------------------
 
entity batalha_naval is
  port (
    T   : in bit_vector(15 downto 0);   -- Player 1
    C,L : in bit_vector(3 downto 0);    -- Player 2
    S   : out bit   -- Speaker "chuá" (erro) or "bum" (acerto)
    );
end entity batalha_naval;

architecture dataflow of batalha_naval is

  --  Multiplexer 16-to-1.  
  component mux_16to1
    port (
      SEL : in bit_vector (3 downto 0);
      I : in bit_vector (15 downto 0);
      Y : out bit
      );
  end component mux_16to1;

  -- Encoder 4-to-2
  component encoder_4to2
    port (
      A : in bit_vector (3 downto 0);
      Y : out bit_vector (1 downto 0)
      );
  end component encoder_4to2;

  signal sel1,sel0 : bit_vector(1 downto 0);
  signal sel : bit_vector(3 downto 0);
    
begin
  -- Components instantiation
  MUX: entity work.mux_16to1(with_select) port map (
    SEL => sel,
    I => T,
    Y => S
    );

  ENC0: entity work.encoder_4to2(with_select) port map (
    A => C ,
    Y => sel1
    );

  ENC1: entity work.encoder_4to2(with_select) port map (
    A => L,
    Y => sel0
    );

  -- Signals
  
sel <= sel1 & sel0;  
  
end architecture dataflow;

