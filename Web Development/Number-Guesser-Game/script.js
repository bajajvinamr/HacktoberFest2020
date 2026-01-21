let humanScore = 0;
let computerScore = 0;
let currentRoundNumber = 1;


//Creating a random number between 1 - 9
const generateTarget = () => {
    return Math.floor(Math.random() * 9 + 1);
};

//Creating guess function for human - computer - target guess
const compareGuesses = (human , computer, target) => {
    check(human);
    const userGuess = Math.abs(target - human);
    const computerGuess = Math.abs(target - computer);
    return userGuess <= computerGuess;
};

//Updating score regarding the winner
const updateScore = (winner) => {
    if (winner === 'human') {
        return humanScore += 1;
    } else {
        return computerScore += 1;
    }
};

//Advance round function that will be updating round's number
const advanceRound = () => {
    currentRoundNumber += 1;
};

//Alert the user for valid input
function check(human) {
    if(human < 0 || human > 9) {
        alert('Enter a number between 0 and 9')
    }
};

