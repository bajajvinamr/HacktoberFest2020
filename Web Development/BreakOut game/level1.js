var canvas = document.getElementById("myCanvas");
var won= document.getElementById("won");
var lost= document.getElementById("lost");
var game= document.getElementById("game");
var level2= document.getElementById("level2");
var mobl = document.getElementById("mobleft");
var mobr = document.getElementById("mobright");
var ctx= canvas.getContext("2d");
var x= canvas.width/2;
var y= canvas.height-30;
var dx= 3;
var dy= -3;
var ballRadius = 10;
var paddleHeight = 10;
var paddleWidth = 75;
var paddleX = (canvas.width-paddleWidth) / 2;
var rightPressed = false;
var leftPressed = false;
var brickRowCount = 3;
var brickColumnCount = 5;
var brickWidth = 75;
var brickHeight = 20;
var brickPadding = 10;
var brickOffsetTop = 30;
var brickOffsetLeft = 30;
var score = 0;
var lives=3;

var bricks = [];
for(var c=0; c<brickColumnCount; c++) {
    bricks[c] = [];
    for(var r=0; r<brickRowCount; r++) {
        bricks[c][r] = { x: 0, y: 0, status:1 };
    }
}

document.addEventListener("keydown", keyDownHandler, false);
document.addEventListener("keyup", keyUpHandler, false);
document.addEventListener("mousemove", mouseMoveHandler, false);
mobl.addEventListener("touchstart",lefty);
mobr.addEventListener("touchstart",righty);
mobl.addEventListener("touchend",leftyc);
mobr.addEventListener("touchend",rightyc);
function lefty()
{
  leftPressed=true;
}
function righty()
{
  rightPressed=true; 
}
function leftyc()
{
  leftPressed=false; 
}
function rightyc()
{
  rightPressed=false; 
}

function keyDownHandler(e) {
    if(e.key == "Right" || e.key == "ArrowRight") {
        rightPressed = true;
    }
    else if(e.key == "Left" || e.key == "ArrowLeft") {
        leftPressed = true;
    }
}

function keyUpHandler(e) {
    if(e.key == "Right" || e.key == "ArrowRight") {
        rightPressed = false;
    }
    else if(e.key == "Left" || e.key == "ArrowLeft") {
        leftPressed = false;
    }
}

function mouseMoveHandler(e) {
    var relativeX = e.clientX - canvas.offsetLeft;
    if(relativeX > 0 && relativeX < canvas.width) {
        paddleX = relativeX - paddleWidth/2;
    }
}

function collisionDetection() {
    for(var c=0; c<brickColumnCount; c++) {
        for(var r=0; r<brickRowCount; r++) {
            var b = bricks[c][r];
            if(b.status==1){
            	if( x > b.x && x < b.x+brickWidth && y > b.y && y < b.y+brickHeight) {
                dy = -dy;
                b.status=0;
                score++;
                    if(score == brickRowCount*brickColumnCount) {
                        game.style.display="none";
                        
                        level2.style.display="block";
                        window.cancelAnimationFrame();
                        // let n= window.open("restart.html", 'newwindow');
                        // document.location.reload();
                        
                    }
            }
            }
        }
    }
}

function drawScore() {
    ctx.font = "20px courier";
    ctx.fillStyle = "black";
    ctx.fillText("Score: "+score, 8, 20);
}

function drawLives() {
    ctx.font = "20px courier";
    ctx.fillStyle = "black";
    ctx.fillText("Lives: "+lives, canvas.width-110, 20);
}

function drawBall() {
    ctx.beginPath();
    ctx.arc(x, y, ballRadius, 0, Math.PI * 2);
    ctx.fillStyle = "black";
    ctx.fill();
    ctx.closePath();
}

function drawPaddle() {
    ctx.beginPath();
    ctx.rect(paddleX, canvas.height-paddleHeight-10, paddleWidth, paddleHeight);
    ctx.fillStyle = "black";
    ctx.fill();
    ctx.closePath();

}

function drawBricks() {
    for(var c=0; c<brickColumnCount; c++) {
        for(var r=0; r<brickRowCount; r++) {
        	if(bricks[c][r].status == 1) {
	        	var brickX = (c*(brickWidth+brickPadding))+brickOffsetLeft;
				var brickY = (r*(brickHeight+brickPadding))+brickOffsetTop;
	            bricks[c][r].x = brickX;
	            bricks[c][r].y = brickY;
	            ctx.beginPath();
	            ctx.rect(brickX, brickY, brickWidth, brickHeight);
	            ctx.fillStyle = "grey";
	            ctx.fill();
	            ctx.closePath();
        	}
        }
    }
}

function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    drawBricks();
    drawBall();
    drawPaddle();
    drawScore();
    drawLives();
    collisionDetection();
   
    if(x + dx > canvas.width-ballRadius || x + dx < ballRadius) {
    dx = -dx;
	}

    if(y+dy<ballRadius)
    {
    	dy=-dy;
    }
    else if(y+dy> canvas.height-ballRadius-10){
    if(x > paddleX && x < paddleX + paddleWidth) {
    	if (y = y - paddleHeight) {
                dy = -dy;
            }
            	}
    else {
    	lives--;
if(!lives) {
    game.style.display="none";
    lost.style.display="block";
    window.cancelAnimationFrame();
    
}
else {
    x = canvas.width/2;
    y = canvas.height-30;
    dx = 3;
    dy = -3;
    paddleX = (canvas.width-paddleWidth)/2;
}
}
    }
    

	if(rightPressed && paddleX < canvas.width - paddleWidth/2) {
    paddleX += 7;
		}
	else if(leftPressed && paddleX > paddleWidth/2) {
    paddleX -= 7;
	}

    x += dx;
    y += dy;
    requestAnimationFrame(draw);
}

draw(); 
