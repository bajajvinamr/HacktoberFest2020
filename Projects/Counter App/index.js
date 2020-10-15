const inputArea = document.getElementsByClassName("inputArea")[0];
const countDisplay = document.getElementsByClassName("counter")[0];
const countButton = document.getElementsByClassName("count-button")[0];
const resetButton = document.getElementsByClassName("reset-button")[0];
const wordButton = document.getElementsByClassName("word-button")[0];
let counter = 0;
let darkMode = false;
resetButton.addEventListener("click",()=>{
    inputArea.value = "";
    counter = 0;
    countDisplay.innerHTML = "0";
})
countButton.addEventListener("click",()=>{
    const characterCount = inputArea.value.length;
    if(characterCount === 0){
        countDisplay.innerHTML = `Zero characters input`
    }else{
        countDisplay.innerHTML = `${characterCount} ${characterCount > 1 ? "Characters" : "Character"}`;
    }
})
wordButton.addEventListener("click",()=>{
    const wordCount = inputArea.value.trim().split(" ").length;
    if(inputArea.value.trim().split("").length === 0){
        countDisplay.innerHTML = `Zero words input`
    }else{
        countDisplay.innerHTML = `${wordCount} ${wordCount > 1 ? "Words" : "Word"}`
    }
})
