const linearSearch = (numbers, wanted) => {
    for (let number of numbers) 
        if (number == wanted) return 'I found your number';

    return 'We didn\'t find your number';
}

const numbers = [15, 2, 1, 8, 10, 5, 20, 25];
const numberSought = 8;

linearSearch(numbers, numberSought); 