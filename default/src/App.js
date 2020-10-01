import React from 'react';
//import logo from './logo.svg';
import './App.css';
//import Greet from './components/Greet'
//import Welcome from './components/Welcome'
//import Hello from './components/Hello'
//import Counter from './components/Counter'
//import Eventbind from './components/EventBind'
//import ParentComponent from './components/ParentComponent'
import Usergreetings from './components/Usergreetings'
import Namelist from './components/Namelist'
function App() {
  return (
    <div className="App">
     { /*<Greet name='Reha' color='blue'/>
      <Greet name='Sonia'color='yellow'/>
      <Greet name='Sugeetha' color='pink'/>
      <Counter></Counter>
      <Eventbind></Eventbind>
      <ParentComponent></ParentComponent>*/ } 
      <Usergreetings></Usergreetings>
      <Namelist></Namelist>
    </div>
  );
}

export default App;
