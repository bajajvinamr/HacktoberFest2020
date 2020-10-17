import React from 'react'

const Hello = () =>{
    //return(

   // <h1>Hello Rehaa!</h1>
   // )
   return React.createElement('div',
   {id:'hello',className:'Dummy'}
   ,React.createElement('h1',null,'Heyya its me Reha'))
}
export default Hello