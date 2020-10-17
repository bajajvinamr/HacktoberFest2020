import React, { Component } from 'react'

class Usergreetings extends Component {

    constructor(props) {
        super(props)
    
        this.state = {
             isLoggedIn: true
        }
    }
    
    render() {
        return(
        this.state.isLoggedIn ?
              <div>Welcome Reha</div> :
              <div>Welcome Guest</div>
        )
        
       // let message
       // if(this.state.isLoggedIn){
       //         message= <div>Welcome Reha</div>
       //  }else{
       //         message = <div>Welcome Guest</div>
       // }
       // return <div>{message}</div>
    }
}

export default Usergreetings
