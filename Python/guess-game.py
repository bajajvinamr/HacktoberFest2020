from random import randint

computador = randint(0, 10)
print('Sou seu computador... Pensei em um número entro 0 e 10')
print('Será que você consegue adivinhar?')
acertou = False
palpites = 0
while not acertou:
    jogador = int(input('Qual é o seu palpite? '))
    palpites += 1
    if jogador == computador:
        acertou = True
    else:
        if jogador < computador:
            print('Mais... tente mais uma vez')
        else:
            print('Menos... tente mais uma vez')
print('Você acertou com {} tentativas!! PARABÉNS'.format(palpites))
