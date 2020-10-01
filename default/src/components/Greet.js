import React from 'react';

//function Greet(){
  //  return <h1>Hello Reha!</h1>
//}
const Greet =(props) =>
{
    console.log(props)
return <h1>Favourite color of {props.name} is {props.color}</h1>
}
export default Greet