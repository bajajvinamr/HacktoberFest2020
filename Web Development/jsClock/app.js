const secHand = document.querySelector('.sec');
const minHand = document.querySelector('.min');
const hourHand = document.querySelector('.hour');

const rps = 360 / 60;
let currSecAngle = 90, currMinAngle = 90, currHourAngle = 90;
let seconds = 0, minutes = 0;

function tick() {
    currSecAngle += rps;
    seconds = (seconds + 1) % 60;
    secHand.style.transform = `rotate(${currSecAngle}deg)`;
    if(seconds === 0) {
        currMinAngle += rps;
        minutes = (minutes + 1) % 60;
        minHand.style.transform = `rotate(${currMinAngle}deg)`;
        if(minutes === 0) {
            currHourAngle += rps;
            hourHand.style.transform = `rotate(${currHourAngle}deg)`;
        }
    }
}

setInterval(tick, 1000);