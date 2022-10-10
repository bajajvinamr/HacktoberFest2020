import React from 'react'
import "./topbar.css"
import { HiSearch } from "react-icons/hi";
import { BsFillPersonFill } from "react-icons/bs";
import { BiMessageDots } from "react-icons/bi";
import { IoMdNotifications } from "react-icons/io";



export default function Topbar() {
  return (
    <nav className='navbar'>
      <div className='topbar-Container displayflex'>

        <div className="topbarLeft displayflex verticalcenter">
          <span className="logo">Barbaric</span>
        </div>

        <div className="topbarCenter">
          <div className="searchbar">
            <HiSearch className='classlogo' />
            <input className='searchinput' type='text' placeholder="Search for friend, post  or video..." />
          </div>
        </div>


        <div className="topbarRight displayflex verticalcenter">

        <div className='hometime displayflex spacebetween'>               
          <div className='homepage m-10'><span>HomePage</span></div>
          <div className='timeline m-10'><span>Timeline</span></div>
        </div>

        <div className="topbar-right-logo displayflex spacebetween">
          <div className="personlogo logosize m-10 "><BsFillPersonFill/></div>
          <div className="messagelogo logosize m-10"><BiMessageDots/></div>
          <div className="notificationlogo logosize m-10"><IoMdNotifications/></div>
        </div>

        <div className="ownaccount">
          <div className="account">
            <img src="/assets/person/1.jpeg" alt="" srcset=""className='topbarimg' />
          </div>
        </div>

        </div>
      </div>
    </nav>
  )
}
