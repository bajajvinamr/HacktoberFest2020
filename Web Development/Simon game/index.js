var gamestart = false;
var level = 0;
$(".level").click(function () {
  //   $(".start").fadeOut();
  //   $(".container").fadeIn();
  if (gamestart == false) {
    nextSequence();
    gamestart = true;
  }
});
$(document).keypress(function () {
  //   $(".start").fadeOut();
  //   $(".container").fadeIn();
  if (gamestart == false) {
    nextSequence();
    gamestart = true;
  }
});

var buttonColors = ["red", "blue", "green", "yellow"];
var gamepattern = [];
var userClickedPattern = [];
var randomChossenColor;
function nextSequence() {
  $(".level").text("LEVEL-" + level);
  level++;
  userClickedPattern = [];
  var randomNumber = Math.floor(Math.random() * 4);
  randomChossenColor = buttonColors[randomNumber];
  gamepattern.push(randomChossenColor);
  $("#" + randomChossenColor)
    .fadeOut(100)
    .fadeIn(100)
    .fadeOut(100)
    .fadeIn(100);
  playSound(randomChossenColor);
}

$(".btn").click(function () {
  var userChossenColor = $(this).attr("id");
  userClickedPattern.push(userChossenColor);
  playSound(userChossenColor);
  animatePress(userChossenColor);
  checkAnswer(userClickedPattern.length - 1);
});
function checkAnswer(currentLevel) {
  if (gamepattern[currentLevel] === userClickedPattern[currentLevel]) {
    if (userClickedPattern.length === gamepattern.length) {
      setTimeout(function () {
        nextSequence();
      }, 1000);
    }
  } else {
    playSound("wrong");
    $(".level").text(
      "Game Over. Press any key or click on the screen to restart."
    );

    startOver();
  }
}
function playSound(name) {
  var audio = new Audio("sounds/" + name + ".mp3");
  audio.play();
}
function animatePress(name) {
  $("#" + name).addClass("pressed");
  setTimeout(function () {
    $("#" + name).removeClass("pressed");
  }, 100);
}
function startOver() {
  level = 0;
  gamepattern = [];
  gamestart = false;
}
