const moonPath="M17.5 29C17.5 44.1878 27.5 55 27.5 55C12.3122 55 0 42.6878 0 27.5C0 12.3122 12.3122 0 27.5 0C27.5 0 17.5 13.8122 17.5 29Z";

const sunPath="M55 27.5C55 42.6878 42.6878 55 27.5 55C12.3122 55 0 42.6878 0 27.5C0 12.3122 12.3122 0 27.5 0C42.6878 0 55 12.3122 55 27.5Z";

const darkMode = document.querySelector("#darkMode");


var toggle =false;



darkMode.addEventListener('click',()=>{

const timeline = anime.timeline({
    duration: 750,
    easing: "easeOutExpo"

});
timeline.add({
    targets: ".sun",
    d:[
        {value:toggle?sunPath:moonPath}
    ]
})
.add({
    targets:"#darkMode",
    rotate:toggle?0:320

},'-=350')
.add({
    targets:"section",
    backgroundColor: toggle ?"rgb(199,199,199)" :"rgb(22,22,22)"
},'-=700')
.add({
    targets:".head",
    color:toggle?"rgb(22,22,22)":"rgb(199,199,199)"
},'-=700');

if(!toggle){
    toggle=true;
}else{
    toggle=false;
}


});