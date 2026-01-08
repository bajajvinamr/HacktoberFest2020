import React from 'react'
import "./rightbar.css"
import {Users} from "../../DummyData"
import Online from '../Online/Online'

export default function Rightbar({user}) {

 

  return (
    <div className='rightbar'>
      <div className="rightwrappertop">
        <img className='giftlogo' src="./assets/gift.png" alt="" srcset="" />
        <span className='rightcommentdiscription'> <b> Pola foster</b> and <b>3 other friends</b> have a birthday today.</span>
      </div>

      <div className="rightwrappercenter">
        <img className='adphoto' src="./assets/ad.png" alt="" srcset="" />
      </div>

      <div className="rightwrapperbottom">
        <div className="heading"><b>Online Friends</b></div>
         <ul className="rightbarfriendlist">
         {Users.map((u) => (
           <Online key={u.id} user={u}/>
             ))}
          </ul> 
           
      </div>


    </div>
  )
}
