import React from 'react'

export default function Online({user}) {
  return (
    <div className='onlineprofile'>
      
          <li className="rightbarfriend">
            <div className="rightbarprofilecontainer">
              <img 
              src={user.profilePicture}
              className='profilelogosize'
              alt="" 
              srcset="" />
              <span className="greendot"></span>
            </div>
          <span className='onlineprofilename'>{user.username}</span>
          </li>
          


    </div>
  )
}
