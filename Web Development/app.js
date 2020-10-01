var button= document.querySelector('.submit');
var inputValue = document.querySelector('.inputValue')
var city =document.querySelector('.city')
var des =document.querySelector('.des')
var temp =document.querySelector('.temp')


button.addEventListener('click',function(){

    fetch(`https://api.openweathermap.org/data/2.5/weather?q=${inputValue.value}&appid=8008395fa13dd591e66311d8b2ee20df`)
    .then(response => response.json())
    .then(data => {
var namevalue=data['name'];
var tempValue= data['main']['temp']-273;
var desValue= data['weather'][0]['description'];

city.innerHTML=namevalue;
temp.innerHTML=`${tempValue} °F`;
des.innerHTML=desValue;
    }
    )


.catch(err =>alert("wrong city name"))
});
