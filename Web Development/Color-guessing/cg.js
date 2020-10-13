
var gameStat=true;
var numo=6;


var easy = document.querySelector(".easy");
var square = document.querySelectorAll(".square");

var hard = document.querySelector(".hard");
hard.classList.add("ios");

var colour = generateRandomColour(6);

var pickedColor = math();
var s = colour.indexOf(pickedColor);
var f = colour[s];
var text = document.querySelector(".winner")
var bod = document.querySelector(".text")
var rgb = document.querySelector("h1");
var ng = document.querySelector(".ng");
var pop=document.querySelector(".text")

ng.addEventListener("click",function(){
    



// colour=generateRandomColour(6);
// pickedColor=math();
// s=colour.indexOf(pickedColor);
// f=colour[s];
// rgb.textContent=pickedColor;
// text.style.color="black";
// text.textContent="RESULT";
// text.style.fontSize="30px"
// easy.classList.remove("ios");
// hard.classList.add("ios");
// ng.innerHTML="NEWGAME";
// pop.style.backgroundColor="#4682B5";
// for (i = 0; i < square.length; i++) {
//     if(!gameStat){
//         colour=generateRandomColour(3);
//         if(colour[i]){
//         square[i].style.backgroundColor=colour[i];

//     }else{
//         square[i].style.display="none";
//     }
//     }else{
//     square[i].style.backgroundColor = colour[i];
//     square[i].style.display="block";
//     }
//     square[i].addEventListener("click", function () {
    
//     var clickedColour = this.style.backgroundColor;
//         if (clickedColour == f) {
//             text.innerHTML = "<b>YOU WON</b>";
//             ng.innerHTML="PLAY AGAIN?";
//             text.style.fontSize = "30px";
//             text.style.color = f;
//             bod.style.backgroundColor = f;

//             for (j = 0; j < square.length; j++) {
//                 square[j].style.backgroundColor = f;
                
//             }
//         } else {
//             text.innerHTML = "<b>TRYAGAIN</b>";
//             this.style.backgroundColor = "white";
//         }
        
        
//     });

// }


// });
if(!gameStat){
    colour=generateRandomColour(3);

pickedColor=math();
s=colour.indexOf(pickedColor);
f=colour[s];
rgb.textContent=pickedColor;
text.style.color="black";
text.textContent="RESULT";
text.style.fontSize="30px"
easy.classList.add("ios");
hard.classList.remove("ios");
ng.innerHTML="NEWGAME";
pop.style.backgroundColor="#4682B5";

for(var i=0 ; i<square.length;i++){
    if(colour[i]){
        square[i].style.backgroundColor=colour[i];

    }else{
        square[i].style.display="none";
    }
}
for(i=0;i<3;i++){
 if (clickedColour==f) {
            text.innerHTML = "<b>YOU WON</b>";
            ng.innerHTML="PLAY AGAIN?";
            text.style.fontSize = "30px";
            text.style.color = f;
            bod.style.backgroundColor = f;

            for (j = 0; j < 3; j++) {
                square[j].style.backgroundColor = f;
            }
        } else {
            text.innerHTML = "<b>TRYAGAIN</b>";
            this.style.backgroundColor = "white";
        }
    }
}

else
{
    colour=generateRandomColour(6);
pickedColor=math();
s=colour.indexOf(pickedColor);
f=colour[s];
rgb.textContent=pickedColor;
text.style.color="black";
text.textContent="RESULT";
text.style.fontSize="30px"
easy.classList.remove("ios");
hard.classList.add("ios");
ng.innerHTML="NEWGAME";
pop.style.backgroundColor="#4682B5";
for (i = 0; i < 6; i++) {
    square[i].style.backgroundColor = colour[i];
    square[i].style.display="block";
    square[i].addEventListener("click", function () {
        var clickedColour = this.style.backgroundColor;
        if (clickedColour == f) {
            text.innerHTML = "<b>YOU WON</b>";
            ng.innerHTML="PLAY AGAIN?";
            text.style.fontSize = "30px";
            text.style.color = f;
            bod.style.backgroundColor = f;

            for (j = 0; j < square.length; j++) {
                square[j].style.backgroundColor = f;
                
            }
        } else {
            text.innerHTML = "<b>TRYAGAIN</b>";
            this.style.backgroundColor = "white";
        }
        
        
    });



}
}
});






rgb.textContent = pickedColor;
for (i = 0; i < square.length; i++) {
    square[i].style.backgroundColor = colour[i];
    square[i].addEventListener("click", function () {
        var clickedColour = this.style.backgroundColor;
        if (clickedColour == f) {
            text.innerHTML = "<b>YOU WON</b>";
            ng.innerHTML="PLAY AGAIN?";
            text.style.fontSize = "30px";
            text.style.color = f;
            bod.style.backgroundColor = f;

            for (j = 0; j < square.length; j++) {
                square[j].style.backgroundColor = f;
            }
        } else {
            text.innerHTML = "<b>TRYAGAIN</b>";
            this.style.backgroundColor = "white";
        }
    });

}


function math() {

    var random = Math.floor(Math.random() * colour.length);
    return colour[random];
}


function generateRandomColour(num) {

    var arr = [];
    for (var z = 0; z < num; z++) {
        arr.push(randomColour());
    }
    return arr;
}

function randomColour() {


    var r = Math.floor(Math.random() * 256);
    var g = Math.floor(Math.random() * 256);
    var b = Math.floor(Math.random() * 256);
    return "rgb(" + r + ", " + g + ", " + b + ")";
}


easy.addEventListener("click",function()

{
    gameStat=false;

colour=generateRandomColour(3);

pickedColor=math();
s=colour.indexOf(pickedColor);
f=colour[s];
rgb.textContent=pickedColor;
text.style.color="black";
text.textContent="RESULT";
text.style.fontSize="30px"
easy.classList.add("ios");
hard.classList.remove("ios");
ng.innerHTML="NEWGAME";
pop.style.backgroundColor="#4682B5";

for(var i=0 ; i<square.length;i++){
    if(colour[i]){
        square[i].style.backgroundColor=colour[i];

    }else{
        square[i].style.display="none";
    }
}
for(i=0;i<3;i++){
 if (clickedColour==f) {
            text.innerHTML = "<b>YOU WON</b>";
            ng.innerHTML="PLAY AGAIN?";
            text.style.fontSize = "30px";
            text.style.color = f;
            bod.style.backgroundColor = f;

            for (j = 0; j < 3; j++) {
                square[j].style.backgroundColor = f;
            }
        } else {
            text.innerHTML = "<b>TRYAGAIN</b>";
            this.style.backgroundColor = "white";
        }
    }



});


hard.addEventListener("click",function(){
  gameStat=true;
colour=generateRandomColour(6);
pickedColor=math();
s=colour.indexOf(pickedColor);
f=colour[s];
rgb.textContent=pickedColor;
text.style.color="black";
text.textContent="RESULT";
text.style.fontSize="30px"
easy.classList.remove("ios");
hard.classList.add("ios");
ng.innerHTML="NEWGAME";
pop.style.backgroundColor="#4682B5";
for (i = 0; i < 6; i++) {
    square[i].style.backgroundColor = colour[i];
    square[i].style.display="block";
    square[i].addEventListener("click", function () {
        var clickedColour = this.style.backgroundColor;
        if (clickedColour == f) {
            text.innerHTML = "<b>YOU WON</b>";
            ng.innerHTML="PLAY AGAIN?";
            text.style.fontSize = "30px";
            text.style.color = f;
            bod.style.backgroundColor = f;

            for (j = 0; j < square.length; j++) {
                square[j].style.backgroundColor = f;
                
            }
        } else {
            text.innerHTML = "<b>TRYAGAIN</b>";
            this.style.backgroundColor = "white";
        }
        
        
    });

}


});
