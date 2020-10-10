//jshint esversion:6

const app = function(){
    const song = document.querySelector(".song");
    const play = document.querySelector(".play");
    const outline= document.querySelector(".moving-outline circle");
    const video = document.querySelector(".vid-container video");
   
    //sounds
    const sounds = document.querySelectorAll(".sound-picker button");
    //time which is displayed below play button
    const timeDisplay = document.querySelector('.time-display');
    const timeselect= document.querySelectorAll(".time-select button");
    //get the length of the outline to make the circle
    const outlineLength= outline.getTotalLength();
    //Durations
    let fakeDuration = 600;
    outline.style.strokeDasharray = outlineLength;
    outline.style.strokeDashoffset = outlineLength;

//pick differnt modes basically sounds
sounds.forEach(sound =>{
    sound.addEventListener("click",function(){
        song.src = this.getAttribute("data-sound");
        video.src= this.getAttribute("data-video");
      checkPlaying(song);

    });
});


    //play sound 
    play.addEventListener("click",function(){
        checkPlaying(song);
       
      });
      //select sound
    timeselect.forEach(option =>{
        option.addEventListener("click",function(){
            fakeDuration = this.getAttribute("data-time");
            timeDisplay.textContent =`${Math.floor(fakeDuration/60)}:${Math.floor(fakeDuration%60)}`;
        });
    });

// here i've learned new making anonymous function by ()=> look below 
    const checkPlaying = song => {
        if(song.paused){
            song.play();
            video.play();
            play.src = "svg/pause.svg";
        }
        else{
            song.pause();
            video.pause();
            play.src= "svg/play.svg";
        }
    };
//we can animate the circle
song.ontimeupdate = ()=>{
    let currentTime = song.currentTime;
    let elapsed = fakeDuration- currentTime;
    let seconds  =  Math.floor(elapsed%60);
    let minutes= Math.floor(elapsed/60);


//Animate the circle
let progress = outlineLength - (currentTime / fakeDuration)*outlineLength;
outline.style.strokeDashoffset= progress;
//animate  the text
timeDisplay.textContent = `${minutes}:${seconds}`;
//if the time currently becomes greater than specified time then clock counts neg. to prevent that we used this
if(currentTime >= fakeDuration){
song.pause();
song.currentTime= 0;
play.src= "./svg/play.svg";
video.pause();
}
};
};


app();