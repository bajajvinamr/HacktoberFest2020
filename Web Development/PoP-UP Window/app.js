var parent = document.querySelector(".modal-parent"),
 btn  = document.querySelector("button"),
 X= document.querySelector(".X");
section = document.querySelector("section");

 btn.addEventListener("click",function(){

    parent.style.display = "block";
    section.style.filter= "blur(6px)";

 });


 X.addEventListener("click",function(){
  parent.style.display ="none";

  section.style.filter= "blur(0px)";
 });

 parent.addEventListener("click",function(e){
 if(e.target.className === "modal-parent"){
    parent.style.display ="none";

    section.style.filter= "blur(0px)";
 }
 });